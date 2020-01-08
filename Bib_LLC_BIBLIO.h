#ifndef _Bib_LLC_BIBLIO_H_
#define _Bib_LLC_BIBLIO_H_

#include "Bib_Standare.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct date date;
typedef struct maillon_Livre maillon_Livre;
typedef struct maillon_Emprunteur maillon_Emprunteur;
typedef struct maillon_Emprunt maillon_Emprunt;

struct date {
  int days;
  int month;
  int years;
};

struct maillon_Emprunteur {
  char nom[50];
  char prenom[50];
  char adresseActuelle[50];
  char nDeTelephone[30];
  int ordreInscription;
  date dateDeInscription;
  int penaliterTotal;
  int penaliter;
  int Emprunter;
  int NbreDeEmprunt;
  maillon_Emprunt *Emprunt;
  maillon_Emprunteur *suiv;
};

/**--------------------------------------------------------------------------------------------------------------------------------**/

struct maillon_Livre {
  int cote;
  char titre[50];
  char auteur[50];
  date dateEdition;
  char editeur[50];
  char motCle[70];
  char resume[700];
  int nbrDeEmprunt;
  int disponible;
  maillon_Emprunt *Emprunt;
  maillon_Livre *suiv;
};

/**--------------------------------------------------------------------------------------------------------------------------------**/

struct maillon_Emprunt {
  maillon_Emprunteur *Emprunteur;
  maillon_Livre *livreEmprunte;
  date dateDeEmprunt;
  date dateDeRetour;
  int penaliter;
  int livreRendu;
  maillon_Emprunt *suiv;
};

/**--------------------------------------------------------------------------------------------------------------------------------**/
/**--------------------------------------------------------------------------------------------------------------------------------**/
/**---------------------------------------------- MACHINE ABSTREATE DE FICHE
 * LIVRE -------------------------------------------------**/
/**--------------------------------------------------------------------------------------------------------------------------------**/
/**--------------------------------------------------------------------------------------------------------------------------------**/

void allouer_Livre(maillon_Livre **nouveau) {
  *nouveau = (maillon_Livre *)malloc(sizeof(maillon_Livre));
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

void liberer_Livre(maillon_Livre **ancien) {
  free(*ancien);
  *ancien = NULL;
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

void aff_adr_Livre(maillon_Livre *p, maillon_Livre *q) { p->suiv = q; }

/**--------------------------------------------------------------------------------------------------------------------------------**/

maillon_Livre *suivant_Livre(maillon_Livre *p) { return (p->suiv); }

/**--------------------------------------------------------------------------------------------------------------------------------**/

int longeur_Livre(
    maillon_Livre *p) /// "LONGEUR" EST UNE FONCTION PERMET DE S'AVOIR LA
                      /// LONGEUR D'UNE LISTE POINTE PAR *P
{
  int l = 0;
  while (p != NULL) {
    p = suivant_Livre(p);
    l++;
  }
  return l;
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

void AccPos2_Livre(
    int pos, maillon_Livre **p, maillon_Livre **q,
    maillon_Livre *liste) /// DONNE L'ADRESSE DU PTR DE MAILLON DE POSITION POS
                          /// ET L'ADRESSE DU PTR DU MAILLON QUI LE PRECEDE
{
  int i = 1;
  *p = liste, *q = NULL;
  while (*p != NULL && i != pos) {
    *q = *p;
    *p = suivant_Livre(*p);
    i++;
  }
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

maillon_Livre *AccPos1_Livre(
    int pos,
    maillon_Livre *liste) // DONNE L'ADRESSE DU PTR DE MAILLON DE POSITION pos
{
  int i = 1;
  maillon_Livre *p = liste;

  while (i != pos && p != NULL) {
    p = suivant_Livre(p);
    i++;
  }
  return p;
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

void viderListe_Livre(
    maillon_Livre **liste) /// Libere tout les maillon d'une liste
{
  maillon_Livre *p;
  while (*liste != NULL) {
    p = *liste;
    *liste = suivant_Livre(*liste);
    liberer_Livre(&p);
  }
}

/**--------------------------------------------------------------------------------------------------------------------------------**/
/**--------------------------------------------------------------------------------------------------------------------------------**/
/**---------------------------------------------- MACHINE ABTREATE DE FICHE
 * EMPRUNTUEUR -------------------------------------------**/
/**--------------------------------------------------------------------------------------------------------------------------------**/
/**--------------------------------------------------------------------------------------------------------------------------------**/

void allouer_Emprunteur(maillon_Emprunteur **nouveau) {
  *nouveau = (maillon_Emprunteur *)malloc(sizeof(maillon_Emprunteur));
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

void liberer_Emprunteur(maillon_Emprunteur **ancien) {
  free(*ancien);
  *ancien = NULL;
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

void aff_adr_Emprunteur(maillon_Emprunteur *p, maillon_Emprunteur *q) {
  p->suiv = q;
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

maillon_Emprunteur *suivant_Emprunteur(maillon_Emprunteur *p) {
  return (p->suiv);
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

int longeur_Emprunteur(
    maillon_Emprunteur *p) /// "LONGEUR" EST UNE FONCTION PERMET DE S'AVOIR LA
                           /// LONGEUR D'UNE LISTE POINTE PAR *P
{
  int l = 0;
  while (p != NULL) {
    p = suivant_Emprunteur(p);
    l++;
  }
  return l;
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

void AccPos2_Emprunteur(
    int pos, maillon_Emprunteur **p, maillon_Emprunteur **q,
    maillon_Emprunteur
        *liste) // DONNE L'ADRESSE DU PTR DE MAILLON DE POSITION POS ET
                // L'ADRESSE DU PTR DU MAILLON QUI LE PRECEDE
{
  int i = 1;
  *p = liste, *q = NULL;
  while (*p != NULL && i != pos) {
    *q = *p;
    *p = suivant_Emprunteur(*p);
    i++;
  }
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

maillon_Emprunteur *AccPos1_Emprunteur(
    int pos, maillon_Emprunteur
                 *liste) // DONNE L'ADRESSE DU PTR DE MAILLON DE POSITION pos
{
  int i = 1;
  maillon_Emprunteur *p = liste;

  while (i != pos && p != NULL) {
    p = suivant_Emprunteur(p);
    i++;
  }
  return p;
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

void viderListe_Emprunteur(
    maillon_Emprunteur **liste) // Libere tout les maillon d'une liste
{
  maillon_Emprunteur *p;
  while (*liste != NULL) {
    p = *liste;
    *liste = suivant_Emprunteur(*liste);
    liberer_Emprunteur(&p);
  }
}

/**--------------------------------------------------------------------------------------------------------------------------------**/
/**--------------------------------------------------------------------------------------------------------------------------------**/
/**---------------------------------------------- MACHINE ABTREATE DE FICHE
 * EMPRUNT -----------------------------------------------**/
/**--------------------------------------------------------------------------------------------------------------------------------**/
/**--------------------------------------------------------------------------------------------------------------------------------**/

void allouer_Emprunt(maillon_Emprunt **nouveau) {
  *nouveau = (maillon_Emprunt *)malloc(sizeof(maillon_Emprunt));
}
/**--------------------------------------------------------------------------------------------------------------------------------**/

void liberer_Emprunt(maillon_Emprunt **ancien) {
  free(*ancien);
  *ancien = NULL;
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

void aff_adr_Emprunt(maillon_Emprunt *p, maillon_Emprunt *q) { p->suiv = q; }

/**--------------------------------------------------------------------------------------------------------------------------------**/

maillon_Emprunt *suivant_Emprunt(maillon_Emprunt *p) { return (p->suiv); }

/**--------------------------------------------------------------------------------------------------------------------------------**/

int longeur_Emprunt(
    maillon_Emprunt *p) /// "LONGEUR" EST UNE FONCTION PERMET DE S'AVOIR LA
                        /// LONGEUR D'UNE LISTE POINTE PAR *P
{
  int l = 0;
  while (p != NULL) {
    p = suivant_Emprunt(p);
    l++;
  }
  return l;
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

void AccPos2_Emprunt(
    int pos, maillon_Emprunt **p, maillon_Emprunt **q,
    maillon_Emprunt *liste) // DONNE L'ADRESSE DU PTR DE MAILLON DE POSITION POS
                            // ET L'ADRESSE DU PTR DU MAILLON QUI LE PRECEDE
{
  int i = 1;
  *p = liste, *q = NULL;
  while (*p != NULL && i != pos) {
    *q = *p;
    *p = suivant_Emprunt(*p);
    i++;
  }
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

maillon_Emprunt *
AccPos1_Emprunt(int pos,
                maillon_Emprunt *
                    liste) /// DONNE L'ADRESSE DU PTR DE MAILLON DE POSITION pos
{
  int i = 1;
  maillon_Emprunt *p = liste;

  while (i != pos && p != NULL) {
    p = suivant_Emprunt(p);
    i++;
  }
  return p;
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

void viderListe_Emprunt(
    maillon_Emprunt **liste) /// Libere tout les maillon d'une liste
{
  maillon_Emprunt *p;
  while (*liste != NULL) {
    p = *liste;
    *liste = suivant_Emprunt(*liste);
    liberer_Emprunt(&p);
  }
}

/**--------------------------------------------------------------------------------------------------------------------------------**/
/**--------------------------------------------------------------------------------------------------------------------------------**/
/**--------------------------------------------------------------------------------------------------------------------------------**/
/**--------------------------------------------------------------------------------------------------------------------------------**/

#endif
