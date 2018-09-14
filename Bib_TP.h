#ifndef _Bib_TP_H_
#define	_Bib_TP_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include "conio2.h"
#include "conio.h"
#include "Bib_LLC_BIBLIO.h"
#include "Bib_Standare.h"
#include "Bib_Graphique.h"
void LireLivre(maillon_Livre**Livre){

    /// LIRE DANS FICHIER LIVRE ET SAUVERGERDER DANS LISTE LIVRE

    FILE *F=fopen("Fiche livre.txt","r");
    maillon_Livre *P=NULL,*Q=NULL;
    *Livre=NULL;
    int i,j;
    char ch[10000];
    while (fgets(ch,10000,F)!=NULL){
       allouer_Livre(&P);
       if (*Livre==NULL) *Livre=P;
        else aff_adr_Livre(Q,P);
       sscanf(ch,"%d %s %s %d/%d/%d %s",&(P->cote),P->titre,P->auteur,&(P->dateEdition.days),&(P->dateEdition.month),&(P->dateEdition.years),P->editeur);
       RamplcerCracrter(P->auteur,'_',' ');
       RamplcerCracrter(P->editeur,'_',' ');
       RamplcerCracrter(P->titre,'_',' ');
       P->disponible=1;
       P->Emprunt=NULL;
       P->nbrDeEmprunt=0;
       i=0;
       while(ch[i]!='(') i++;
       j=0;
       i++;
       while(ch[i]!=')') P->motCle[j++]=ch[i++];
       P->motCle[j]=0;
       i++;
       while(ch[i]!='#') i++;
        j=0;
        i++;
       while(ch[i]!='#') P->resume[j++]=ch[i++];
       P->resume[j]=0;
       Q=P;
    }
    if (P!=NULL) aff_adr_Livre(P,NULL);
    fclose(F);
}
void LireEmprunteur(maillon_Emprunteur**Emprunteur){

    /// LIRE DANS FICHIER LIVRE ET SAUVERGERDER DANS LISTE LIVRE

    FILE *F=fopen("Fiche Emprunteur.txt","r");
    maillon_Emprunteur *P=NULL,*Q=NULL;
    *Emprunteur=NULL;
    int i,j;
    char ch[2000];
    while (fgets(ch,2000,F)!=NULL){
       allouer_Emprunteur(&P);
       if (*Emprunteur==NULL) *Emprunteur=P;
        else aff_adr_Emprunteur(Q,P);
       sscanf(ch,"%s %s %s %s %d %d/%d/%d",P->nom,P->prenom,P->adresseActuelle,P->nDeTelephone,&(P->ordreInscription),&(P->dateDeInscription.days),&(P->dateDeInscription.month),&(P->dateDeInscription.years));
       RamplcerCracrter(P->adresseActuelle,'_',' ');
       RamplcerCracrter(P->nom,'_',' ');
       RamplcerCracrter(P->prenom,'_',' ');
       P->Emprunt=NULL;
       P->Emprunter=0;
       P->NbreDeEmprunt=0;
       P->penaliterTotal=0;
       P->penaliter=0;
       Q=P;
       }

    if (P!=NULL) aff_adr_Emprunteur(P,NULL);
    fclose(F);
}
void Chargement(maillon_Emprunt**Emprunt,maillon_Livre**Livre,maillon_Emprunteur**Emprunteur){

    /// CHARGER TOUS LES INFORMATION QUI STOUQUER DANS LES FICHIER ET LE SAUVERGERDER DANS DES LISTE

     FILE *F1;
     time_t tk;
     struct tm *TimeActeul;
     time(&tk); /// ON LIT LE DATE DE PC
     TimeActeul=localtime(&tk); /// ON LES CONVERTIRE
     int Years=TimeActeul->tm_year+1900,Days=TimeActeul->tm_mday,Month=TimeActeul->tm_mon+1;
    F1=fopen("Fiche Emprunt.txt","r");
    LireEmprunteur(Emprunteur);
    LireLivre(Livre);
    maillon_Emprunt *P=NULL,*Q=NULL;
    maillon_Livre *L=NULL;
    maillon_Emprunteur *E=NULL;
    *Emprunt=NULL;
    int i,j,cote,ordre,pin=0,d,m,y;
    char ch1[500];
    while(fgets(ch1,500,F1)!=NULL){
        allouer_Emprunteur(&P);
        if (*Emprunt==NULL) *Emprunt=P;
            else aff_adr_Emprunt(Q,P);
        sscanf(ch1,"%d %d %d/%d/%d %d/%d/%d %d %d",&cote,&ordre,&(P->dateDeEmprunt.days),&(P->dateDeEmprunt.month),&(P->dateDeEmprunt.years),&(P->dateDeRetour.days),&(P->dateDeRetour.month),&(P->dateDeRetour.years),&(P->livreRendu),&(P->penaliter));
        i=RechachezUnCote_Livre(*Livre,cote);y=P->dateDeRetour.years;
        d=P->dateDeRetour.days;m=P->dateDeRetour.month;
        if (P->penaliter>0){
        DateDeRetour(&(d),&(m),&(y),2*(P->penaliter));
        pin=DiffiranceEntre2Date(Days,Month,Years,d,m,y);
        }else pin=0;
        if (i==0) {
                printf("IL YA ERREUR DANS LES FICHIER cote");
                exit(1);
                return 0;
        }
        L=AccPos1_Livre(i,*Livre);
        P->livreEmprunte=L;
        (L->nbrDeEmprunt)++;
        if ((P->livreRendu)==0) {
                L->disponible=0;
                L->Emprunt=P;
            }
        i=RechachezUnOrdreInscription_Emprunteur(*Emprunteur,ordre);
        if(i==0) {
                printf("IL YA ERREUR DANS LES FICHIER Ordre");
                exit(1);
                return 0;
            }
        E=AccPos1_Emprunteur(i,*Emprunteur);
        P->Emprunteur=E;
        (E->NbreDeEmprunt)++;
        (E->penaliterTotal)+=P->penaliter;
        if ((P->livreRendu)==0) {
                E->Emprunter=1;
                E->Emprunt=P;
            }
        if (pin>0) (E->penaliter)+=pin;
        Q=P;
    }
    if (P!=NULL) aff_adr_Emprunt(P,NULL);
    fclose(F1);
}
void EcrireLivre(maillon_Livre**Livre){

    /// ECRIRE DANS FICHIER LIVRE LES INFORMATION QUI SONT DANS LISTE LIVRE

    FILE *F=fopen("Fiche livre.txt","w");
    maillon_Livre* P;
    P=*Livre;
    while(P!=NULL){
       RamplcerCracrter(P->auteur,' ','_');
       RamplcerCracrter(P->editeur,' ','_');
       RamplcerCracrter(P->titre,' ','_');
       fprintf(F,"%d %s %s %d/%d/%d %s (%s) #%s#\n",P->cote,P->titre,P->auteur,P->dateEdition.days,P->dateEdition.month,P->dateEdition.years,P->editeur,P->motCle,P->resume);
       P=suivant_Livre(P);
    }
    fclose(F);
}
void EcrireEmprunteur(maillon_Emprunteur**Emprunteur){

    /// ECRIRE DANS FICHIER EMPRUNTEUR LES INFORMATION QUI SONT DANS LISTE EMPRUNTEUR

    FILE *F=fopen("Fiche Emprunteur.txt","w");
    maillon_Emprunteur* P;
    P=*Emprunteur;
    while(P!=NULL){
       RamplcerCracrter(P->adresseActuelle,' ','_');
       RamplcerCracrter(P->nom,' ','_');
       RamplcerCracrter(P->prenom,' ','_');

       fprintf(F,"%s %s %s %s %d %d/%d/%d\n",P->nom,P->prenom,P->adresseActuelle,P->nDeTelephone,P->ordreInscription,P->dateDeInscription.days,P->dateDeInscription.month,P->dateDeInscription.years);
       P=suivant_Emprunteur(P);
    }
    fclose(F);
}
void EcrireEmprunt(maillon_Emprunt**Emprunt){

    /// ECRIRE DANS FICHIER EMPRUNT ET OTHERS LES INFORMATION QUI SONT DANS LISTE EMPRUNT

    FILE *F1;
    F1=fopen("Fiche Emprunt.txt","w");
    maillon_Emprunt* P;
    P=*Emprunt;
    while(P!=NULL){
        fprintf(F1,"%d %d %d/%d/%d %d/%d/%d %d %d\n",P->livreEmprunte->cote,P->Emprunteur->ordreInscription,P->dateDeEmprunt.days,P->dateDeEmprunt.month,P->dateDeEmprunt.years,P->dateDeRetour.days,P->dateDeRetour.month,P->dateDeRetour.years,P->livreRendu,P->penaliter);
        P=suivant_Emprunt(P);
    }
    fclose(F1);
}
void Sauvergarder(maillon_Emprunt**Emprunt,maillon_Livre**Livre,maillon_Emprunteur**Emprunteur){

    /// SAUVERGARDER LES TROIS LISTE DANS LES FICHIER

    EcrireLivre(Livre);
    EcrireEmprunteur(Emprunteur);
    EcrireEmprunt(Emprunt);

}
void EclaterEmprunt(maillon_Emprunt*Emprunt){

    /// ECLATER LA LISTE EN 2 LISTE ET SAUVERGARDER EN 2 FICHIER

    resetcolor();
    system("CLS");
    maillon_Emprunt *TEmpruntEnCours,*TEmpruntTerminer,*P;
    Eclater2ListeEmprunt(Emprunt,&TEmpruntEnCours,&TEmpruntTerminer);
    FILE *F1,*F2;
    F1=fopen("Fiche Emprunt En cours.txt","w");
    F2=fopen("Fiche Emprunt pas En cours.txt","w");
    P=TEmpruntEnCours;
    while(P!=NULL){
        fprintf(F1,"%d %d %d/%d/%d %d/%d/%d\n",P->livreEmprunte->cote,P->Emprunteur->ordreInscription,P->dateDeEmprunt.days,P->dateDeEmprunt.month,P->dateDeEmprunt.years,P->dateDeRetour.days,P->dateDeRetour.month,P->dateDeRetour.years);
        P=suivant_Emprunt(P);
    }
    fclose(F1);
    P=TEmpruntTerminer;
    while(P!=NULL){
        fprintf(F2,"%d %d %d/%d/%d %d/%d/%d\n",P->livreEmprunte->cote,P->Emprunteur->ordreInscription,P->dateDeEmprunt.days,P->dateDeEmprunt.month,P->dateDeEmprunt.years,P->dateDeRetour.days,P->dateDeRetour.month,P->dateDeRetour.years);
        P=suivant_Emprunt(P);
    }
    fclose(F2);
    cputsxych(22,3,"LE ECLATEMENT EST TERMINER AVEC SECCES MERCI ...");
    cputsxych(12,4,"ALLER VOIR LE FICHIER Fiche Emprunt En cours.txt ET Fiche Emprunt En cours.txt ...");
    getch();

}
int  RechachezUnNom_Emprunteur(maillon_Emprunteur*liste,char* nom){

    /** RECHARCHEZ DANS LISTE DES EMPRUNTEUR
     ** SI IL EXISTE  RENVOIS SON PREMIER POSTION
     ** SI N'EXISTE PAS RENVOIS 0
     **/

     int i=0,cpt=0;
     char* a=UpperCase(nom);
     maillon_Emprunteur *p=liste ;
     while ( p != NULL){
            cpt++;
        if (!strcmp(UpperCase(p->nom),a)){
            i=cpt;
            break;
        }
        p=suivant_Emprunteur(p);
     }
    return i;
}
int  RechachezUnPrenom_Emprunteur(maillon_Emprunteur*liste,char* Prenom){

    /** RECHARCHEZ DANS LISTE DES EMPRUNTEUR
     ** SI IL EXISTE  RENVOIS SON PREMIER POSTION
     ** SI N'EXISTE PAS RENVOIS 0
     **/

     int i=0,cpt=0;
     char* a=UpperCase(Prenom);
     maillon_Emprunteur *p=liste ;
     while ( p != NULL){
            cpt++;
        if (!strcmp(UpperCase(p->prenom),a)){
            i=cpt;
            break;
        }
        p=suivant_Emprunteur(p);
     }
    return i;
}
int  RechachezUnAdresseActuelle_Emprunteur(maillon_Emprunteur*liste,char* adresseActuelle){

    /** RECHARCHEZ DANS LISTE DES EMPRUNTEUR
     ** SI IL EXISTE  RENVOIS SON PREMIER POSTION
     ** SI N'EXISTE PAS RENVOIS 0
     **/

     int i=0,cpt=0;
     char* a=UpperCase(adresseActuelle);
     maillon_Emprunteur *p=liste ;
     while ( p != NULL){
            cpt++;
        if (!strcmp(UpperCase(p->adresseActuelle),a)){
            i=cpt;
            break;
        }
        p=suivant_Emprunteur(p);
     }
    return i;
}
int  RechachezUnOrdreInscription_Emprunteur(maillon_Emprunteur*liste,int ordreInscription){

    /** RECHARCHEZ DANS LISTE DES EMPRUNTEUR
     ** SI IL EXISTE  RENVOIS SON PREMIER POSTION
     ** SI N'EXISTE PAS RENVOIS 0
     **/

     int i=0,cpt=0;
     maillon_Emprunteur *p=liste ;
     while ( p != NULL){
            cpt++;
        if (p->ordreInscription==ordreInscription){
            i=cpt;
            break;
        }
        p=suivant_Emprunteur(p);
     }
    return i;
}
void TrieListeEmprunteur(maillon_Emprunteur**Emprunteur){

        /// TRIE LE LISTE DES EMPRUNTEURS

        if ((*Emprunteur)!=NULL){
            if (suivant_Emprunteur(*Emprunteur)!=NULL){
                maillon_Emprunteur *P,*S,*T;
                int q=1;
                while(q){
                    q=0;
                    P=*Emprunteur;
                    T=P;
                    S=suivant_Emprunteur(P);
                    while(S!=NULL){
                        if ((P->NbreDeEmprunt)<(S->NbreDeEmprunt)){
                            q=1;
                            if (T==P) *Emprunteur=S;
                                else aff_adr_Emprunteur(T,S);
                            aff_adr_Emprunteur(P,suivant_Emprunteur(S));
                            aff_adr_Emprunteur(S,P);
                            }
                        T=P;
                        P=S;
                        S=suivant_Emprunteur(S);
                        }
                    }
            }
        }
}
void TrieListePenaliterEmprunteur(maillon_Emprunteur**Emprunteur){

        /// TRIE LE LISTE DES EMPRUNTEURS

        if ((*Emprunteur)!=NULL){
            if (suivant_Emprunteur(*Emprunteur)!=NULL){
                maillon_Emprunteur *P,*S,*T;
                int q=1;
                while(q){
                    q=0;
                    P=*Emprunteur;
                    T=P;
                    S=suivant_Emprunteur(P);
                    while(S!=NULL){
                        if (P->penaliterTotal<S->penaliterTotal){
                            q=1;
                            if (T==P) *Emprunteur=S;
                                else aff_adr_Emprunteur(T,S);
                            aff_adr_Emprunteur(P,suivant_Emprunteur(S));
                            aff_adr_Emprunteur(S,P);
                            }
                        T=P;
                        P=S;
                        S=suivant_Emprunteur(S);
                        }
                    }
            }
        }
}
maillon_Emprunteur* CopierEmprunteur(maillon_Emprunteur*Emprunteur){

    /// RETURN COPIER LA LISTE EMPRUNTEUR

    maillon_Emprunteur *P=Emprunteur,*P1,*Q1,*T=NULL;

    while (P!=NULL){
        allouer_Emprunteur(&P1);
        (*P1)=(*P);
        if (T==NULL) T=P1;
            else aff_adr_Emprunteur(Q1,P1);
        Q1=P1;
        P=suivant_Emprunteur(P);
    }

    if (Q1!=NULL)
        aff_adr_Emprunteur(Q1,NULL);
    return T;
}
maillon_Emprunteur* CopierEmprunteurBloquer(maillon_Emprunteur*Emprunteur){

    /// RETURN COPIER LA LISTE EMPRUNTEUR BLOQUER

    maillon_Emprunteur *P=Emprunteur,*P1,*Q1,*T=NULL;

    while (P!=NULL){
        if ((P->penaliter)>0){
        allouer_Emprunteur(&P1);
        (*P1)=(*P);
        if (T==NULL) T=P1;
            else aff_adr_Emprunteur(Q1,P1);
        Q1=P1;
        }
        P=suivant_Emprunteur(P);
    }

    if (Q1!=NULL)
        aff_adr_Emprunteur(Q1,NULL);
    return T;
}
void Eclater2ListeEmprunt(maillon_Emprunt*emprunt,maillon_Emprunt**empruntEncours,maillon_Emprunt**empruntNonEncours){

    maillon_Emprunt *P=emprunt,*Q,*P1=NULL,*P2=NULL;
    *empruntEncours=NULL;
    *empruntNonEncours=NULL;
    while(P!=NULL){
        allouer_Emprunt(&Q);
        (*Q)=(*P);
        if (P->livreRendu){
            if (*empruntNonEncours==NULL) *empruntNonEncours=Q;
                else aff_adr_Emprunt(P1,Q);
            P1=Q;
        }else{
            if (*empruntEncours==NULL) *empruntEncours=Q;
                else aff_adr_Emprunt(P2,Q);
            P2=Q;
        }
        P=suivant_Emprunt(P);
        }
    if (P1!=NULL) aff_adr_Emprunt(P1,NULL);
    if (P2!=NULL) aff_adr_Emprunt(P2,NULL);
}
int  RechachezUnCote_Livre(maillon_Livre*liste,int cote){

    /** RECHARCHEZ DANS LISTE DES LIVRES
     ** SI IL EXISTE  RENVOIS SON PREMIER POSTION
     ** SI N'EXISTE PAS RENVOIS 0
     **/

     int i=0,cpt=0;
     maillon_Livre *p=liste ;
     while ( p != NULL){
            cpt++;
        if (p->cote==cote){
            i=cpt;
            break;
        }
        p=suivant_Livre(p);
     }
    return i;
}
void RechacheParMotsCles(maillon_Livre*Livre,char mot[],maillon_Livre* tab[]){

        /** RECHARCHER TOUS LES MAILLON QUI SONT AVEC LEs MOT CLEs MOT
         ** IL SAUVERGERDE LEURS ADRESS DANS TABLEAUX TAB
         **/

         int i=0,m,rep=1,j=0;
        maillon_Livre* P=Livre;
        tab[0]=NULL;
        char* b[20];
        DecopPhrase(mot,b,&m);
        while(P!=NULL){
                rep=1;
            for (j=0;j<m;j++)
            if (strstrcase(P->motCle,b[j])==0){
                rep=0;
                break;
            }

            if (rep) (tab)[i++]=P;
            P=suivant_Livre(P);
        }
        if (tab[0]!=NULL) printf("%s",tab[0]->auteur);
         (tab)[i]=NULL;
}
void RechacheParAuteur(maillon_Livre*Livre,char Auteur[],maillon_Livre* tab[]){

        /** RECHARCHER TOUS LES MAILLON QUI SONT AVEC LE AUTEUR
         ** IL SAUVERGERDE LEURS ADRESS DANS TABLEAUX TAB
         **/

         int i=0;
        maillon_Livre* P=Livre;
        while(P!=NULL){
            if (strstrcase(P->auteur,Auteur)) tab[i++]=P;
            P=suivant_Livre(P);
        }
         tab[i]=NULL;
}
void TrieListe(maillon_Livre**Livre){

        /// TRIE LE LISTE DES LIVRES

        if ((*Livre)!=NULL){
            if (suivant_Livre(*Livre)!=NULL){
                maillon_Livre *P,*S,*T;
                int q=1;
                while(q){
                    q=0;
                    P=*Livre;
                    T=P;
                    S=suivant_Livre(P);
                    while(S!=NULL){
                        if (P->nbrDeEmprunt<S->nbrDeEmprunt){
                            q=1;
                            if (T==P) *Livre=S;
                                else aff_adr_Livre(T,S);
                            aff_adr_Livre(P,suivant_Livre(S));
                            aff_adr_Livre(S,P);
                            }
                        T=P;
                        P=S;
                        S=suivant_Livre(S);
                        }
                    }
            }
        }
}
maillon_Livre* CopierLivre(maillon_Livre*Livre){

    /// RETURN COPIER LA LISTE LIVRE

    maillon_Livre *P=Livre,*P1,*Q1,*T=NULL;

    while (P!=NULL){
        allouer_Livre(&P1);
        (*P1)=(*P);
        if (T==NULL) T=P1;
            else aff_adr_Livre(Q1,P1);
        Q1=P1;
        P=suivant_Livre(P);

    }
    aff_adr_Livre(Q1,NULL);
    return T;
}
void Eclater2ListeLivres(maillon_Livre*Livre,maillon_Livre**LivreDisponible,maillon_Livre**LivreNonDisponible){

    maillon_Livre *P=Livre,*Q,*P1=NULL,*P2=NULL;
    *LivreNonDisponible=NULL;
    *LivreDisponible=NULL;
    while(P!=NULL){
        allouer_Livre(&Q);
        (*Q)=(*P);

        if (P->disponible){
            if ((*LivreDisponible)==NULL) (*LivreDisponible)=Q;
                else aff_adr_Livre(P1,Q);
            P1=Q;
        }else{

            if ((*LivreNonDisponible)==NULL) (*LivreNonDisponible)=Q;
                else aff_adr_Livre(P2,Q);
            P2=Q;
        }
        P=suivant_Livre(P);
        }

    if (P1!=NULL) aff_adr_Livre(P1,NULL);
    if (P2!=NULL)  aff_adr_Livre(P2,NULL);
}
void CalculePinaliterEncours(maillon_Emprunteur**Emprunteur){

        /** CALCULE LA PINALITER EN COURS
         ** TRIE LA LISTE SELON LA PENALITER
         ** SUPPRIME LES EMPRUNTEUR QUI N'EST PAS PENALITER
         **/

     time_t tk;
     struct tm *TimeActeul;
     time(&tk); /// ON LIT LE DATE DE PC
     TimeActeul=localtime(&tk); /// ON LES CONVERTIRE
     int Years=TimeActeul->tm_year+1900,Days=TimeActeul->tm_mday,Month=TimeActeul->tm_mon+1;
     maillon_Emprunteur *P,*Q=NULL;
     P=*Emprunteur;
     int i,j;
     while(P!=NULL){
        if ((P->Emprunter)!=0){
            i=DiffiranceEntre2Date(P->Emprunt->dateDeRetour.days,P->Emprunt->dateDeRetour.month,P->Emprunt->dateDeRetour.years,Days,Month,Years);
            if (i>0) (P->penaliterTotal)+=i;
        }
        P=suivant_Emprunteur(P);
        }
    TrieListePenaliterEmprunteur(Emprunteur);
    P=*Emprunteur;
    while(P!=NULL){
        if ((P->penaliterTotal)==0) break;
        Q=P;
        P=suivant_Emprunteur(P);
    }
    if (P==*Emprunteur) *Emprunteur=NULL;
    if (P!=NULL) viderListe_Emprunteur(&P);
    if (Q!=NULL) aff_adr_Emprunteur(Q,NULL);
}

#endif
