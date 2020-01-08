#ifndef _Bib_Graphique_H_
#define _Bib_Graphique_H_

#include "Bib_LLC_BIBLIO.h"
#include "Bib_Standare.h"
#include "conio.h"
#include "conio2.h"
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#define ColorSup WHITE
#define colorbackgroundDate WHITE
#define colorTexteDate BLACK
#define COLOR0 DARKGRAY
#define COLOR1 WHITE
#define COLOR2 LIGHTGRAY
#define COLORECRAN BLACK
#define PX 30
#define PY 10
#define HTR 20
#define LNGR 100
#define PX1 30
#define PY1 10
#define HTR1 30
#define LNGR1 100
#define string char *
#define ColorSelect DARKGRAY
#define ColorDeselect LIGHTGRAY
#define ColorInput DARKGRAY
#define ColorTextInput WHITE
#define ColorTexteErreur WHITE
#define ColorbackgroundErreur RED
#define ColorDeTitre BLACK
#define ColorCadre BLUE
#define ColorCadre2 RED
#define Tmp 10

int colorText0 = BLACK;       /// color de la text
int colorbackground0 = WHITE; /// color de la background
int colorText = BLACK;        /// color de la text
int colorbackground = WHITE;  /// color de la background
void resetcolor() {
  colorbackground = colorbackground0;
  colorText = colorText0;
  textbackground(colorbackground0);
  textcolor(colorText0);
}
void cputsxych(int x, int y, char *a) {

  int i = 0;
  gotoxy(x, y);
  while (a[i] != 0) {
    printf("%c", a[i++]);
    Sleep(Tmp);
  }
}
void cputsxyBlanc(int x, int y, char ch[], int T) {

  /** affichez un chaine de cract�re � la postion (x,y) dans ecran
   ** affichez seulement T cract�re
   ** si la longueur de ch < T donc terminera le affichage par de blanc
   **/

  int i, m = strlen(ch); /// calculer la longueur de chain de cract�re ch
  gotoxy(x, y);          /// allez � la postion (x,y)
  for (i = 0; i < T; i++) {
    if (i < m)
      printf("%c", ch[i]);
    else
      printf(" "); /// on complete la rest par de blanc
  }
}
void cputcxyBlanc(int x, int y, char ch[], int T, int pos[]) {

  /** affichez les cract�re ch[i] de chain un par un  � la postion (x+pos[i],y)
   *dans ecran affichez seulement T cract�re si la longueur de ch < T donc
   *terminera le affichage par de blanc
   **/

  int i, m = strlen(ch); // calculer la longueur de chain de cract�re ch

  for (i = 0; i < T; i++) {
    if (i < m)
      cputsxyBlanc(x + pos[i], y, &(ch[i]), 1);
    else
      cputsxyBlanc(x + pos[i], y, " ", 1); // on complete la rest par de blanc
  }
}
void AffichezButon(char *ch, int x, int y, int l, int color) {

  /** AFFICHEZ UN BUTON DE NOM CH DE LONG L
   ** COLOR EST SA COLOR
   **/

  // AffichezPage(x-1,y-1,l,3,color);
  int i, j;
  textbackground(color);
  for (i = 0; i < 3; i++) {
    gotoxy(x - 1, y - 1 + i);
    for (j = 0; j < l; j++)
      printf(" ");
    cputsxyBlanc(x - 1, y + i - 1, " ",
                 l); /// affichez un text avec seulement de blanc
  }
  i = strlen(ch);
  cputsxy(x + (l - i) / 2 - 1, y, ch);
  textbackground(colorbackground);
}
void AffichezErreur(int x, int y, char e[]) {

  /** AFFICHEZ UN AVIRETISSEMENT DANS LA POSTION (x,y)
   **/

  textcolor(ColorTexteErreur);
  textbackground(ColorbackgroundErreur);
  printf("%c", 7);
  printf("%c", 7);
  cputsxyBlanc(x, y - 1, " ", strlen(e));
  cputsxych(x, y, e);
  textcolor(colorText);
  textbackground(colorbackground);
}
void AffichezPage(int x, int y, int Longueur, int Hauteur, int color) {

  /** affiche une page vide
   ** color est sa color
   ** debutera par la postion (x,y)
   ** se termenra sur la postion (x+longueur-1,y+Hauteur-1)
   **/
  system("CLS");
  /*int i,j;
   textbackground(color);
   for (i=0;i<Hauteur;i++){
      gotoxy(x,y+i);
      for (j=0;j<Longueur;j++) printf(" ");
      //cputsxyBlanc(x,y+i," ",Longueur); /// affichez un text avec seulement de
  blanc
      }
  textbackground(colorbackground); /// return le color de text comme aupervant*/
}
void AffichezCadre(int x, int y, int Longueur, int Hauteur, int ch, int color) {

  /** Affichez un cadre avec cract�re ch debutera par la postion (x,y)
   ** se termenra sur la postion (x+longueur-1,y+Hauteur-1)
   ** color est le color de cadre
   **/
  int i;
  if (ch == 219)
    textbackground(color);
  textcolor(color);
  gotoxy(x, y);
  for (i = 0; i < Longueur; i++)
    printf("%c", ch);
  gotoxy(x, y + Hauteur - 1);
  for (i = 0; i < Longueur; i++)
    printf("%c", ch);
  for (i = 1; i < Hauteur - 1; i++) {
    gotoxy(x, y + i);
    printf("%c", ch);
    gotoxy(x + Longueur - 1, y + i);
    printf("%c", ch);
  }
  if (ch == 219)
    textbackground(colorbackground);
  textcolor(colorText); /// return le color du text comme aupervant
}
void AffichezTexte(char text[], int x, int y, int Longueur, int color,
                   int ColorBackground) {

  /** AFFICHEZ UN TEXTE DANS CADRE DE COLOR colorBackground
   **/

  // AffichezPage(x,y,Longueur,Hauteur,ColorBackground);
  textbackground(ColorBackground);
  textcolor(color);
  int i = 0, j = 0, f = 0;
  char s[30];
  gotoxy(x, y);
  do {
    if (text[i] == 0)
      break;
    if ((text[i] == ' ') || (text[i] == ',') || (text[i] == '.')) {
      f += j;
      if (f >= Longueur) {
        f = j;
        gotoxy(x, wherey() + 1);
      }
      s[j] = 0;
      printf("%s%c", s, text[i]);
      j = 0;
    } else
      s[j++] = text[i];
    if (text[i] == '.') {
      gotoxy(x, wherey() + 1);
      f = 0;
    }
    i++;
  } while (1);
  if ((f % Longueur + j) >= Longueur)
    gotoxy(x, wherey() + 1);
  s[j] = 0;
  printf("%s", s);
  textbackground(colorbackground);
  textcolor(colorText);
}
void AffichezInputDate(int x, int y, int pos[9]) {

  /** AFFICHEZ 3 INPUTS POUR SAISER LA DATE ET MOIS ET ANNES
   * AFFICHERA PARTIRE DE LA POSTION (x,y)
   * pos EST UN TABLEAUX DE INTEGER QUI VA QUANTENIRE LES POSTION DES SAISTION
   **/

  cputsxy(x, y, "DAYS :      MONTHE :      YEARS :"); // AFFICHEZ LES MOTS CLE
  textbackground(ColorInput);
  // AFFICHEZ LES INPUTS A SAISER
  cputsxy(x + 7, y, "    ");
  cputsxy(x + 7, y - 1, "    ");
  cputsxy(x + 20, y, "    ");
  cputsxy(x + 20, y - 1, "    ");
  cputsxy(x + 33, y, "      ");
  cputsxy(x + 33, y - 1, "      ");
  // REMPLIER LE TANLEAUX AVEC LES POSTION DES INPUTS
  pos[0] = 8;
  pos[1] = 9;
  pos[2] = 21;
  pos[3] = 22;
  pos[4] = 34;
  pos[5] = 35;
  pos[6] = 36;
  pos[7] = 37;
  pos[8] = 38;
  textbackground(colorbackground);
}
void AffichezListeChoix(char **ch, int NbrChoix, int num, int MaxLongueurString,
                        int x, int y) {

  /** Affichez un liste des chiox qui se trouve dans tableau ch de Nbrchoix
   * phrase la taille maximan de ces phrase est MaxLongString le premier pherase
   * se trouve dans la postion (x,y) de ecran le num est un debut numeration de
   * la pherase � affichez
   */

  int i;
  char c[5];
  for (i = 0; i < NbrChoix; i++) {
    /// allez � la postion (x,y+i) le premier phrase se trouve dans (x,y) et la
    /// 2 se trouva dans (x,y+1) ...
    sprintf(c, "%d- ", num + i);
    cputsxyBlanc(x, y + i, c, 5); /// affichez le numeration
    cputsxyBlanc(x + 5, y + i, ch[i], MaxLongueurString - 5);
  }
  gotoxy(1, 1);
}
int Menu(char **Ph, int NbrPhrase, int x, int y, int Longueur, int Hauteur) {

  /** Affichez Le menu
   ** return le nemero choiser
   ** return 0 c'est choiser retourner en arreire
   **/
  int Mn, chx = 1, f = 0;
  char c;
  Mn = Min(Hauteur, NbrPhrase); /// on prend le minimant pour affichez les choix
                                /// pour evitez de soortire de cadre
  AffichezPage(x, y, Longueur, Hauteur, COLOR1);
  AffichezCadre(x - 1, y - 1, Longueur + 2, Hauteur + 2, 219, COLOR0);

  textbackground(COLOR1); /// affichez le reste des choix avec le color1
  AffichezListeChoix(&(Ph[1]), Mn - 1, 2, Longueur, x, y + 1);
  textbackground(COLOR2); /// Affichez le prmier choix avec le color2
  AffichezListeChoix(Ph, 1, 1, Longueur, x, y);
  do {
    do {
      c = getch();
    } while ((c != -32) && (c != 8) && (c != 27) && (c != 13));
    if ((c == 8) || (c == 27)) {
      chx = 0; /// chiox pour retournez en arriere
      break;
    }
    if (c == 13)
      break; /// il chioser le choix selectionez
    c = getch();
    if ((c != 72) && (c != 80))
      continue;
    textbackground(COLOR1);
    if (c == 72) {
      /// SI IL APPEUIYER SUR UP
      if ((f == 0) && (NbrPhrase > Mn)) {
        if (chx == 1) {
          f = Mn - 1;
          AffichezListeChoix(&Ph[NbrPhrase - Mn], Mn - 1, NbrPhrase - Mn + 1,
                             Longueur, x, y);
        } else
          AffichezListeChoix(&Ph[chx - 1], Mn - 1, chx, Longueur, x, y + 1);
      } else {
        AffichezListeChoix(&Ph[chx - 1], 1, chx, Longueur, x, y + f);
        f = ((f + Mn) - 1) % Mn; /// decrimanter le f mais il dois restez sur
                                 /// intervale 0 .. Hauteur-1
      }
      chx = ((chx + NbrPhrase) - 2) % NbrPhrase +
            1; /// decrimanter le chx mais il dois restez sur intervale 1 ..
               /// NbrPhrase
    } else {
      if (c == 80) {
        if ((f == Mn - 1) && (NbrPhrase > Mn)) {
          if (chx == NbrPhrase) {
            f = 0;
            AffichezListeChoix(&Ph[1], Mn - 1, 2, Longueur, x, y + 1);
          } else
            AffichezListeChoix(&Ph[chx - f], Mn - 1, chx - f + 1, Longueur, x,
                               y);
        } else {
          AffichezListeChoix(&Ph[chx - 1], 1, chx, Longueur, x, y + f);
          f = ((f + Mn) + 1) % Mn; /// incrimanter le f mais il dois restez sur
                                   /// intervale 0 .. Hauteur-1
        }
        chx = (chx + NbrPhrase) % NbrPhrase +
              1; /// incrimanter le chx mais il dois restez sur intervale 1 ..
                 /// NbrPhrase
      }
    }
    textbackground(COLOR2); /// Affichez le prmier choix avec le color2
    AffichezListeChoix(&Ph[chx - 1], 1, chx, Longueur, x, y + f);
  } while (1);
  gotoxy(1, 1);
  resetcolor();
  return chx;
}
void Afficher_Emprunteur(maillon_Emprunteur *P, int x, int y, int Longueur,
                         int Hauteur, int color) {

  /** AFFICHEZ UN TOUS LES INFORMATION DE MAILLON QUI SE TROUVE DANS P
   ** LE AFFICHERA DANS CADRE DE (x,y) DEBUTRA
   **/

  int pas = ((Hauteur - 13) / 10) + 1, i = (Longueur - 60) / 2;
  char m[100];
  AffichezPage(x, y, Longueur, Hauteur, colorbackground);
  AffichezCadre(x - 1, y - 1, Longueur + 2, Hauteur + 2, 5, color);

  cputsxy(x + i, y + 2, "CODE EMPRUNTEUR");
  cputsxy(x + i, y + 2 + pas, "NOM");
  cputsxy(x + i, y + 2 + 2 * pas, "PRENOM");
  cputsxy(x + i, y + 2 + 3 * pas, "ADRESSE ACTUELLE");
  cputsxy(x + i, y + 2 + 4 * pas, "NUMERO DE TELEPHONE");
  cputsxy(x + i, y + 2 + 5 * pas, "DATE D'INSCRIPTION");
  cputsxy(x + i, y + 2 + 6 * pas, "PENALITE TOTAL");
  cputsxy(x + i, y + 2 + 7 * pas, "NOMBRE DES LIVRES EMPRUNTER");
  cputsxy(x + i, y + 2 + 8 * pas, "COTE DE LIVRE EMPRUNTER");
  cputsxy(x + i, y + 2 + 9 * pas, "DATE PRIVU DE RETOUR DE LIVRE");
  cputsxy(x + i, y + 2 + 10 * pas, "BLOUQUER");
  sprintf(m, "%d", P->ordreInscription);
  cputsxych(x + i + 30, y + 2, m);
  cputsxych(x + i + 30, y + 2 + pas, P->nom);
  cputsxych(x + i + 30, y + 2 + 2 * pas, P->prenom);
  cputsxych(x + i + 30, y + 2 + 3 * pas, P->adresseActuelle);
  cputsxych(x + i + 30, y + 2 + 4 * pas, P->nDeTelephone);
  sprintf(m, "%d/%d/%d", P->dateDeInscription.days, P->dateDeInscription.month,
          P->dateDeInscription.years);
  cputsxych(x + i + 30, y + 2 + 5 * pas, m);
  sprintf(m, "%d", P->penaliterTotal);
  cputsxych(x + i + 30, y + 2 + 6 * pas, m);
  sprintf(m, "%d", P->NbreDeEmprunt);
  cputsxych(x + i + 30, y + 2 + 7 * pas, m);
  if (P->Emprunter && P->Emprunt != NULL) {
    sprintf(m, "%d", P->Emprunt->livreEmprunte->cote);
    cputsxych(x + i + 30, y + 2 + 8 * pas, m);
    sprintf(m, "%d/%d/%d", P->Emprunt->dateDeRetour.days,
            P->Emprunt->dateDeRetour.month, P->Emprunt->dateDeRetour.years);
    cputsxych(x + i + 30, y + 2 + 9 * pas, m);
  } else {
    cputsxych(x + i + 30, y + 2 + 8 * pas, "Non");
    cputsxych(x + i + 30, y + 2 + 9 * pas, "Non");
  }
  if (P->penaliter == 0)
    sprintf(m, "Non");
  else
    sprintf(m, "IL VA RESTE %d JOURS", P->penaliter);
  cputsxych(x + i + 30, y + 2 + 10 * pas, m);
  getch();
}
void Afficher_Livre(maillon_Livre *P, int x, int y, int Longueur, int Hauteur,
                    int color) {

  /** AFFICHEZ UN TOUS LES INFORMATION DE MAILLON QUI SE TROUVE DANS P
   ** LE AFFICHERA DANS CADRE DE (x,y) DEBUTRA
   **/

  int pas = ((Hauteur - 15) / 12) + 1, i = 10;
  char m[100];
  AffichezPage(x, y, Longueur, Hauteur, colorbackground);
  AffichezCadre(x - 1, y - 1, Longueur + 2, Hauteur + 2, 5, color);

  cputsxy(x + i, y + 2, "COTE");
  cputsxy(x + i, y + 2 + pas, "TITRE");
  cputsxy(x + i, y + 2 + 2 * pas, "AUTEUR");
  cputsxy(x + i, y + 2 + 3 * pas, "EDITEUR");
  cputsxy(x + i, y + 2 + 4 * pas, "DATE DE EDITION");
  cputsxy(x + i, y + 2 + 5 * pas, "MOT CLE");
  cputsxy(x + i, y + 2 + 6 * pas, "DISPONIBLE");
  cputsxy(x + i, y + 2 + 7 * pas, "CODE EMPRUNTEUR");
  cputsxy(x + i, y + 2 + 8 * pas, "DATE PRIVU DE RETOUR DE LIVRE");
  cputsxy(x + i, y + 2 + 9 * pas, "NOMBRE DE EMPRUNT");
  cputsxy(x + i, y + 2 + 10 * pas, "RESUMER");
  sprintf(m, "%d", P->cote);
  cputsxych(x + i + 30, y + 2, m);
  cputsxych(x + i + 30, y + 2 + pas, P->titre);
  cputsxych(x + i + 30, y + 2 + 2 * pas, P->auteur);
  cputsxych(x + i + 30, y + 2 + 3 * pas, P->editeur);
  sprintf(m, "%d/%d/%d", P->dateEdition.days, P->dateEdition.month,
          P->dateEdition.years);
  cputsxych(x + i + 30, y + 2 + 4 * pas, m);
  cputsxych(x + i + 30, y + 2 + 5 * pas, P->motCle);
  if (P->disponible) {
    cputsxych(x + i + 30, y + 2 + 6 * pas, "Oui");
    cputsxych(x + i + 30, y + 2 + 7 * pas, "Non");
    cputsxych(x + i + 30, y + 2 + 8 * pas, "Non");
  } else {
    cputsxych(x + i + 30, y + 2 + 6 * pas, "Non");
    sprintf(m, "%d %s %s", P->Emprunt->Emprunteur->ordreInscription,
            P->Emprunt->Emprunteur->nom, P->Emprunt->Emprunteur->prenom);
    cputsxych(x + i + 30, y + 2 + 7 * pas, m);
    sprintf(m, "%d/%d/%d", P->Emprunt->dateDeRetour.days,
            P->Emprunt->dateDeRetour.month, P->Emprunt->dateDeRetour.years);
    cputsxych(x + i + 30, y + 2 + 8 * pas, m);
  }
  sprintf(m, "%d", P->nbrDeEmprunt);
  cputsxych(x + i + 30, y + 2 + 9 * pas, m);
  AffichezTexte(P->resume, x + i + 30, y + 2 + 10 * pas, Longueur - 50 - i,
                colorText, colorbackground);
  getch();
  gotoxy(1, 1);
}
void Afficher_Emprunt(maillon_Emprunt *P, int x, int y, int Longueur,
                      int Hauteur, int color) {

  /** AFFICHEZ UN TOUS LES INFORMATION DE MAILLON QUI SE TROUVE DANS P
   ** LE AFFICHERA DANS CADRE DE (x,y) DEBUTRA
   **/

  int pas = ((Hauteur - 12) / 10) + 1, i = (Longueur - 60) / 2;
  char m[100];
  AffichezPage(x, y, Longueur, Hauteur, colorbackground);
  AffichezCadre(x - 1, y - 1, Longueur + 2, Hauteur + 2, 5, color);

  cputsxych(x + i, y + 2, "CODE EMPRUNTEUR");
  cputsxy(x + i, y + 2 + pas, "NOM");
  cputsxy(x + i, y + 2 + 2 * pas, "PRENOM");
  cputsxy(x + i, y + 2 + 3 * pas, "COTE");
  cputsxy(x + i, y + 2 + 4 * pas, "AUTEUR");
  cputsxy(x + i, y + 2 + 5 * pas, "TITRE");
  cputsxy(x + i, y + 2 + 6 * pas, "DATE DE L'EMPRUNTE");
  cputsxy(x + i, y + 2 + 7 * pas, "DATE PRIVU DE RETOUR DE LIVRE");
  cputsxy(x + i, y + 2 + 8 * pas, "LIVRE RENDU");
  cputsxy(x + i, y + 2 + 9 * pas, "PENALITER DE CETTE EMPRUNTE");
  sprintf(m, "%d", P->Emprunteur->ordreInscription);
  cputsxych(x + i + 30, y + 2, m);
  cputsxych(x + i + 30, y + 2 + pas, P->Emprunteur->nom);
  cputsxych(x + i + 30, y + 2 + 2 * pas, P->Emprunteur->prenom);
  sprintf(m, "%d", P->livreEmprunte->cote);
  cputsxych(x + i + 30, y + 2 + 3 * pas, m);
  cputsxych(x + i + 30, y + 2 + 4 * pas, P->livreEmprunte->auteur);
  cputsxych(x + i + 30, y + 2 + 5 * pas, P->livreEmprunte->titre);
  sprintf(m, "%d/%d/%d", P->dateDeEmprunt.days, P->dateDeEmprunt.month,
          P->dateDeEmprunt.years);
  cputsxych(x + i + 30, y + 2 + 6 * pas, m);
  sprintf(m, "%d/%d/%d", P->dateDeRetour.days, P->dateDeRetour.month,
          P->dateDeRetour.years);
  cputsxych(x + i + 30, y + 2 + 7 * pas, m);
  if (P->livreRendu)
    cputsxych(x + i + 30, y + 2 + 8 * pas, "Oui");
  else
    cputsxych(x + i + 30, y + 2 + 8 * pas, "Non");
  sprintf(m, "%d", P->penaliter);
  cputsxych(x + i + 30, y + 2 + 9 * pas, m);
  getch();
}
void InscriptionEmprunteur(maillon_Emprunteur **Tete) {

  /** AJOUTEZ UN EMPRENTEUR DANS LA LISTE
   ** LIRE LES INFORMATION DES ENTRES DES UTILISATAURE ET ET SAUVEGARDEZ DANS LA
   *LISTE
   ** FAIRE LE CONTROLER POUR POUR LES ENTRES DE UTILISATAURE
   ** DONNEZ A L'UTILISATAUR LA POSSIBELITER DE MODIFIER ET SUPPRIMER
   ** DONNEZ A L'UTILISATAUR DEUX BUTTON POUR SAUVERGERDEZ ET POUR RESTARER
   **/

  int Taille = 6, i, j, Lm[10] = {30, 30, 30, 10, 8, 1};
  int ps[10][50];
  char *Mot[] = {"NOM ", "PRENOM ", "ADRESSE ACTUELLE ", "NEMERO DE TELEPHONE ",
                 "DATE D'INSCRIPTION "};
  time_t tk;
  struct tm *TimeActeul;
  time(&tk);                   /// ON LIT LE DATE DE PC
  TimeActeul = localtime(&tk); /// ON LES CONVERTIRE
  int Years = TimeActeul->tm_year + 1900, Days = TimeActeul->tm_mday,
      Month = TimeActeul->tm_mon + 1;
  int Date = Years + (Month + Days * 100) * 10000;
  char *buton[2] = {"Save", "Reset"};
  int x = 40, y = 5, lg = 80, ht = 40;
debut:
  AffichezPage(x, y, lg, ht, colorbackground);
  AffichezCadre(x - 1, y - 1, lg + 2, ht + 2, 5, colorText);

  int pas = 40 / (Taille + 1), a = x + 30, b = y + 4;
  textcolor(ColorDeTitre); /// AFFICHEZ LES MOTS CLE AVEC LE COLOR RED
  for (i = 0; i < Taille - 1; i++) {
    gotoxy(x + 5, b + i * pas);
    printf("%s  : ", Mot[i]);
  }
RST: /// C'EST ICI LE RETOURE DE GOTO C'EST IL AUIYER SUR LE BUTON RESET
     /// AFFICHEZ DE UNPUT DE ENTREZ
  textcolor(ColorDeTitre);
  textbackground(ColorInput);
  for (i = 0; i < Taille - 2; i++) {
    cputsxyBlanc(a, b + i * pas - 1, " ", Lm[i]);
    cputsxyBlanc(a, b + i * pas, " ", Lm[i]);
  }
  for (i = 0; i < 10; i++)
    for (j = 0; j < 50; j++)
      ps[i][j] = j;
  char Info[10][50] = {""};
  textbackground(colorbackgroundDate);
  textcolor(colorTexteDate);
  AffichezInputDate(a, b + 4 * pas, &(ps[4][0]));
  colorbackground = ColorInput;
  textbackground(colorbackground);
  colorText = ColorTextInput;
  textcolor(colorText);
  int o = Date;
  for (i = 7; i >= 0; i--) {
    /// ON TRANFORM LA DATE EN CHAINE DE CARACTERE
    Info[4][i] = o % 10 + '0';
    o /= 10;
  }
  Info[4][8] = 0;
  cputcxyBlanc(a, b + 4 * pas, Info[4], 8,
               &(ps[4][0])); /// ON ECRIT LE CHAINE DE CARACTERE
  int saiser[10] = {0};
  saiser[4] = 8;
  saiser[5] = 2;
  ps[5][0] = 0;
  ps[5][1] = 20;
  for (j = 0; j < 2; j++)
    AffichezButon(buton[j], a + ps[5][j], b + (Taille - 1) * pas, 10,
                  ColorDeselect); /// AFFICHEZ DEUX BUTTON A L'ECRAN
  int Q = false;
  char c, po[20];
  i = 0;
  j = 0;
  do {
    gotoxy(a + ps[i][j], b + i * pas);
    c = getch();
    if ((!Q) && (c == 27))
      goto FG;
    if ((i == Taille - 1) && (!Q) && (c == 13)) {
      /// ALORS ICI IL APUIYER SUR UN BUTON
      textbackground(ColorSup); /// ON SUPPRIMER LE ANCIEN MESSAGE SI IL EXISTE
      cputsxyBlanc(x, y, " ", lg);
      cputsxyBlanc(x, y + 1, " ", lg);
      textbackground(colorbackground);
      if (j == 0) {
        /// IL APUIYER SUR SAVE
        int rep = true, k;
        for (k = 0; k < Taille; k++)
          if (saiser[k] == 0) {
            rep = false;
            /// SI IL YA UN CASE VIDE ON SIGNALE UN ERREUR
            AffichezErreur(x + 20, y + 1, " TU DOIS REMLIRE TOUS LES CASES ");
            break;
          }
        if (!rep)
          continue;
        char ya[30];
        sprintf(ya, "%s", &(Info[4][4]));
        Years = strtol(ya, NULL, 10);
        if ((Years < 2000) || (Years > 2100)) {
          /// SI LE DATE YEARS < 2000 OU > 2100 ON SIGNALE UN ERREUR
          AffichezErreur(x + 10, y + 1,
                         " LA DATE YEARS IL DOIT ENTRE 2000 .. 2100 ");
          continue;
        }
        sprintf(ya, "%c%c", Info[4][2], Info[4][3]);
        Month = strtol(ya, NULL, 10);
        if ((Month < 1) || (Month > 12)) {
          /// SI LE DATE MONTH INCORECT ON SIGNALE UN ERREUR
          AffichezErreur(x + 10, y + 1,
                         " LA DATE MONTHE EST INCORECT IL DOIT ENTRE 1 .. 12 ");
          continue;
        }
        sprintf(ya, "%c%c", Info[4][0], Info[4][1]);
        Days = strtol(ya, NULL, 10);
        k = MaxJour(Years, Month);
        if ((Days < 1) || (Days > k)) {
          sprintf(
              ya,
              " LA NEMERO DE JOUR EST INCORECT IL DOIT COMPRIT ENTRE 1 .. %d ",
              k);
          /// SI LE DATE DAYS INCORECT ON SIGNALE UN ERREUR
          AffichezErreur(x + 10, y + 1, ya);
          continue;
        }

        break;

      } else if (j == 1) {
        /// IL APUIYER SUR RESET
        goto RST;
      }
    } else if ((Q && ((c == 80) || (c == 81))) || (!Q && (c == 13)) ||
               (!Q && (c == 9))) {
      /// IL APUIYER SUR LE TOUCHE ENTREZ OU DOWN TAB
      if (i == Taille - 1) {
        /// DANS CE CAS ON UN BUTON A DESELECTIONNER
        AffichezButon(buton[j], a + ps[i][j], b + i * pas, 10, ColorDeselect);
      }
      i = (i + 1) % Taille; /// ON INCREMANTE I DE FACON NE DEPASSE PAS LE
                            /// NOMBRE DE UNPUTE A ENTREZ
      if (i == Taille - 1) {
        /// DANS CE CAS ON UN BUTON A SELECTIONNER
        j = 0;
        AffichezButon(buton[j], a + ps[i][j], b + i * pas, 10, ColorSelect);
      } else if (i != 4)
        j = Min(j, saiser[i]); /// ON CHANGE LE VALAUR DE J SI IL DEPASSE LE
                               /// NOMBRE DE CARACTERE QUI SONT SAISER
      else
        j = 0;
    } else if (Q && ((c == 72) || (c == 73))) {
      /// IL APPUIYER SUR UP
      if (i == Taille - 1) { /// DANS CE CAS ON UN BUTON A DESELECTIONNER
        AffichezButon(buton[j], a + ps[i][j], b + i * pas, 10, ColorDeselect);
      }
      i = (i + Taille - 1) % Taille; /// ON DECREMANTE I DE FACON NE DEPASSE PAS
                                     /// LE NOMBRE DE UNPUTE A ENTREZ
      if (i == Taille - 1) {         /// DANS CE CAS ON UN BUTON A SELECTIONNER
        j = 0;
        AffichezButon(buton[j], a + ps[i][j], b + i * pas, 10, ColorSelect);
      } else if (i != 4)
        j = Min(j, saiser[i]); /// ON CHANGE LE VALAUR DE J SI IL DEPASSE LE
                               /// NOMBRE DE CARACTERE QUI SONT SAISER
      else
        j = 0;
    } else if (Q && (c == 75)) {
      /// IL APUIYER SUR LEFT
      if (i == Taille - 1) {
        AffichezButon(
            buton[j], a + ps[i][j], b + i * pas, 10,
            ColorDeselect); /// DANS CE CAS ON UN BUTON A DESELECTIONNER j
        j = (j + saiser[i] - 1) % (saiser[i]);
        AffichezButon(buton[j], a + ps[i][j], b + i * pas, 10, ColorSelect);
      } else
        j = (j + saiser[i]) %
            (saiser[i] + 1); /// ON DECREMANTE J DE FACON NE DEPASSE PAS LE
                             /// NOMBRE DE CARACTERE QUI SONT SAISER

    } else if (Q && (c == 77)) {
      /// IL APUIYER SUR RIGHT
      if (i == Taille - 1) {
        AffichezButon(
            buton[j], a + ps[i][j], b + i * pas, 10,
            ColorDeselect); /// DANS CE CAS ON UN BUTON A DESELECTIONNER j
        j = (j + saiser[i] + 1) % (saiser[i]);
        AffichezButon(buton[j], a + ps[i][j], b + i * pas, 10, ColorSelect);
      } else
        j = (j + 1) %
            (saiser[i] + 1); /// ON INCREMANTE J DE FACON NE DEPASSE PAS LE
                             /// NOMBRE DE CARACTERE QUI SONT SAISER

    } else if (Q && (c == 71)) {
      /// IL APUIYER SUR DEBUT DE LINE
      j = 0; /// ON DEPELACE LE CURSEUR A LA DEBUT DE LA LINE

    } else if (Q && (c == 79)) {
      /// IL APUIYER SUR FIN DE LINE
      j = saiser[i]; /// ON DEPELACE LE CURSEUR A LA FIN DE LA PHRASE
    } else if (i == 4) {
      if ((Q && (c == 83)) || (!Q && (c == 8))) {
        /// IL APUIYER SUR SUPPRIMER
        if (j > 0) {
          j--; /// ON DECREMANTE J DE FACON NE DEPASSE PAS LE NOMBRE DE
               /// CARACTERE QUI SONT SAISER
          Info[i][j] = '0'; /// ON REMPLACE LA CARACTERE DANS CHAINE INFO[I] A
                            /// LA POSTION J PAR 0
          cputcxyBlanc(a, b + i * pas, Info[i], saiser[i],
                       &(ps[i][0])); /// ON ECRIT LE CHAINE DANS ECRAN
        } else
          printf("%c", 7); /// ON PEUT PAS SUPRIMER ON INVERTER LE UTILISATAURE
                           /// AVEC UN SON

      } else if ((!Q) && (isdigit(c))) {
        /// IL C NUMERIQUE
        if (j < saiser[i]) {
          Info[i][j] = c; /// ON SAUVERGERDE LA CARACTERE DANS CHAINE INFO[I] A
                          /// LA POSTION J
          cputcxyBlanc(a, b + i * pas, Info[i], saiser[i],
                       &(ps[i][0])); /// ON ECRIT LE CHAINE DANS ECRAN
          j++; /// ON INCREMANTE J DE FACON NE DEPASSE PAS LE NOMBRE DE
               /// CARACTERE QUI SONT SAISER
        } else
          printf(
              "%c",
              7); /// ON PEUT PAS SAISER ON INVERTER LE UTILISATAURE AVEC UN SON
      }

    } else if ((Q && (c == 83)) || (!Q && (c == 8))) {
      /// IL APUIYER SUR SUPPRIMER
      if (j > 0) {
        j--; /// ON DECREMANTE J DE FACON NE DEPASSE PAS LE NOMBRE DE CARACTERE
             /// QUI SONT SAISER
        SupprimerChar(
            Info[i], saiser[i],
            j); /// ON SUPPRIME LA CARACTERE DANS CHAINE INFO[I] A LA POSTION J
        cputsxyBlanc(a + j, b + i * pas, &(Info[i][j]),
                     Lm[i] - j); /// ON ECRIT LE CHAINE DANS ECRAN
        saiser[i]--;             /// ON DECREMANTE LE NOMBRE DES A SAISER

      } else
        printf("%c", 7); /// ON PEUT PAS SUPPRIMER ON INVERTER LE UTILISATAURE
                         /// AVEC UN SON

    } else if ((!Q) && (((i != 3) && (isalnum(c) || c == 32)) ||
                        ((i == 3) && (isdigit(c))))) {
      /// SI LE SAISER DE DIFFIRENT DE NUMERO DE TELEPHONE C CARACTERE
      /// ALPHAPTIQUE OU NUMERIQUE OU BLANC SINON LE CARACTERE NUMERIQUE
      if (saiser[i] < Lm[i]) {
        if ((c != 32) || ((c == 32) && (j > 0) && (Info[i][j - 1] != 32) &&
                          (Info[i][j] != 32))) {
          /// ON FAIT CONDITION SI IL YA UN ESPACE BLANC DEJA POUR N'EST PAS LE
          /// REPRTER
          c = (islower(c)) ? c - 32 : c; /// ON TRANFER LES LETTRE EN MAJUSQUILE
          AjoutezChar(Info[i], saiser[i], j,
                      c); /// ON SAUVERGERDE LA CARACTERE DANS CHAINE INFO[I] A
                          /// LA POSTION J
          cputsxyBlanc(a + j, b + i * pas, &(Info[i][j]),
                       Lm[i] - j); /// ON ECRIT LE CHAINE DANS ECRAN
          saiser[i]++;             /// ON INCREMANTE LE NOMBRE DES A SAISER
          j++; /// ON INCREMANTE J DE FACON NE DEPASSE PAS LE NOMBRE DE
               /// CARACTERE QUI SONT SAISER
        }
      } else
        printf(
            "%c",
            7); /// ON PEUT PAS SAISER ON INVERTER LE UTILISATAURE AVEC UN SON
    }
    if (c == -32)
      Q = true;
    else
      Q = false;
  } while (1);
  /// ON SAUVERGEDE LES INFORMATION DANS UN MAILLON
  maillon_Emprunteur *P;
  allouer_Emprunteur(&P);
  sprintf(P->nom, "%s", Info[0]);
  sprintf(P->prenom, "%s", Info[1]);
  sprintf(P->adresseActuelle, "%s", Info[2]);
  sprintf(P->nDeTelephone, "%s", Info[3]);
  P->penaliterTotal = 0;
  P->dateDeInscription.days = Days;
  P->dateDeInscription.month = Month;
  P->dateDeInscription.years = Years;
  P->ordreInscription = longeur_Emprunteur(*Tete) + 1;
  P->Emprunt = NULL;
  P->Emprunter = 0;
  P->NbreDeEmprunt = 0;
  P->penaliter = 0;
  ///  ON AFFICHE LES INFORMATIONS QUI SONT SAISER DANS ECRAN POUR CONFERMER QUI
  ///  N'EST PAS ERREUR
  resetcolor();
  system("CLS");
  AffichezCadre(19, 1, 82, 6, 35, ColorCadre2);
  cputsxych(
      22, 3,
      "C'EST LES INFORMATION SONT CORRECT APUIYER SUR ENTRER POR SAUVERGERDER");
  cputsxych(22, 4,
            "SINON APUIYER SUR ECHAP POUR RETOURNER EN ARREIRE POUR REINSCRIT");
  Afficher_Emprunteur(P, 20, 8, 80, 50, ColorCadre);
  do {
    c = getch();
  } while ((c != 13) && (c != 8) && (c != 27));
  system("CLS");
  if (c != 13) {
    liberer_Emprunteur(&P);
    goto debut;
  }
  aff_adr_Emprunteur(P, *Tete);
  *Tete = P;
  cputsxych(22, 3, "LES INSCRIPTION EST TERMINER AVEC SECCES MERCI ...");
  c = getch();
FG:
  resetcolor();
}
void AjoutezUnLivre(maillon_Livre **Tete) {

  /** AJOUTEZ UN LIVRE DANS LA LISTE
   ** LIRE LES INFORMATION DES ENTRES DES UTILISATAURE ET ET SAUVEGARDEZ DANS LA
   *LISTE
   ** FAIRE LE CONTROLER POUR POUR LES ENTRES DE UTILISATAURE
   ** DONNEZ A L'UTILISATAUR LA POSSIBELITER DE MODIFIER ET SUPPRIMER
   ** DONNEZ A L'UTILISATAUR DEUX BUTTON POUR SAUVERGERDEZ ET POUR RESTARER
   **/

  int Taille = 15, i, j, Lm[15] = {20,  40,  40,  40,  8,   50,  100, 100,
                                   100, 100, 100, 100, 100, 100, 1};
  int ps[15][110];
  char *Mot[] = {"COTE ",         "TITRE ",   "AUTEUR ", "EDITEUR ",
                 "DATE EDITION ", "MOT CLE ", "RESUME "};
  int Years = 2000, Days = 1, Month = 1;
  int Date = Years + (Month + Days * 100) * 10000;
  char *buton[2] = {"Save", "Reset"};
  int x = 20, y = 5, lg = 140, ht = 40;
debut:
  textbackground(colorbackground);
  system("CLS");
  AffichezCadre(x - 1, y - 1, lg + 2, ht + 2, 5, colorText);

  // AffichezPage(x,y,lg,ht,colorbackground);
  int pa = ht / (Taille - 2), a = x + 20, b = y + 5;
  int pas[15];
  for (i = 0; i < Taille - 1; i++)
    pas[i] = pa * i;
  for (i = 1; i < 8; i++)
    pas[6 + i] = pas[6] + i;
  pas[Taille - 1] = pas[Taille - 2] + pa + 2;
  textcolor(ColorDeTitre);
  for (i = 0; i < 7; i++) {
    gotoxy(x + 5, b + pas[i]);
    printf("%s\t: ", Mot[i]);
  }
RST: /// C'EST ICI LE RETOURE DE GOTO C'EST IL AUIYER SUR LE BUTON RESET
     /// AFFICHEZ DE UNPUT DE ENTREZ
  textcolor(colorText);
  textbackground(ColorInput);
  for (i = 0; i < 7; i++) {
    if ((i == 4) || (i == 6))
      continue;
    cputsxyBlanc(a, b + pas[i] - 1, " ", Lm[i]);
    cputsxyBlanc(a, b + pas[i], " ", Lm[i]);
  }
  cputsxyBlanc(a, b + pas[6] - 1, " ", Lm[6]);
  for (i = 6; i < 14; i++)
    cputsxyBlanc(a, b + pas[i], " ", Lm[i]);
  cputsxyBlanc(a, b + pas[13] + 1, " ", Lm[13]);
  for (i = 0; i < 15; i++)
    for (j = 0; j < 110; j++)
      ps[i][j] = j;
  char Info[15][110] = {""};
  textbackground(colorbackgroundDate);
  textcolor(colorTexteDate);
  AffichezInputDate(a, b + pas[4], &(ps[4][0]));
  colorbackground = ColorInput;
  textbackground(colorbackground);
  colorText = ColorTextInput;
  textcolor(colorText);
  j = Date;
  for (i = 7; i >= 0; i--) {
    /// ON TRANFORM LA DATE EN CHAINE DE CARACTERE
    Info[4][i] = j % 10 + '0';
    j /= 10;
  }
  Info[4][8] = 0;
  cputcxyBlanc(a, b + pas[4], Info[4], 8,
               &(ps[4][0])); /// ON ECRIT LE CHAINE DE CARACTERE
  int saiser[15] = {0};
  saiser[4] = 8;
  saiser[Taille - 1] = 2;
  ps[Taille - 1][0] = 0;
  ps[Taille - 1][1] = 20;
  for (j = 0; j < 2; j++)
    AffichezButon(buton[j], a + ps[Taille - 1][j], b + pas[Taille - 1], 10,
                  ColorDeselect); /// AFFICHEZ DEUX BUTTON A L'ECRAN
  int Q = false;
  char c, po[20], resum[700];
  ;
  i = 0;
  j = 0;
  do {
    gotoxy(a + ps[i][j], b + pas[i]);
    c = getch();
    if ((!Q) && (c == 27))
      goto FG;
    if ((i == Taille - 1) && (!Q) && (c == 13)) {
      /// ALORS ICI IL APUIYER SUR UN BUTON
      textbackground(ColorSup); /// ON SUPPRIMER LE ANCIEN MESSAGE SI IL EXISTE
      cputsxyBlanc(x, y, " ", lg);
      cputsxyBlanc(x, y + 1, " ", lg);
      textbackground(colorbackground);
      if (j == 0) {
        /// IL APUIYER SUR SAVE
        int rep = true, k;
        for (k = 0; k < 7; k++) {
          if (saiser[k] == 0) {
            rep = false;
            /// SI IL YA UN CASE VIDE ON SIGNALE UN ERREUR
            AffichezErreur(x + 20, y + 1, " TU DOIS REMLIRE TOUS LES CASES ");
            break;
          }
        }
        if (!rep)
          continue;
        char ya[100];
        sprintf(ya, "%s", &(Info[4][4]));
        Years = strtol(ya, NULL, 10);
        if ((Years < 1900) || (Years > 2016)) {
          /// SI LE DATE YEARS < 1900 OU > 2016 ON SIGNALE UN ERREUR
          AffichezErreur(x + 20, y + 1,
                         " LA DATE YEARS IL DOIT ENTRE 1900 .. 2016 ");
          continue;
        }
        sprintf(ya, "%c%c", Info[4][2], Info[4][3]);
        Month = strtol(ya, NULL, 10);
        if ((Month < 1) || (Month > 12)) {
          /// SI LE DATE MONTH INCORECT ON SIGNALE UN ERREUR
          AffichezErreur(x + 20, y + 1,
                         " LA DATE MONTHE EST INCORECT IL DOIT ENTRE 1 .. 12 ");
          continue;
        }
        sprintf(ya, "%c%c", Info[4][0], Info[4][1]);
        Days = strtol(ya, NULL, 10);
        k = MaxJour(Years, Month);
        if ((Days < 1) || (Days > k)) {
          sprintf(
              ya,
              " LA NEMERO DE JOUR EST INCORECT IL DOIT COMPRIT ENTRE 1 .. %d ",
              k);
          /// SI LE DATE DAYS INCORECT ON SIGNALE UN ERREUR
          AffichezErreur(x + 20, y + 1, ya);
          continue;
        }
        int Tai = NbreMot(Info[5]);
        if (Tai > 5) {
          /// SI LE NOMBRE DES MOT CLE DEPPASSE 5
          AffichezErreur(x + 20, y + 1, " LE NOMBRE DES MOT CLE 5 AU MAXIMUM ");
          continue;
        }
        sprintf(resum, "%s %s %s %s %s %s", Info[6], Info[7], Info[8], Info[9],
                Info[10], Info[11], Info[12], Info[13]);
        if (NbreMot(resum) > 100) {
          /// SI LE NOMBRE DES MOT DE RESUME DEPPASSE 100
          AffichezErreur(x + 20, y + 1,
                         " LE NOMBRE DES MOT DE RESUME 100 AU MAXIMUM ");
          continue;
        }
        char *rh[20], sauv[30];
        DecopPhrase(&(Info[5][0]), rh, &Tai);
        rep = true;
        for (k = 0; k < Tai; k++) {
          if (strstrcase(resum, rh[k]) == 0) {
            rep = false;
            /// LA MOT K+1 N'EXISTE PAS DANS LE RESUME
            sprintf(ya,
                    " LA MOT %d N'EXISTE PAS DANS LE RESUME IL DOIT TOUS LES "
                    "MOT CLE EXISTE",
                    k + 1);
            AffichezErreur(x + 20, y + 1, ya);
            break;
          }
        }
        if (!rep)
          continue;
        if (RechachezUnCote_Livre(*Tete, strtol(Info[0], NULL, 10))) {
          AffichezErreur(x + 20, y + 1, " CE NUMERO DE COTE EXSITE DEJA ");
          continue;
        }
        break;

      } else if (j == 1) {
        /// IL APUIYER SUR RESET
        goto RST;
      }
    } else if ((Q && ((c == 80) || (c == 81))) || (!Q && (c == 13)) ||
               (!Q && (c == 9))) {
      /// IL APUIYER SUR LE TOUCHE ENTREZ OU DOWN TAB
      if (i == Taille - 1) {
        /// DANS CE CAS ON UN BUTON A DESELECTIONNER
        AffichezButon(buton[j], a + ps[i][j], b + pas[i], 10, ColorDeselect);
      }
      do {
        i = (i + 1) % Taille; /// ON INCREMANTE I DE FACON NE DEPASSE PAS LE
                              /// NOMBRE DE UNPUTE A ENTREZ
      } while ((c != 13) && (i < 14) && (i > 6) && (saiser[i] == 0));
      if (i == Taille - 1) {
        /// DANS CE CAS ON UN BUTON A SELECTIONNER
        j = 0;
        AffichezButon(buton[j], a + ps[i][j], b + pas[i], 10, ColorSelect);
      } else if (i != 4)
        j = Min(j, saiser[i]); /// ON CHANGE LE VALAUR DE J SI IL DEPASSE LE
                               /// NOMBRE DE CARACTERE QUI SONT SAISER
      else
        j = 0;
    } else if (Q && ((c == 72) || (c == 73))) {
      /// IL APPUIYER SUR UP
      if (i == Taille - 1) { /// DANS CE CAS ON UN BUTON A DESELECTIONNER
        AffichezButon(buton[j], a + ps[i][j], b + pas[i], 10, ColorDeselect);
      }
      do {
        i = (i + Taille - 1) % Taille; /// ON DECREMANTE I DE FACON NE DEPASSE
                                       /// PAS LE NOMBRE DE UNPUTE A ENTREZ
      } while ((i < 14) && (i > 6) && (saiser[i] == 0));
      if (i == Taille - 1) { /// DANS CE CAS ON UN BUTON A SELECTIONNER
        j = 0;
        AffichezButon(buton[j], a + ps[i][j], b + pas[i], 10, ColorSelect);
      } else if (i != 4)
        j = Min(j, saiser[i]); /// ON CHANGE LE VALAUR DE J SI IL DEPASSE LE
                               /// NOMBRE DE CARACTERE QUI SONT SAISER
      else
        j = 0;
    } else if (Q && (c == 75)) {
      /// IL APUIYER SUR LEFT
      if (i == Taille - 1) {
        AffichezButon(
            buton[j], a + ps[i][j], b + pas[i], 10,
            ColorDeselect); /// DANS CE CAS ON UN BUTON A DESELECTIONNER j
        j = (j + saiser[i] - 1) % (saiser[i]);
        AffichezButon(buton[j], a + ps[i][j], b + pas[i], 10, ColorSelect);
      } else
        j = (j + saiser[i]) %
            (saiser[i] + 1); /// ON DECREMANTE J DE FACON NE DEPASSE PAS LE
                             /// NOMBRE DE CARACTERE QUI SONT SAISER

    } else if (Q && (c == 77)) {
      /// IL APUIYER SUR RIGHT
      if (i == Taille - 1) {
        AffichezButon(
            buton[j], a + ps[i][j], b + pas[i], 10,
            ColorDeselect); /// DANS CE CAS ON UN BUTON A DESELECTIONNER j
        j = (j + saiser[i] + 1) % (saiser[i]);
        AffichezButon(buton[j], a + ps[i][j], b + pas[i], 10, ColorSelect);
      } else
        j = (j + 1) %
            (saiser[i] + 1); /// ON INCREMANTE J DE FACON NE DEPASSE PAS LE
                             /// NOMBRE DE CARACTERE QUI SONT SAISER

    } else if (Q && (c == 71)) {
      /// IL APUIYER SUR DEBUT DE LINE
      j = 0; /// ON DEPELACE LE CURSEUR A LA DEBUT DE LA LINE

    } else if (Q && (c == 79)) {
      /// IL APUIYER SUR FIN DE LINE
      j = saiser[i]; /// ON DEPELACE LE CURSEUR A LA FIN DE LA PHRASE
    } else if (i == 4) {
      if ((Q && (c == 83)) || (!Q && (c == 8))) {
        /// IL APUIYER SUR SUPPRIMER
        if (j > 0) {
          j--; /// ON DECREMANTE J DE FACON NE DEPASSE PAS LE NOMBRE DE
               /// CARACTERE QUI SONT SAISER
          Info[i][j] = '0'; /// ON REMPLACE LA CARACTERE DANS CHAINE INFO[I] A
                            /// LA POSTION J PAR 0
          cputcxyBlanc(a, b + pas[i], Info[i], saiser[i],
                       &(ps[i][0])); /// ON ECRIT LE CHAINE DANS ECRAN
        } else
          printf("%c", 7); /// ON PEUT PAS SUPRIMER ON INVERTER LE UTILISATAURE
                           /// AVEC UN SON

      } else if ((!Q) && (isdigit(c))) {
        /// IL C NUMERIQUE
        if (j < saiser[i]) {
          Info[i][j] = c; /// ON SAUVERGERDE LA CARACTERE DANS CHAINE INFO[I] A
                          /// LA POSTION J
          cputcxyBlanc(a, b + pas[i], Info[i], saiser[i],
                       &(ps[i][0])); /// ON ECRIT LE CHAINE DANS ECRAN
          j++; /// ON INCREMANTE J DE FACON NE DEPASSE PAS LE NOMBRE DE
               /// CARACTERE QUI SONT SAISER
        } else
          printf(
              "%c",
              7); /// ON PEUT PAS SAISER ON INVERTER LE UTILISATAURE AVEC UN SON
      }

    } else if ((Q && (c == 83)) || (!Q && (c == 8))) {
      /// IL APUIYER SUR SUPPRIMER
      if (j > 0) {
        j--; /// ON DECREMANTE J DE FACON NE DEPASSE PAS LE NOMBRE DE CARACTERE
             /// QUI SONT SAISER
        SupprimerChar(
            Info[i], saiser[i],
            j); /// ON SUPPRIME LA CARACTERE DANS CHAINE INFO[I] A LA POSTION J
        cputsxyBlanc(a + j, b + pas[i], &(Info[i][j]),
                     Lm[i] - j); /// ON ECRIT LE CHAINE DANS ECRAN
        saiser[i]--;             /// ON DECREMANTE LE NOMBRE DES A SAISER
      } else
        printf("%c", 7); /// ON PEUT PAS SUPPRIMER ON INVERTER LE UTILISATAURE
                         /// AVEC UN SON

    } else if ((!Q) &&
               ((((i == 2) || (i == 3)) && ((isalnum(c)) || (c == 32))) ||
                ((i == 0) && (isdigit(c))) ||
                (((i == 1) || (i > 4)) && (isprint(c))))) {
      if (saiser[i] < Lm[i]) {
        if ((c != 32) || ((c == 32) && (j > 0) && (Info[i][j - 1] != 32) &&
                          (Info[i][j] != 32))) {
          /// ON FAIT CONDITION SI IL YA UN ESPACE BLANC DEJA POUR N'EST PAS LE
          /// REPRTER
          if ((i == 2) || (i == 3)) {
            c = (islower(c)) ? c - 32 : c;
          } /// ON TRANFER LES LETTRE EN MAJUSQUILE
          AjoutezChar(Info[i], saiser[i], j,
                      c); /// ON SAUVERGERDE LA CARACTERE DANS CHAINE INFO[I] A
                          /// LA POSTION J
          cputsxyBlanc(a + j, b + pas[i], &(Info[i][j]),
                       Lm[i] - j); /// ON ECRIT LE CHAINE DANS ECRAN
          saiser[i]++;             /// ON INCREMANTE LE NOMBRE DES A SAISER
          j++; /// ON INCREMANTE J DE FACON NE DEPASSE PAS LE NOMBRE DE
               /// CARACTERE QUI SONT SAISER
        }
      } else
        printf(
            "%c",
            7); /// ON PEUT PAS SAISER ON INVERTER LE UTILISATAURE AVEC UN SON
    }
    if (c == -32)
      Q = true;
    else
      Q = false;
  } while (1);
  /// ON SAUVERGEDE LES INFORMATION DANS UN MAILLON
  maillon_Livre *P;
  allouer_Livre(&P);
  P->cote = strtol(Info[0], NULL, 10);
  sprintf(P->titre, "%s", Info[1]);
  sprintf(P->auteur, "%s", Info[2]);
  sprintf(P->editeur, "%s", Info[3]);
  P->dateEdition.days = Days;
  P->dateEdition.month = Month;
  P->dateEdition.years = Years;
  sprintf(P->motCle, "%s", Info[5]);
  sprintf(P->resume, "%s", resum);
  P->nbrDeEmprunt = 0;
  P->Emprunt = NULL;
  P->disponible = 1;
  ///  ON AFFICHE LES INFORMATIONS QUI SONT SAISER DANS ECRAN POUR CONFERMER QUI
  ///  N'EST PAS ERREUR
  resetcolor();
  system("CLS");
  AffichezCadre(10, 1, 122, 6, 35, ColorCadre);
  cputsxych(12, 3,
            "C'EST LES INFORMATION SONT CORRECT APUIYER SUR ENTRER POUR "
            "SAUVERGARDER");
  cputsxych(12, 4, "SINON APUIYER SUR ECHAP POUR RETOURNER EN ARREIRE ");
  Afficher_Livre(P, 10, 8, 120, 40, ColorCadre2);
  do {
    c = getch();
  } while ((c != 13) && (c != 8) && (c != 27));
  system("CLS");
  if (c != 13) {
    liberer_Livre(&P);
    goto debut;
  }
  aff_adr_Livre(P, *Tete);
  *Tete = P;
  cputsxych(42, 3, "LES AJOUTATION EST TERMINER AVEC SECCES MERCI ...");
  c = getch();
FG:
  resetcolor();
}
void EmprunterUnLivre(maillon_Emprunt **Tete, maillon_Livre **Livre,
                      maillon_Emprunteur **Emprunteur) {

  /** EMPRUNTER UN LIVRE DANS LA LISTE
   ** LIRE LES INFORMATION DES ENTRES DES UTILISATAURE ET ET SAUVEGARDEZ DANS LA
   *LISTE
   ** FAIRE LE CONTROLER POUR POUR LES ENTRES DE UTILISATAURE
   ** DONNEZ A L'UTILISATAUR LA POSSIBELITER DE MODIFIER ET SUPPRIMER
   ** DONNEZ A L'UTILISATAUR DEUX BUTTON POUR SAUVERGERDEZ ET POUR RESTARER
   **/

  int Taille = 4, i, j, Lm[5] = {20, 20, 8, 1};
  maillon_Livre *PLivre = NULL;
  maillon_Emprunteur *PEmprunteur = NULL;
  int ps[5][110];
  char *Mot[] = {
      "COTE ",
      "CODE EMPRUNTEUR ",
      "DATE DE L'EMPRUNTE ",
  };
  time_t tk;
  struct tm *TimeActeul;
  time(&tk);                   /// ON LIT LE DATE DE PC
  TimeActeul = localtime(&tk); /// ON LES CONVERTIRE
  int Years = TimeActeul->tm_year + 1900, Days = TimeActeul->tm_mday,
      Month = TimeActeul->tm_mon + 1;
  int Date = Years + (Month + Days * 100) * 10000;
  char *buton[2] = {"Save", "Reset"};
  int x = 40, y = 5, lg = 80, ht = 40, pos1, pos2;
debut:
  AffichezPage(x, y, lg, ht, colorbackground);
  AffichezCadre(x - 1, y - 1, lg + 2, ht + 2, 5, colorText);

  int pa = ht / (Taille + 1), a = x + 30, b = y + 4;
  int pas[5];
  for (i = 0; i < Taille; i++)
    pas[i] = pa * i;
  textcolor(ColorDeTitre);
  for (i = 0; i < Taille - 1; i++) {
    gotoxy(x + 5, b + pas[i]);
    printf("%s\t: ", Mot[i]);
  }
RST: /// C'EST ICI LE RETOURE DE GOTO C'EST IL AUIYER SUR LE BUTON RESET
  /// AFFICHEZ DE UNPUT DE ENTREZ
  textcolor(colorText);
  textbackground(ColorInput);
  for (i = 0; i < Taille - 1; i++) {
    if (i == 2)
      continue;
    cputsxyBlanc(a, b + pas[i] - 1, " ", Lm[i]);
    cputsxyBlanc(a, b + pas[i], " ", Lm[i]);
  }
  for (i = 0; i < 5; i++)
    for (j = 0; j < 110; j++)
      ps[i][j] = j;
  char Info[5][110] = {""};
  textbackground(colorbackgroundDate);
  textcolor(colorTexteDate);
  AffichezInputDate(a, b + pas[2], &(ps[2][0]));
  colorbackground = ColorInput;
  textbackground(colorbackground);
  colorText = ColorTextInput;
  textcolor(colorText);
  j = Date;
  for (i = 7; i >= 0; i--) {
    /// ON TRANFORM LA DATE EN CHAINE DE CARACTERE
    Info[2][i] = j % 10 + '0';
    j /= 10;
  }
  Info[2][8] = 0;
  cputcxyBlanc(a, b + pas[2], Info[2], 8,
               &(ps[2][0])); /// ON ECRIT LE CHAINE DE CARACTERE
  int saiser[5] = {0};
  saiser[2] = 8;
  saiser[Taille - 1] = 2;
  ps[Taille - 1][0] = 0;
  ps[Taille - 1][1] = 20;
  for (j = 0; j < 2; j++)
    AffichezButon(buton[j], a + ps[Taille - 1][j], b + pas[Taille - 1], 10,
                  ColorDeselect); /// AFFICHEZ DEUX BUTTON A L'ECRAN
  int Q = false;
  char c, po[20];
  i = 0;
  j = 0;
  do {
    gotoxy(a + ps[i][j], b + pas[i]);
    c = getch();
    if ((!Q) && (c == 27))
      goto FG;
    if ((i == Taille - 1) && (!Q) && (c == 13)) {
      /// ALORS ICI IL APUIYER SUR UN BUTON
      textbackground(ColorSup); /// ON SUPPRIMER LE ANCIEN MESSAGE SI IL EXISTE
      cputsxyBlanc(x, y, " ", lg);
      cputsxyBlanc(x, y + 1, " ", lg);
      textbackground(colorbackground);
      if (j == 0) {
        /// IL APUIYER SUR SAVE
        int rep = true, k;
        for (k = 0; k < Taille - 2; k++) {
          if (saiser[k] == 0) {
            rep = false;
            /// SI IL YA UN CASE VIDE ON SIGNALE UN ERREUR
            AffichezErreur(x + 20, y + 1, " TU DOIS REMLIRE TOUS LES CASES ");
            break;
          }
        }
        if (!rep)
          continue;
        char ya[100];
        sprintf(ya, "%s", &(Info[2][4]));
        Years = strtol(ya, NULL, 10);
        if ((Years < 2000) || (Years > 2100)) {
          /// SI LE DATE YEARS < 2000 OU > 2100 ON SIGNALE UN ERREUR
          AffichezErreur(x + 20, y + 1,
                         " LA DATE YEARS IL DOIT ENTRE 2000 .. 2100 ");
          continue;
        }
        sprintf(ya, "%c%c", Info[2][2], Info[2][3]);
        Month = strtol(ya, NULL, 10);
        if ((Month < 1) || (Month > 12)) {
          /// SI LE DATE MONTH INCORECT ON SIGNALE UN ERREUR
          AffichezErreur(x + 20, y + 1,
                         " LA DATE MONTHE EST INCORECT IL DOIT ENTRE 1 .. 12 ");
          continue;
        }
        sprintf(ya, "%c%c", Info[2][0], Info[2][1]);
        Days = strtol(ya, NULL, 10);
        k = MaxJour(Years, Month);
        if ((Days < 1) || (Days > k)) {
          sprintf(
              ya,
              " LA NEMERO DE JOUR EST INCORECT IL DOIT COMPRIT ENTRE 1 .. %d ",
              k);
          /// SI LE DATE DAYS INCORECT ON SIGNALE UN ERREUR
          AffichezErreur(x + 20, y + 1, ya);
          continue;
        }
        pos1 = RechachezUnCote_Livre(*Livre, strtol(Info[0], NULL, 10));
        if (!pos1) {
          AffichezErreur(x + 20, y + 1, " CE NUMERO DE COTE N'EXSITE PAS ");
          continue;
        }
        pos2 = RechachezUnOrdreInscription_Emprunteur(
            *Emprunteur, strtol(Info[1], NULL, 10));
        if (!pos1) {
          AffichezErreur(x + 20, y + 1,
                         " CETTE ORDRE D'INSCRIPTION  N'EXSITE PAS ");
          continue;
        }
        PLivre = AccPos1_Livre(pos1, *Livre);
        if (!(PLivre->disponible)) {
          AffichezErreur(x + 20, y + 1, " CETTE LIVRE N'EST PAS DISPONIBLE ");
          continue;
        }
        PEmprunteur = AccPos1_Emprunteur(pos2, *Emprunteur);
        if (PEmprunteur->Emprunt) {
          AffichezErreur(
              x + 15, y + 1,
              " VOUS AVAIS DEJA EMPRUNTER UN LIVRE ET VOUS N'AVAIS PAS RENDER");
          continue;
        }
        if ((PEmprunteur->penaliter) > 0) {
          sprintf(ya, "VOUS ETE DEJA BLOQUER REVIEN APRES %d JOURS",
                  PEmprunteur->penaliter);
          AffichezErreur(x + 15, y + 1, ya);
          continue;
        }

        break;

      } else if (j == 1) {
        /// IL APUIYER SUR RESET
        goto RST;
      }
    } else if ((Q && ((c == 80) || (c == 81))) || (!Q && (c == 13)) ||
               (!Q && (c == 9))) {
      /// IL APUIYER SUR LE TOUCHE ENTREZ OU DOWN TAB
      if (i == Taille - 1) {
        /// DANS CE CAS ON UN BUTON A DESELECTIONNER
        AffichezButon(buton[j], a + ps[i][j], b + pas[i], 10, ColorDeselect);
      }
      i = (i + 1) % Taille; /// ON INCREMANTE I DE FACON NE DEPASSE PAS LE
                            /// NOMBRE DE UNPUTE A ENTREZ
      if (i == Taille - 1) {
        /// DANS CE CAS ON UN BUTON A SELECTIONNER
        j = 0;
        AffichezButon(buton[j], a + ps[i][j], b + pas[i], 10, ColorSelect);
      } else if (i != 2)
        j = Min(j, saiser[i]); /// ON CHANGE LE VALAUR DE J SI IL DEPASSE LE
                               /// NOMBRE DE CARACTERE QUI SONT SAISER
      else
        j = 0;
    } else if (Q && ((c == 72) || (c == 73))) {
      /// IL APPUIYER SUR UP
      if (i == Taille - 1) { /// DANS CE CAS ON UN BUTON A DESELECTIONNER
        AffichezButon(buton[j], a + ps[i][j], b + pas[i], 10, ColorDeselect);
      }
      i = (i + Taille - 1) % Taille; /// ON DECREMANTE I DE FACON NE DEPASSE PAS
                                     /// LE NOMBRE DE UNPUTE A ENTREZ
      if (i == Taille - 1) {         /// DANS CE CAS ON UN BUTON A SELECTIONNER
        j = 0;
        AffichezButon(buton[j], a + ps[i][j], b + pas[i], 10, ColorSelect);
      } else if (i != 4)
        j = Min(j, saiser[i]); /// ON CHANGE LE VALAUR DE J SI IL DEPASSE LE
                               /// NOMBRE DE CARACTERE QUI SONT SAISER
      else
        j = 0;
    } else if (Q && (c == 75)) {
      /// IL APUIYER SUR LEFT
      if (i == Taille - 1) {
        AffichezButon(
            buton[j], a + ps[i][j], b + pas[i], 10,
            ColorDeselect); /// DANS CE CAS ON UN BUTON A DESELECTIONNER j
        j = (j + saiser[i] - 1) % (saiser[i]);
        AffichezButon(buton[j], a + ps[i][j], b + pas[i], 10, ColorSelect);
      } else
        j = (j + saiser[i]) %
            (saiser[i] + 1); /// ON DECREMANTE J DE FACON NE DEPASSE PAS LE
                             /// NOMBRE DE CARACTERE QUI SONT SAISER
    } else if (Q && (c == 77)) {
      /// IL APUIYER SUR RIGHT
      if (i == Taille - 1) {
        AffichezButon(
            buton[j], a + ps[i][j], b + pas[i], 10,
            ColorDeselect); /// DANS CE CAS ON UN BUTON A DESELECTIONNER j
        j = (j + saiser[i] + 1) % (saiser[i]);
        AffichezButon(buton[j], a + ps[i][j], b + pas[i], 10, ColorSelect);
      } else
        j = (j + 1) %
            (saiser[i] + 1); /// ON INCREMANTE J DE FACON NE DEPASSE PAS LE
                             /// NOMBRE DE CARACTERE QUI SONT SAISER

    } else if (Q && (c == 71)) {
      /// IL APUIYER SUR DEBUT DE LINE
      j = 0; /// ON DEPELACE LE CURSEUR A LA DEBUT DE LA LINE
    } else if (Q && (c == 79)) {
      /// IL APUIYER SUR FIN DE LINE
      j = saiser[i]; /// ON DEPELACE LE CURSEUR A LA FIN DE LA PHRASE
    } else if (i == 2) {
      if ((Q && (c == 83)) || (!Q && (c == 8))) {
        /// IL APUIYER SUR SUPPRIMER
        if (j > 0) {
          j--; /// ON DECREMANTE J DE FACON NE DEPASSE PAS LE NOMBRE DE
               /// CARACTERE QUI SONT SAISER
          Info[i][j] = '0'; /// ON REMPLACE LA CARACTERE DANS CHAINE INFO[I] A
                            /// LA POSTION J PAR 0
          cputcxyBlanc(a, b + pas[i], Info[i], saiser[i],
                       &(ps[i][0])); /// ON ECRIT LE CHAINE DANS ECRAN
        } else
          printf("%c", 7); /// ON PEUT PAS SUPRIMER ON INVERTER LE UTILISATAURE
                           /// AVEC UN SON

      } else if ((!Q) && (isdigit(c))) {
        /// IL C NUMERIQUE
        if (j < saiser[i]) {
          Info[i][j] = c; /// ON SAUVERGERDE LA CARACTERE DANS CHAINE INFO[I] A
                          /// LA POSTION J
          cputcxyBlanc(a, b + pas[i], Info[i], saiser[i],
                       &(ps[i][0])); /// ON ECRIT LE CHAINE DANS ECRAN
          j++; /// ON INCREMANTE J DE FACON NE DEPASSE PAS LE NOMBRE DE
               /// CARACTERE QUI SONT SAISER
        } else
          printf(
              "%c",
              7); /// ON PEUT PAS SAISER ON INVERTER LE UTILISATAURE AVEC UN SON
      }
    } else if ((Q && (c == 83)) || (!Q && (c == 8))) {
      /// IL APUIYER SUR SUPPRIMER
      if (j > 0) {
        j--; /// ON DECREMANTE J DE FACON NE DEPASSE PAS LE NOMBRE DE CARACTERE
             /// QUI SONT SAISER
        SupprimerChar(
            Info[i], saiser[i],
            j); /// ON SUPPRIME LA CARACTERE DANS CHAINE INFO[I] A LA POSTION J
        cputsxyBlanc(a + j, b + pas[i], &(Info[i][j]),
                     Lm[i] - j); /// ON ECRIT LE CHAINE DANS ECRAN
        saiser[i]--;             /// ON DECREMANTE LE NOMBRE DES A SAISER
      } else
        printf("%c", 7); /// ON PEUT PAS SUPPRIMER ON INVERTER LE UTILISATAURE
                         /// AVEC UN SON

    } else if ((!Q) && (isdigit(c))) {
      if (saiser[i] < Lm[i]) {
        AjoutezChar(Info[i], saiser[i], j,
                    c); /// ON SAUVERGERDE LA CARACTERE DANS CHAINE INFO[I] A LA
                        /// POSTION J
        cputsxyBlanc(a + j, b + pas[i], &(Info[i][j]),
                     Lm[i] - j); /// ON ECRIT LE CHAINE DANS ECRAN
        saiser[i]++;             /// ON INCREMANTE LE NOMBRE DES A SAISER
        j++; /// ON INCREMANTE J DE FACON NE DEPASSE PAS LE NOMBRE DE CARACTERE
             /// QUI SONT SAISER
      } else
        printf(
            "%c",
            7); /// ON PEUT PAS SAISER ON INVERTER LE UTILISATAURE AVEC UN SON
    }
    if (c == -32)
      Q = true;
    else
      Q = false;
  } while (1);
  /// ON SAUVERGEDE LES INFORMATION DANS UN MAILLON
  maillon_Emprunt *P;
  allouer_Emprunt(&P);
  P->Emprunteur = PEmprunteur;
  P->livreEmprunte = PLivre;
  P->livreRendu = 0;
  P->penaliter = 0;
  P->dateDeEmprunt.days = Days;
  P->dateDeEmprunt.month = Month;
  P->dateDeEmprunt.years = Years;
  DateDeRetour(&Days, &Month, &Years, 28);
  P->dateDeRetour.days = Days;
  P->dateDeRetour.month = Month;
  P->dateDeRetour.years = Years;
  ///  ON AFFICHE LES INFORMATIONS QUI SONT SAISER DANS ECRAN POUR CONFERMER QUI
  ///  N'EST PAS ERREUR
  resetcolor();
  system("CLS");
  AffichezCadre(19, 1, 122, 6, 35, ColorCadre);
  cputsxych(22, 3,
            "C'EST LES INFORMATION SONT CORRECT APUIYER SUR ENTRER POUR "
            "SAUVERGERDER");
  cputsxych(
      22, 4,
      "SINON APUIYER SUR ECHAP POUR RETOURNER EN ARREIRE POUR REEMPRUNTER");
  Afficher_Emprunt(P, 20, 8, 120, 40, ColorCadre2);
  do {
    c = getch();
  } while ((c != 13) && (c != 8) && (c != 27));
  system("CLS");
  if (c != 13) {
    liberer_Livre(&P);
    goto debut;
  }
  P->Emprunteur->Emprunter = 1;
  P->Emprunteur->Emprunt = P;
  P->livreEmprunte->disponible = 0;
  (P->livreEmprunte->nbrDeEmprunt)++;
  P->livreEmprunte->Emprunt = P;
  aff_adr_Emprunt(P, *Tete);
  *Tete = P;
  cputsxych(22, 3, "LE EMPRUNT EST TERMINER AVEC SECCES MERCI ...");
  c = getch();
FG:
  resetcolor();
}
void RendreUnLivre(maillon_Livre **Livre) {

  /** RENDRE UN LIVRE DANS LA LISTE
   ** LIRE LES INFORMATION DES ENTRES DES UTILISATAURE ET ET SAUVEGARDEZ DANS LA
   *LISTE
   ** FAIRE LE CONTROLER POUR POUR LES ENTRES DE UTILISATAURE
   ** DONNEZ A L'UTILISATAUR LA POSSIBELITER DE MODIFIER ET SUPPRIMER
   ** DONNEZ A L'UTILISATAUR DEUX BUTTON POUR SAUVERGERDEZ ET POUR RESTARER
   **/

  int Taille = 3, i, j, Lm[5] = {20, 8, 1};
  maillon_Livre *PLivre = NULL;
  maillon_Emprunteur *PEmprunteur = NULL;
  int ps[5][110];
  char *Mot[] = {
      "COTE ",
      "DATE DE RETOUR ",
  };
  time_t tk;
  struct tm *TimeActeul;
  time(&tk);                   /// ON LIT LE DATE DE PC
  TimeActeul = localtime(&tk); /// ON LES CONVERTIRE
  int Years = TimeActeul->tm_year + 1900, Days = TimeActeul->tm_mday,
      Month = TimeActeul->tm_mon + 1;
  int Date = Years + (Month + Days * 100) * 10000;
  char *buton[2] = {"Save", "Reset"};
  int x = 40, y = 5, lg = 80, ht = 20, pos1, pos2;
debut:
  AffichezPage(x, y, lg, ht, colorbackground);
  AffichezCadre(x - 1, y - 1, lg + 2, ht + 2, 5, colorText);

  int pa = ht / (Taille + 1), a = x + 30, b = y + 4;
  int pas[5];
  for (i = 0; i < Taille; i++)
    pas[i] = pa * i;
  textcolor(ColorDeTitre);
  for (i = 0; i < Taille - 1; i++) {
    gotoxy(x + 5, b + pas[i]);
    printf("%s\t: ", Mot[i]);
  }
RST: /// C'EST ICI LE RETOURE DE GOTO C'EST IL AUIYER SUR LE BUTON RESET
     /// AFFICHEZ DE UNPUT DE ENTREZ

  textcolor(colorText);
  textbackground(ColorInput);
  for (i = 0; i < Taille - 1; i++) {
    if (i == 1)
      continue;
    cputsxyBlanc(a, b + pas[i] - 1, " ", Lm[i]);
    cputsxyBlanc(a, b + pas[i], " ", Lm[i]);
  }
  for (i = 0; i < 5; i++)
    for (j = 0; j < 110; j++)
      ps[i][j] = j;
  char Info[5][110] = {""};
  textbackground(colorbackgroundDate);
  textcolor(colorTexteDate);
  AffichezInputDate(a, b + pas[1], &(ps[1][0]));
  colorbackground = ColorInput;
  textbackground(colorbackground);
  colorText = ColorTextInput;
  textcolor(colorText);
  j = Date;
  for (i = 7; i >= 0; i--) {
    /// ON TRANFORM LA DATE EN CHAINE DE CARACTERE
    Info[1][i] = j % 10 + '0';
    j /= 10;
  }
  Info[1][8] = 0;
  cputcxyBlanc(a, b + pas[1], Info[1], 8,
               &(ps[1][0])); /// ON ECRIT LE CHAINE DE CARACTERE
  int saiser[5] = {0};
  saiser[1] = 8;
  saiser[Taille - 1] = 2;
  ps[Taille - 1][0] = 0;
  ps[Taille - 1][1] = 20;
  for (j = 0; j < 2; j++)
    AffichezButon(buton[j], a + ps[Taille - 1][j], b + pas[Taille - 1], 10,
                  ColorDeselect); /// AFFICHEZ DEUX BUTTON A L'ECRAN
  int Q = false;
  char c, po[20];
  i = 0;
  j = 0;
  do {
    gotoxy(a + ps[i][j], b + pas[i]);
    c = getch();
    if ((!Q) && (c == 27))
      goto FG;
    if ((i == Taille - 1) && (!Q) && (c == 13)) {
      /// ALORS ICI IL APUIYER SUR UN BUTON
      textbackground(ColorSup); /// ON SUPPRIMER LE ANCIEN MESSAGE SI IL EXISTE
      cputsxyBlanc(x, y, " ", lg);
      cputsxyBlanc(x, y + 1, " ", lg);
      textbackground(colorbackground);
      if (j == 0) {
        /// IL APUIYER SUR SAVE
        int rep = true, k;
        for (k = 0; k < Taille - 2; k++) {
          if (saiser[k] == 0) {
            rep = false;
            /// SI IL YA UN CASE VIDE ON SIGNALE UN ERREUR
            AffichezErreur(x + 20, y + 1, " TU DOIS REMLIRE TOUS LES CASES ");
            break;
          }
        }
        if (!rep)
          continue;
        char ya[100];
        sprintf(ya, "%s", &(Info[1][4]));
        Years = strtol(ya, NULL, 10);
        if ((Years < 2000) || (Years > 2100)) {
          /// SI LE DATE YEARS < 2000 OU > 2100 ON SIGNALE UN ERREUR
          AffichezErreur(x + 20, y + 1,
                         " LA DATE YEARS IL DOIT ENTRE 2000 .. 2100 ");
          continue;
        }
        sprintf(ya, "%c%c", Info[1][2], Info[1][3]);
        Month = strtol(ya, NULL, 10);
        if ((Month < 1) || (Month > 12)) {
          /// SI LE DATE MONTH INCORECT ON SIGNALE UN ERREUR
          AffichezErreur(x + 20, y + 1,
                         " LA DATE MONTHE EST INCORECT IL DOIT ENTRE 1 .. 12 ");
          continue;
        }
        sprintf(ya, "%c%c", Info[1][0], Info[1][1]);
        Days = strtol(ya, NULL, 10);
        k = MaxJour(Years, Month);
        if ((Days < 1) || (Days > k)) {
          sprintf(
              ya,
              " LA NEMERO DE JOUR EST INCORECT IL DOIT COMPRIT ENTRE 1 .. %d ",
              k);
          /// SI LE DATE DAYS INCORECT ON SIGNALE UN ERREUR
          AffichezErreur(x + 20, y + 1, ya);
          continue;
        }
        pos1 = RechachezUnCote_Livre(*Livre, strtol(Info[0], NULL, 10));
        if (!pos1) {
          AffichezErreur(x + 20, y + 1, " CE NUMERO DE COTE N'EXSITE PAS ");
          continue;
        }
        PLivre = AccPos1_Livre(pos1, *Livre);
        if (PLivre->disponible == 1) {
          AffichezErreur(x + 20, y + 1, " CE LIVRE EST DEJA RENDER   ");
          continue;
        }
        break;

      } else if (j == 1) {
        /// IL APUIYER SUR RESET
        goto RST;
      }
    } else if ((Q && ((c == 80) || (c == 81))) || (!Q && (c == 13)) ||
               (!Q && (c == 9))) {
      /// IL APUIYER SUR LE TOUCHE ENTREZ OU DOWN TAB
      if (i == Taille - 1) {
        /// DANS CE CAS ON UN BUTON A DESELECTIONNER
        AffichezButon(buton[j], a + ps[i][j], b + pas[i], 10, ColorDeselect);
      }
      i = (i + 1) % Taille; /// ON INCREMANTE I DE FACON NE DEPASSE PAS LE
                            /// NOMBRE DE UNPUTE A ENTREZ
      if (i == Taille - 1) {
        /// DANS CE CAS ON UN BUTON A SELECTIONNER
        j = 0;
        AffichezButon(buton[j], a + ps[i][j], b + pas[i], 10, ColorSelect);
      } else if (i != 2)
        j = Min(j, saiser[i]); /// ON CHANGE LE VALAUR DE J SI IL DEPASSE LE
                               /// NOMBRE DE CARACTERE QUI SONT SAISER
      else
        j = 0;
    } else if (Q && ((c == 72) || (c == 73))) {
      /// IL APPUIYER SUR UP
      if (i == Taille - 1) { /// DANS CE CAS ON UN BUTON A DESELECTIONNER
        AffichezButon(buton[j], a + ps[i][j], b + pas[i], 10, ColorDeselect);
      }
      i = (i + Taille - 1) % Taille; /// ON DECREMANTE I DE FACON NE DEPASSE PAS
                                     /// LE NOMBRE DE UNPUTE A ENTREZ
      if (i == Taille - 1) {         /// DANS CE CAS ON UN BUTON A SELECTIONNER
        j = 0;
        AffichezButon(buton[j], a + ps[i][j], b + pas[i], 10, ColorSelect);
      } else if (i != 4)
        j = Min(j, saiser[i]); /// ON CHANGE LE VALAUR DE J SI IL DEPASSE LE
                               /// NOMBRE DE CARACTERE QUI SONT SAISER
      else
        j = 0;
    } else if (Q && (c == 75)) {
      /// IL APUIYER SUR LEFT
      if (i == Taille - 1) {
        AffichezButon(
            buton[j], a + ps[i][j], b + pas[i], 10,
            ColorDeselect); /// DANS CE CAS ON UN BUTON A DESELECTIONNER j
        j = (j + saiser[i] - 1) % (saiser[i]);
        AffichezButon(buton[j], a + ps[i][j], b + pas[i], 10, ColorSelect);
      } else
        j = (j + saiser[i]) %
            (saiser[i] + 1); /// ON DECREMANTE J DE FACON NE DEPASSE PAS LE
                             /// NOMBRE DE CARACTERE QUI SONT SAISER
    } else if (Q && (c == 77)) {
      /// IL APUIYER SUR RIGHT
      if (i == Taille - 1) {
        AffichezButon(
            buton[j], a + ps[i][j], b + pas[i], 10,
            ColorDeselect); /// DANS CE CAS ON UN BUTON A DESELECTIONNER j
        j = (j + saiser[i] + 1) % (saiser[i]);
        AffichezButon(buton[j], a + ps[i][j], b + pas[i], 10, ColorSelect);
      } else
        j = (j + 1) %
            (saiser[i] + 1); /// ON INCREMANTE J DE FACON NE DEPASSE PAS LE
                             /// NOMBRE DE CARACTERE QUI SONT SAISER

    } else if (Q && (c == 71)) {
      /// IL APUIYER SUR DEBUT DE LINE
      j = 0; /// ON DEPELACE LE CURSEUR A LA DEBUT DE LA LINE
    } else if (Q && (c == 79)) {
      /// IL APUIYER SUR FIN DE LINE
      j = saiser[i]; /// ON DEPELACE LE CURSEUR A LA FIN DE LA PHRASE
    } else if (i == 1) {
      if ((Q && (c == 83)) || (!Q && (c == 8))) {
        /// IL APUIYER SUR SUPPRIMER
        if (j > 0) {
          j--; /// ON DECREMANTE J DE FACON NE DEPASSE PAS LE NOMBRE DE
               /// CARACTERE QUI SONT SAISER
          Info[i][j] = '0'; /// ON REMPLACE LA CARACTERE DANS CHAINE INFO[I] A
                            /// LA POSTION J PAR 0
          cputcxyBlanc(a, b + pas[i], Info[i], saiser[i],
                       &(ps[i][0])); /// ON ECRIT LE CHAINE DANS ECRAN
        } else
          printf("%c", 7); /// ON PEUT PAS SUPRIMER ON INVERTER LE UTILISATAURE
                           /// AVEC UN SON

      } else if ((!Q) && (isdigit(c))) {
        /// IL C NUMERIQUE
        if (j < saiser[i]) {
          Info[i][j] = c; /// ON SAUVERGERDE LA CARACTERE DANS CHAINE INFO[I] A
                          /// LA POSTION J
          cputcxyBlanc(a, b + pas[i], Info[i], saiser[i],
                       &(ps[i][0])); /// ON ECRIT LE CHAINE DANS ECRAN
          j++; /// ON INCREMANTE J DE FACON NE DEPASSE PAS LE NOMBRE DE
               /// CARACTERE QUI SONT SAISER
        } else
          printf(
              "%c",
              7); /// ON PEUT PAS SAISER ON INVERTER LE UTILISATAURE AVEC UN SON
      }
    } else if ((Q && (c == 83)) || (!Q && (c == 8))) {
      /// IL APUIYER SUR SUPPRIMER
      if (j > 0) {
        j--; /// ON DECREMANTE J DE FACON NE DEPASSE PAS LE NOMBRE DE CARACTERE
             /// QUI SONT SAISER
        SupprimerChar(
            Info[i], saiser[i],
            j); /// ON SUPPRIME LA CARACTERE DANS CHAINE INFO[I] A LA POSTION J
        cputsxyBlanc(a + j, b + pas[i], &(Info[i][j]),
                     Lm[i] - j); /// ON ECRIT LE CHAINE DANS ECRAN
        saiser[i]--;             /// ON DECREMANTE LE NOMBRE DES A SAISER
      } else
        printf("%c", 7); /// ON PEUT PAS SUPPRIMER ON INVERTER LE UTILISATAURE
                         /// AVEC UN SON

    } else if ((!Q) && (isdigit(c))) {
      if (saiser[i] < Lm[i]) {
        AjoutezChar(Info[i], saiser[i], j,
                    c); /// ON SAUVERGERDE LA CARACTERE DANS CHAINE INFO[I] A LA
                        /// POSTION J
        cputsxyBlanc(a + j, b + pas[i], &(Info[i][j]),
                     Lm[i] - j); /// ON ECRIT LE CHAINE DANS ECRAN
        saiser[i]++;             /// ON INCREMANTE LE NOMBRE DES A SAISER
        j++; /// ON INCREMANTE J DE FACON NE DEPASSE PAS LE NOMBRE DE CARACTERE
             /// QUI SONT SAISER
      } else
        printf(
            "%c",
            7); /// ON PEUT PAS SAISER ON INVERTER LE UTILISATAURE AVEC UN SON
    }
    if (c == -32)
      Q = true;
    else
      Q = false;
  } while (1);
  /// ON SAUVERGEDE LES INFORMATION
  PLivre->disponible = 1;
  resetcolor();
  system("CLS");
  if (PLivre->Emprunt != NULL) {
    PLivre->Emprunt->penaliter = DiffiranceEntre2Date(
        PLivre->Emprunt->dateDeRetour.days, PLivre->Emprunt->dateDeRetour.month,
        PLivre->Emprunt->dateDeRetour.years, Days, Month, Years);
    PLivre->Emprunt->livreRendu = 1;
    PLivre->Emprunt->Emprunteur->Emprunter = 0;
    (PLivre->Emprunt->Emprunteur->penaliterTotal) += PLivre->Emprunt->penaliter;
    (PLivre->Emprunt->Emprunteur->penaliter) += PLivre->Emprunt->penaliter;
    PLivre->Emprunt->Emprunteur->Emprunt = NULL;
    Afficher_Emprunt(PLivre->Emprunt, 20, 8, 120, 40, ColorCadre2);
    PLivre->Emprunt = NULL;
    c = getch();
    system("CLS");
    cputsxych(22, 3, "LE EMPRUNT EST TERMINER AVEC SECCES MERCI ...");
  } else
    cputsxych(22, 3,
              "IL YA ERREUR DANS LA COTE CETTE N'EST PAS EMPRINTER OU DEJA "
              "RENDER OU IL YA ERREUR DANS LES FICHIER ...");
  c = getch();
FG:
  resetcolor();
}
void AffichezListeEmprunteur(maillon_Emprunteur *tete) {

  /// AFFICHEZ LA LISTE DE EMPRUNTEUR TRIE SELON L'ORDRE DE INSCIPTIONS

  if (tete == NULL) {
    textbackground(colorbackground0);
    system("CLS");
    printf("LA LISTE DES EMPRUNTEUR EST VIDE MERCI ...");
    getch();
    return 0;
  }
  maillon_Emprunteur *P;
  P = tete;
  int m = 0, i;
  char *v[1000];
  char *ch[longeur_Emprunteur(tete) + 1];
  while (P != NULL) {
    sprintf(v, "%s %s ", P->nom, P->prenom);
    ch[m] = malloc((strlen(v) + 2) * sizeof(char));
    strcpy(ch[m], v);
    P = suivant_Emprunteur(P);
    m++;
  }
  do {
    textbackground(colorbackground0);
    system("CLS");
    i = Menu(ch, m, PX1, PY1, LNGR1, HTR1);
    if (i == 0)
      break;
    P = AccPos1_Emprunteur(i, tete);
    textbackground(colorbackground0);
    system("CLS");
    if (P != NULL)
      Afficher_Emprunteur(P, 20, 8, 80, 50, ColorCadre2);
    getch();
  } while (1);
  resetcolor();
}
void AffichezListeLivre(maillon_Livre *Livre) {

  /// AFFICHEZ LA LISTE DES LIVRES

  if (Livre == NULL) {
    textbackground(colorbackground0);
    system("CLS");
    printf("LA LISTE DES LIVRES EST VIDE MERCI ...");
    getch();
    return 0;
  }
  maillon_Livre *P;
  P = Livre;
  int m = 0, i;
  char *v[1000];
  char *T[longeur_Livre(P) + 2];
  while (P != NULL) {
    sprintf(v, "%s %s", P->titre, P->auteur);
    T[m] = malloc(strlen(v) * sizeof(char) + 2);
    strcpy(T[m], v);
    m++;
    P = suivant_Livre(P);
  }

  do {
    textbackground(colorbackground0);
    system("CLS");
    i = Menu(T, m, PX1, PY1, LNGR1, HTR1);
    if (i == 0)
      break;
    P = AccPos1_Livre(i, Livre);
    textbackground(colorbackground0);
    system("CLS");
    Afficher_Livre(P, 20, 2, 120, 45, ColorCadre2);
    getch();
  } while (1);
  resetcolor();
}
void AffichezListeEmprunt(maillon_Emprunt *Emprunt) {

  /// AFFICHEZ LA LISTE DES EMPRUNTS

  if (Emprunt == NULL) {
    textbackground(colorbackground0);
    system("CLS");
    printf("LA LISTE DES LIVRES EST VIDE MERCI ...");
    getch();
    return 0;
  }
  maillon_Emprunt *P;
  P = Emprunt;
  int m = 0, i;
  char *v[1000];
  char *T[longeur_Emprunt(P) + 2];
  while (P != NULL) {
    sprintf(v, "%s PAR %s %s", P->livreEmprunte->titre, P->Emprunteur->nom,
            P->Emprunteur->prenom);
    T[m] = malloc(strlen(v) * sizeof(char) + 2);
    strcpy(T[m], v);
    m++;
    P = suivant_Emprunt(P);
  }

  do {
    textbackground(colorbackground0);
    system("CLS");
    i = Menu(T, m, PX1, PY1, LNGR1, HTR1);
    if (i == 0)
      break;
    P = AccPos1_Emprunt(i, Emprunt);
    textbackground(colorbackground0);
    system("CLS");
    Afficher_Emprunt(P, 20, 8, 120, 40, ColorCadre2);
    getch();
  } while (1);
  resetcolor();
}
void RecharcheUnLivreCote(maillon_Livre *Livre) {

  /// RECHARCHEZ UN COTE DANS LISTE LIVRE

  int x = 40, y = 5, lg = 80, ht = 10, Lm = 20;
  char Info[30];
debut:
  AffichezPage(x, y, lg, ht, colorbackground);
  AffichezCadre(x - 1, y - 1, lg + 2, ht + 2, 5, colorText);

  int a = x + 30, b = y + 4, pos1;
  textcolor(ColorDeTitre);
  gotoxy(x + 5, b);
  char *Mot = "COTE";
  printf("%s\t: ", Mot);
  colorText = ColorTextInput;
  textcolor(colorText);
  colorbackground = ColorInput;
  textbackground(ColorInput);
  cputsxyBlanc(a, b - 1, " ", Lm);
  cputsxyBlanc(a, b, " ", Lm);
  int Q = false, j = 0, saiser = 0;
  char c;

  do {
    gotoxy(a + j, b);
    c = getch();
    if ((!Q) && (c == 27)) {
      resetcolor();
      return 0;
    }
    if ((!Q) && (c == 13)) {
      textbackground(ColorSup); /// ON SUPPRIMER LE ANCIEN MESSAGE SI IL EXISTE
      cputsxyBlanc(x, y, " ", lg);
      cputsxyBlanc(x, y + 1, " ", lg);
      textbackground(colorbackground);
      if (saiser == 0) {
        AffichezErreur(x + 20, y + 1, " TU DOIS REMLIRE LA CASE ");
        continue;
      }
      pos1 = RechachezUnCote_Livre(Livre, strtol(Info, NULL, 10));
      if (!pos1) {
        AffichezErreur(x + 20, y + 1, " CE NUMERO DE COTE N'EXSITE PAS ");
        continue;
      }
      break;

    } else if (Q && (c == 75)) {
      /// IL APUIYER SUR LEFT
      j = (j + saiser) %
          (saiser + 1); /// ON DECREMANTE J DE FACON NE DEPASSE PAS LE NOMBRE DE
                        /// CARACTERE QUI SONT SAISER
    } else if (Q && (c == 77)) {
      /// IL APUIYER SUR RIGHT
      j = (j + 1) % (saiser + 1); /// ON INCREMANTE J DE FACON NE DEPASSE PAS LE
                                  /// NOMBRE DE CARACTERE QUI SONT SAISER
    } else if (Q && (c == 71)) {
      /// IL APUIYER SUR DEBUT DE LINE
      j = 0; /// ON DEPELACE LE CURSEUR A LA DEBUT DE LA LINE
    } else if (Q && (c == 79)) {
      /// IL APUIYER SUR FIN DE LINE
      j = saiser; /// ON DEPELACE LE CURSEUR A LA FIN DE LA PHRASE
    } else if ((Q && (c == 83)) || (!Q && (c == 8))) {
      /// IL APUIYER SUR SUPPRIMER
      if (j > 0) {
        j--; /// ON DECREMANTE J DE FACON NE DEPASSE PAS LE NOMBRE DE CARACTERE
             /// QUI SONT SAISER
        SupprimerChar(
            Info, saiser,
            j); /// ON SUPPRIME LA CARACTERE DANS CHAINE INFO[I] A LA POSTION J
        cputsxyBlanc(a + j, b, &(Info[j]),
                     Lm - j); /// ON ECRIT LE CHAINE DANS ECRAN
        saiser--;             /// ON DECREMANTE LE NOMBRE DES A SAISER
      } else
        printf("%c", 7); /// ON PEUT PAS SUPPRIMER ON INVERTER LE UTILISATAURE
                         /// AVEC UN SON
    } else if ((!Q) && (isdigit(c))) {
      if (saiser < Lm) {
        AjoutezChar(Info, saiser, j, c); /// ON SAUVERGERDE LA CARACTERE DANS
                                         /// CHAINE INFO[I] A LA POSTION J
        cputsxyBlanc(a + j, b, &(Info[j]),
                     Lm - j); /// ON ECRIT LE CHAINE DANS ECRAN
        saiser++;             /// ON INCREMANTE LE NOMBRE DES A SAISER
        j++; /// ON INCREMANTE J DE FACON NE DEPASSE PAS LE NOMBRE DE CARACTERE
             /// QUI SONT SAISER
      } else
        printf(
            "%c",
            7); /// ON PEUT PAS SAISER ON INVERTER LE UTILISATAURE AVEC UN SON
    }
    if (c == -32)
      Q = true;
    else
      Q = false;
  } while (1);
  maillon_Livre *P = AccPos1_Livre(pos1, Livre);
  resetcolor();
  system("CLS");
  Afficher_Livre(P, 20, 2, 120, 45, ColorCadre2);
  resetcolor();
}
void RecharcheUnLivreAuteur(maillon_Livre *Livre) {

  /// RECHARCHEZ UN AUTEUR DANS LISTE LIVRE

  int x = 40, y = 5, lg = 80, ht = 10, Lm = 40;
  char Info[30];
  AffichezPage(x, y, lg, ht, colorbackground);
  AffichezCadre(x - 1, y - 1, lg + 2, ht + 2, 5, colorText);

  int a = x + 30, b = y + 4, pos1;
  textcolor(ColorDeTitre);
  gotoxy(x + 5, b);
  char *Mot = "AUTEUR";
  printf("%s\t: ", Mot);
  colorText = ColorTextInput;
  textcolor(colorText);
  colorbackground = ColorInput;
  textbackground(ColorInput);
  cputsxyBlanc(a, b - 1, " ", Lm);
  cputsxyBlanc(a, b, " ", Lm);
  int Q = false, j = 0, saiser = 0;
  char c;

  do {
    gotoxy(a + j, b);
    c = getch();
    if ((!Q) && (c == 27)) {
      resetcolor();
      return 0;
    }

    if ((!Q) && (c == 13)) {
      if (saiser == 0) {
        AffichezErreur(x + 10, y + 1, " TU DOIS REMLIRE LA CASE ");
        continue;
      }
      break;

    } else if (Q && (c == 75)) {
      /// IL APUIYER SUR LEFT
      j = (j + saiser) %
          (saiser + 1); /// ON DECREMANTE J DE FACON NE DEPASSE PAS LE NOMBRE DE
                        /// CARACTERE QUI SONT SAISER
    } else if (Q && (c == 77)) {
      /// IL APUIYER SUR RIGHT
      j = (j + 1) % (saiser + 1); /// ON INCREMANTE J DE FACON NE DEPASSE PAS LE
                                  /// NOMBRE DE CARACTERE QUI SONT SAISER
    } else if (Q && (c == 71)) {
      /// IL APUIYER SUR DEBUT DE LINE
      j = 0; /// ON DEPELACE LE CURSEUR A LA DEBUT DE LA LINE
    } else if (Q && (c == 79)) {
      /// IL APUIYER SUR FIN DE LINE
      j = saiser; /// ON DEPELACE LE CURSEUR A LA FIN DE LA PHRASE
    } else if ((Q && (c == 83)) || (!Q && (c == 8))) {
      /// IL APUIYER SUR SUPPRIMER
      if (j > 0) {
        j--; /// ON DECREMANTE J DE FACON NE DEPASSE PAS LE NOMBRE DE CARACTERE
             /// QUI SONT SAISER
        SupprimerChar(
            Info, saiser,
            j); /// ON SUPPRIME LA CARACTERE DANS CHAINE INFO[I] A LA POSTION J
        cputsxyBlanc(a + j, b, &(Info[j]),
                     Lm - j); /// ON ECRIT LE CHAINE DANS ECRAN
        saiser--;             /// ON DECREMANTE LE NOMBRE DES A SAISER
      } else
        printf("%c", 7); /// ON PEUT PAS SUPPRIMER ON INVERTER LE UTILISATAURE
                         /// AVEC UN SON
    } else if ((!Q) && ((isalnum(c)) || (c == 32))) {
      if (saiser < Lm) {
        if ((c != 32) ||
            ((c == 32) && (j > 0) && (Info[j - 1] != 32) && (Info[j] != 32))) {
          c = (islower(c)) ? c - 32 : c; /// ON TRANFER LES LETTRE EN MAJUSQUILE
          AjoutezChar(Info, saiser, j, c); /// ON SAUVERGERDE LA CARACTERE DANS
                                           /// CHAINE INFO[I] A LA POSTION J
          cputsxyBlanc(a + j, b, &(Info[j]),
                       Lm - j); /// ON ECRIT LE CHAINE DANS ECRAN
          saiser++;             /// ON INCREMANTE LE NOMBRE DES A SAISER
          j++; /// ON INCREMANTE J DE FACON NE DEPASSE PAS LE NOMBRE DE
               /// CARACTERE QUI SONT SAISER
        }
      } else
        printf(
            "%c",
            7); /// ON PEUT PAS SAISER ON INVERTER LE UTILISATAURE AVEC UN SON
    }
    if (c == -32)
      Q = true;
    else
      Q = false;
  } while (1);
  maillon_Livre *P[longeur_Livre(Livre)];
  P[0] = NULL;
  RechacheParAuteur(Livre, Info, P);
  resetcolor();
  system("CLS");
  if (P[0] == NULL) {
    printf("LES LIVRES DE CETTE AUTEUR N'EXISTE PAS MERCI ...");
    getch();
    return 0;
  }
  int m = 0, i;
  char *v[1000];
  char *T[longeur_Livre(Livre)];
  while (P[m] != NULL) {
    sprintf(v, "%s %d", P[m]->titre, P[m]->cote);
    T[m] = malloc(strlen(v) * sizeof(char) + 2);
    strcpy(T[m], v);
    m++;
  }
  do {
    textbackground(colorbackground0);
    system("CLS");
    i = Menu(T, m, PX1, PY1, LNGR1, HTR1);
    if (i == 0)
      break;
    textbackground(colorbackground0);
    system("CLS");
    Afficher_Livre(P[i - 1], 20, 2, 120, 45, ColorCadre2);
    getch();
  } while (1);
  resetcolor();
}
void RecharcheUnLivreMotsCles(maillon_Livre *Livre) {

  /// RECHARCHEZ UN AUTEUR DANS LISTE LIVRE

  int x = 40, y = 5, lg = 80, ht = 10, Lm = 50;
  char Info[50];
  AffichezPage(x, y, lg, ht, colorbackground);
  AffichezCadre(x - 1, y - 1, lg + 2, ht + 2, 5, colorText);

  int a = x + 20, b = y + 4, pos1;
  textcolor(ColorDeTitre);
  gotoxy(x + 5, b);
  char *Mot = "MOTS CLES";
  printf("%s\t: ", Mot);
  colorText = ColorTextInput;
  textcolor(colorText);
  colorbackground = ColorInput;
  textbackground(ColorInput);
  cputsxyBlanc(a, b - 1, " ", Lm);
  cputsxyBlanc(a, b, " ", Lm);
  int Q = false, j = 0, saiser = 0;
  char c;

  do {
    gotoxy(a + j, b);
    c = getch();
    if ((!Q) && (c == 27)) {
      resetcolor();
      return 0;
    }
    if ((!Q) && (c == 13)) {
      if (saiser == 0) {
        AffichezErreur(x + 20, y + 1, " TU DOIS REMLIRE LA CASE ");
        continue;
      }
      break;

    } else if (Q && (c == 75)) {
      /// IL APUIYER SUR LEFT
      j = (j + saiser) %
          (saiser + 1); /// ON DECREMANTE J DE FACON NE DEPASSE PAS LE NOMBRE DE
                        /// CARACTERE QUI SONT SAISER
    } else if (Q && (c == 77)) {
      /// IL APUIYER SUR RIGHT
      j = (j + 1) % (saiser + 1); /// ON INCREMANTE J DE FACON NE DEPASSE PAS LE
                                  /// NOMBRE DE CARACTERE QUI SONT SAISER
    } else if (Q && (c == 71)) {
      /// IL APUIYER SUR DEBUT DE LINE
      j = 0; /// ON DEPELACE LE CURSEUR A LA DEBUT DE LA LINE
    } else if (Q && (c == 79)) {
      /// IL APUIYER SUR FIN DE LINE
      j = saiser; /// ON DEPELACE LE CURSEUR A LA FIN DE LA PHRASE
    } else if ((Q && (c == 83)) || (!Q && (c == 8))) {
      /// IL APUIYER SUR SUPPRIMER
      if (j > 0) {
        j--; /// ON DECREMANTE J DE FACON NE DEPASSE PAS LE NOMBRE DE CARACTERE
             /// QUI SONT SAISER
        SupprimerChar(
            Info, saiser,
            j); /// ON SUPPRIME LA CARACTERE DANS CHAINE INFO[I] A LA POSTION J
        cputsxyBlanc(a + j, b, &(Info[j]),
                     Lm - j); /// ON ECRIT LE CHAINE DANS ECRAN
        saiser--;             /// ON DECREMANTE LE NOMBRE DES A SAISER
      } else
        printf("%c", 7); /// ON PEUT PAS SUPPRIMER ON INVERTER LE UTILISATAURE
                         /// AVEC UN SON
    } else if ((!Q) && ((isalnum(c)) || (c == 32))) {
      if (saiser < Lm) {
        if ((c != 32) ||
            ((c == 32) && (j > 0) && (Info[j - 1] != 32) && (Info[j] != 32))) {
          AjoutezChar(Info, saiser, j, c); /// ON SAUVERGERDE LA CARACTERE DANS
                                           /// CHAINE INFO[I] A LA POSTION J
          cputsxyBlanc(a + j, b, &(Info[j]),
                       Lm - j); /// ON ECRIT LE CHAINE DANS ECRAN
          saiser++;             /// ON INCREMANTE LE NOMBRE DES A SAISER
          j++; /// ON INCREMANTE J DE FACON NE DEPASSE PAS LE NOMBRE DE
               /// CARACTERE QUI SONT SAISER
        }
      } else
        printf(
            "%c",
            7); /// ON PEUT PAS SAISER ON INVERTER LE UTILISATAURE AVEC UN SON
    }
    if (c == -32)
      Q = true;
    else
      Q = false;
  } while (1);
  maillon_Livre *P[longeur_Livre(Livre)];
  RechacheParMotsCles(Livre, Info, P);
  resetcolor();
  system("CLS");
  if (P[0] == NULL) {
    printf("LES LIVRES AVEC CES MOT CLES N'EXISTE PAS MERCI ...");
    getch();
    return 0;
  }
  int m = 0, i;
  char *v[1000];
  char *T[20];
  while (P[m] != NULL) {
    sprintf(v, "%s %d", P[m]->titre, P[m]->cote);
    T[m] = malloc(strlen(v) * sizeof(char) + 2);
    strcpy(T[m], v);
    m++;
  }
  do {
    resetcolor();
    system("CLS");
    i = Menu(T, m, PX1, PY1, LNGR1, HTR1);
    if (i == 0)
      break;
    resetcolor();
    system("CLS");
    Afficher_Livre(P[i - 1], 20, 2, 120, 45, ColorCadre2);
    getch();
  } while (1);
  resetcolor();
}
void Debut() {
  system("CLS");
  int z = 40;
  int w = 10;
  char a = 219;
  system("cls");
  puts("    ");
  textbackground(15);
  system("cls");
  gotoxy(z, w - 3);
  textcolor(0);

  printf("                 ---| ECOLE SUPERIEURE D'INFORMATIQUE ESI |---  ");
  textcolor(0);
  puts("    ");
  puts("    ");
  textcolor(15);

  gotoxy(z, w + 5);
  printf("<>");
  textcolor(3);

  gotoxy(z, w + 1);
  printf("      %c%c%c%c%c%c%c%c%c      %c%c     %c%c%c%c%c%c%c%c%c      "
         "%c%c%c%c%c%c%c%c%c     %c%c%c%c%c%c%c%c%c      %c%c",
         a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a,
         a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a);
  gotoxy(z, w + 2);
  printf("      %c%c%c%c%c%c%c%c%c      %c%c     %c%c%c%c%c%c%c%c%c      "
         "%c%c%c%c%c%c%c%c%c     %c%c%c%c%c%c%c%c%c      %c%c",
         a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a,
         a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a);
  gotoxy(z, w + 3);
  printf("      %c%c       %c%c    %c%c     %c%c       %c%c    %c%c            "
         "%c%c             %c%c",
         a, a, a, a, a, a, a, a, a, a, a, a, a);
  gotoxy(z, w + 4);
  printf("      %c%c       %c%c    %c%c     %c%c       %c%c    %c%c            "
         "%c%c             %c%c",
         a, a, a, a, a, a, a, a, a, a, a, a, a);
  gotoxy(z, w + 5);
  printf("      %c%c       %c%c    %c%c     %c%c       %c%c    %c%c            "
         "%c%c             %c%c",
         a, a, a, a, a, a, a, a, a, a, a, a, a);
  gotoxy(z, w + 6);
  printf("      %c%c%c%c%c%c%c%c%c      %c%c     %c%c%c%c%c%c%c%c%c      "
         "%c%c%c%c%c%c%c%c%c     %c%c%c%c%c%c%c%c%c      %c%c",
         a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a,
         a, a, a, a, a, a, a, a, a, a, a, a, a, a);
  gotoxy(z, w + 7);
  printf("      %c%c%c%c%c%c%c%c%c      %c%c     %c%c%c%c%c%c%c%c%c      "
         "%c%c%c%c%c%c%c%c%c     %c%c%c%c%c%c%c%c%c      %c%c",
         a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a,
         a, a, a, a, a, a, a, a, a, a, a, a, a, a);
  gotoxy(z, w + 8);
  printf("      %c%c       %c%c    %c%c     %c%c       %c%c    %c%c            "
         "       %c%c      %c%c",
         a, a, a, a, a, a, a, a, a, a, a, a, a, a);
  gotoxy(z, w + 9);
  printf("      %c%c       %c%c    %c%c     %c%c       %c%c    %c%c            "
         "       %c%c      %c%c",
         a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a);
  gotoxy(z, w + 10);
  printf("      %c%c       %c%c    %c%c     %c%c       %c%c    %c%c            "
         "       %c%c      %c%c",
         a, a, a, a, a, a, a, a, a, a, a, a, a, a);
  gotoxy(z, w + 11);
  printf("      %c%c%c%c%c%c%c%c%c      %c%c     %c%c%c%c%c%c%c%c%c      "
         "%c%c%c%c%c%c%c%c%c     %c%c%c%c%c%c%c%c%c      %c%c",
         a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a,
         a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a);
  gotoxy(z, w + 12);
  printf("      %c%c%c%c%c%c%c%c%c      %c%c     %c%c%c%c%c%c%c%c%c      "
         "%c%c%c%c%c%c%c%c%c     %c%c%c%c%c%c%c%c%c      %c%c",
         a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a,
         a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a);
  gotoxy(z + 20, w + 13);
  printf("\n");
  textcolor(4);
  printf("                                         < GESTIONNAIRE DE "
         "BIBLIOTHEQUE BIBESI > |");
  textcolor(12);
  printf("                              | V 1.0 ");
  puts("                          ");
  textcolor(0);
  printf("                                         "
         "_____________________________________________________________________"
         "_________");
  printf("\n");
  textcolor(5);
  printf("                                        |%c%c                        "
         "                                                    %c%c|",
         a, a, a, a);
  textcolor(0);
  printf("\n");
  textcolor(5);
  printf("                                        |%c%c           REALISE PAR  "
         " --->   CHAKLALA LAHCENE | ISMAIL KHERBACH          %c%c|",
         a, a, a, a);
  textcolor(0);
  printf("\n");
  printf("                                        "
         "|%c%c________________________________________________________________"
         "___________ %c%c|",
         a, a, a, a);
  textcolor(0);
  printf("\n");
  printf("                                        |%c%C                        "
         "                                                    %c%c|",
         a, a, a, a);
  textcolor(5);
  printf("\n");
  printf("                                        |%c%c           SECTION C    "
         "--|-->    1CPI   --|-->    GO9                      %c%c|",
         a, a, a, a);
  textcolor(5);
  printf("\n");
  textcolor(5);
  printf("                                        "
         "|%c%c________________________________________________________________"
         "____________%c%c|",
         a, a, a, a);
  textcolor(0);
  printf("\n");
  printf("                                        "
         "|%c%c________________________________________________________________"
         "___________ %c%c|",
         a, a, a, a);
  textcolor(0);
  printf("\n");
  printf("                                        |%c%C                        "
         "                                                    %c%c|",
         a, a, a, a);
  textcolor(5);
  printf("\n");
  printf("                                        |%c%c           ENCADRE PAR "
         "MADAME DAOUDI ASMAA                                  %c%c|",
         a, a, a, a);
  textcolor(5);
  printf("\n");
  textcolor(5);
  printf("                                        "
         "|%c%c________________________________________________________________"
         "____________%c%c|",
         a, a, a, a);
  textcolor(5);
  printf("\n");
  textcolor(0);
  puts("                          ");
  printf("                                                       "
         "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%"
         "c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
         a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a,
         a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a,
         a, a, a, a);
  printf("\n");
  textcolor(4);
  printf("                                                       %c%c%c%c%c    "
         "                                      %c%c%c%c%c",
         a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a);
  printf("\n");
  printf("                                                       %c%c%c%c%c    "
         "    | CLIQUER POUR CONTINUER |        %c%c%c%c%c",
         a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a);
  printf("\n");
  printf("                                                       %c%c%c%c%c    "
         "                                      %c%c%c%c%c",
         a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a);
  textcolor(0);
  printf("\n");
  printf("                                                       "
         "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%"
         "c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
         a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a,
         a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a,
         a, a, a, a);

  puts("                         ");
  printf("\n");
  printf("\n");
  printf("\n");
  puts("                                                                       "
       "                       Copyrights Reserved 2017");
  printf("\n");

  getch();
  textbackground(colorbackground0);
  textcolor(colorText0);
}
void FIN() {
  system("CLS");
  int z = 40;
  int w = 10;
  char a = 219;
  system("cls");
  puts("    ");
  textcolor(BLACK);
  puts("                                         LES SAUVEGARDEMNT EST "
       "TERMINREE AVEC SUCCES .............. ");
  gotoxy(10, 40);

  puts("                                        {LAHCENE CHAKLALA </> ISMAIL "
       "KHERBACH ALL COPYRIGHTS RESERVED 2017             ");
  textcolor(0);
  getch();
  textbackground(colorbackground0);
  textcolor(colorText0);
}
void AffichezGuide() {
  system("CLS");
  int z = 27;
  int w = 5;
  char a = 219;
  system("cls");
  puts("    ");
  textbackground(15);
  system("cls");
  textcolor(4);
  puts("                             ECOLE SUPERIEURE D'INFORMATIQUE ESI "
       "{LAHCENE CHAKLALA </> ISMAIL KHERBACH}");
  gotoxy(z, w + 1);
  textcolor(5);
  printf("      %c%c%c%c%c%c%c%c%c       %c%c        %c%c      %c%c      "
         "%c%c%c%c%c%c%c%c%c      %c%c%c%c%c%c%c%c%c",
         a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a,
         a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a);
  gotoxy(z, w + 2);
  printf("      %c%c%c%c%c%c%c%c%c       %c%c        %c%c      %c%c      "
         "%c%c%c%c%c%c%c%c%c      %c%c%c%c%c%c%c%c%c",
         a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a,
         a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a);
  gotoxy(z, w + 3);
  printf("      %c%c              %c%c        %c%c      %c%c      %c%c      "
         "%c%c     %c%c",
         a, a, a, a, a, a, a, a, a, a, a, a, a);
  gotoxy(z, w + 4);
  printf("      %c%c              %c%c        %c%c      %c%c      %c%c      "
         "%c%c     %c%c",
         a, a, a, a, a, a, a, a, a, a, a, a, a);
  gotoxy(z, w + 5);
  printf("      %c%c              %c%c        %c%c      %c%c      %c%c      "
         "%c%c     %c%c",
         a, a, a, a, a, a, a, a, a, a, a, a, a);
  gotoxy(z, w + 6);
  printf("      %c%c              %c%c        %c%c      %c%c      %c%c      "
         "%c%c     %c%c%c%c%c%c%c%c%c",
         a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a,
         a, a, a, a, a, a, a, a, a, a, a, a, a, a);
  gotoxy(z, w + 7);
  printf("      %c%c   %c%c%c%c       %c%c        %c%c      %c%c      %c%c     "
         " %c%c     %c%c%c%c%c%c%c%c%c",
         a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a,
         a, a, a, a, a, a, a, a, a, a, a, a, a, a);
  gotoxy(z, w + 8);
  printf("      %c%c       %c%c     %c%c        %c%c      %c%c      %c%c      "
         "%c%c     %c%c",
         a, a, a, a, a, a, a, a, a, a, a, a, a, a);
  gotoxy(z, w + 9);
  printf("      %c%c       %c%c     %c%c        %c%c      %c%c      %c%c      "
         "%c%c     %c%c",
         a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a);
  gotoxy(z, w + 10);
  printf("      %c%c       %c%c     %c%c        %c%c      %c%c      %c%c      "
         "%c%c     %c%c",
         a, a, a, a, a, a, a, a, a, a, a, a, a, a, a);
  gotoxy(z, w + 11);
  printf("      %c%c%c%c%c%c%c%c%c       %c%c%c%c%c%c%c%c%c%c%c%c      %c%c    "
         "  %c%c%c%c%c%c%c%c%c      %c%c%c%c%c%c%c%c%c",
         a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a,
         a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a);
  gotoxy(z, w + 12);
  printf("      %c%c%c%c%c%c%c%c%c       %c%c%c%c%c%c%c%c%c%c%c%c      %c%c    "
         "  %c%c%c%c%c%c%c%c%c      %c%c%c%c%c%c%c%c%c",
         a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a,
         a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a);
  gotoxy(z, w + 13);
  printf("\n");
  printf("\n");
  textcolor(4);

  puts("                      "
       "_______________________________________________________________________"
       "___________");

  puts("                      ");
  puts("                      DANS CETTE PAGE VOUS TROUVEZ LE GUIDE POUR BIEN "
       "MANUPILER L'APPLICATION");
  puts("                      "
       "_______________________________________________________________________"
       "___________");
  printf("\n");
  printf("\n");
  textcolor(0);
  printf(
      "         %c%c%c%c%c%c%c%c%c%c                    %c%c%c%c%c%c%c%c%c%c",
      a, a, a, a, a, a, a, a, a, a, a, a, a);
  printf("\n");
  printf("         %c%c      %c%c                    %c%c      %c%c", a, a, a,
         a, a);
  printf("\n");
  printf(
      "         %c%c ---> %c%c     MOVE RIGHT     %c%c  UP  %c%c      MOVE UP",
      a, a, a, a, a);
  printf("\n");
  printf("         %c%c      %c%c                    %c%c      %c%c", a, a, a,
         a, a);
  printf("\n");
  printf(
      "         %c%c%c%c%c%c%c%c%c%c                    %c%c%c%c%c%c%c%c%c%c",
      a, a, a, a, a, a, a, a, a, a, a, a, a);
  printf("\n");
  printf("\n");
  printf(
      "         %c%c%c%c%c%c%c%c%c%c                    %c%c%c%c%c%c%c%c%c%c",
      a, a, a, a, a, a, a, a, a, a, a, a, a);
  printf("\n");
  printf("         %c%c      %c%c                    %c%c      %c%c", a, a, a,
         a, a);
  printf("\n");
  printf("         %c%c <--- %c%c     MOVE LEFT      %c%c DOWN %c%c      MOVE "
         "DOWN",
         a, a, a, a, a);
  printf("\n");
  printf("         %c%c      %c%c                    %c%c      %c%c", a, a, a,
         a, a);
  printf("\n");
  printf(
      "         %c%c%c%c%c%c%c%c%c%c                    %c%c%c%c%c%c%c%c%c%c",
      a, a, a, a, a, a, a, a, a, a, a, a, a);
  printf("\n");
  printf("\n");
  printf("         %c%c%c%c%c%c%c%c%c%c                    "
         "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                    "
         "%c%c%c%c%c%c%c%c%c%c%c%c",
         a, a, a, a, a, a, a, a, a, a, a, a, a);
  printf("\n");
  printf("         %c%c      %c%c                    %c%c           %c%c       "
         "             %c%c        %c%c                    ",
         a, a, a, a, a);
  printf("\n");
  printf("         %c%c ESC  %c%c     MOVE BACK      %c%c   <---    %c%c      "
         "CLEAR         %c%c SUPPR  %c%c     DELETE TEXT      ",
         a, a, a, a, a);
  printf("\n");
  printf("         %c%c      %c%c                    %c%c           %c%c       "
         "             %c%c        %c%c                    ",
         a, a, a, a, a);
  printf("\n");
  printf("         %c%c%c%c%c%c%c%c%c%c                    "
         "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                    "
         "%c%c%c%c%c%c%c%c%c%c%c%c",
         a, a, a, a, a, a, a, a, a, a, a, a, a);
  printf("\n");
  printf("\n");
  printf(
      "         %c%c%c%c%c%c%c%c%c%c                    %c%c%c%c%c%c%c%c%c%c   "
      "                 %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
      a, a, a, a, a, a, a, a, a, a, a, a, a);
  printf("\n");
  printf("         %c%c      %c%c                    %c%c      %c%c            "
         "        %c%c                %c%c",
         a, a, a, a, a);
  printf("\n");
  printf("         %c%c    | %c%c                    %c%c FIN  %c%c   GO TO "
         "END PAGE   %c%c     ESPACE     %c%c    SEPARE BETWEEN WORDS EXT ..",
         a, a, a, a, a);

  printf("\n");
  printf("         %c%c <--| %c%c  ACCESS TO PAGE    %c%c      %c%c            "
         "        %c%c                %c%c",
         a, a, a, a, a);
  printf("\n");
  printf("           %c%c    %c%c   ENTER VALUE      %c%c%c%c%c%c%c%c%c%c      "
         "              %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
         a, a, a, a, a);
  printf("\n");
  printf("           %c%c    %c%c", a, a, a, a, a);
  printf("\n");
  printf("           %c%c%c%c%c%c%c%c", a, a, a, a, a, a, a, a, a, a, a, a, a);
  printf("\n");
  puts("                                                                       "
       "                   ALL COPYRIGHTS RESERVED 2017");

  getch();
  textbackground(colorbackground0);
  textcolor(colorText0);
}

#endif
