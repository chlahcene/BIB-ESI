#ifndef _Bib_LLC_BIBLIO1_H_
#define _Bib_LLC_BIBLIO2_H_

#include "Bib_LLC_BIBLIO.h"
#include <stdio.h>
#include <stdlib.h>

/**--------------------------------------------------------------------------------------------------------------------------------**/

void aff_adr_Livre(maillon_Livre *p, maillon_Livre *q) { p->suiv = q; }

/**--------------------------------------------------------------------------------------------------------------------------------**/

void aff_cote_Livre(maillon_Livre *p, int cote) { p->cote = cote; }

/**--------------------------------------------------------------------------------------------------------------------------------**/

void aff_dateEdition_Livre(maillon_Livre *p, struct date dateEdition) {
  p->dateEdition.days = dateEdition.days;
  p->dateEdition.month = dateEdition.month;
  p->dateEdition.years = dateEdition.years;
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

void aff_dateEdition_days_Livre(maillon_Livre *p, int days) {
  p->dateEdition.days = days;
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

void aff_dateEdition_month_Livre(maillon_Livre *p, int month) {
  p->dateEdition.month = month;
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

void aff_dateEdition_years_Livre(maillon_Livre *p, int years) {
  p->dateEdition.years = years;
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

void aff_titre_Livre(maillon_Livre *p, char titre[]) {
  sprintf(p->titre, "%s", titre);
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

void aff_auteur_Livre(maillon_Livre *p, char auteur[]) {
  sprintf(p->auteur, "%s", auteur);
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

void aff_editeur_Livre(maillon_Livre *p, char editeur[]) {
  sprintf(p->editeur, "%s", editeur);
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

void aff_motCle_Livre(maillon_Livre *p, char motCle[]) {
  sprintf(p->motCle, "%s", motCle);
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

void aff_resume_Livre(maillon_Livre *p, char resume[]) {
  sprintf(p->resume, "%s", resume);
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

int valeur_cote_Livre(maillon_Livre *p) { return (p->cote); }

/**--------------------------------------------------------------------------------------------------------------------------------**/

struct date valeur_dateEdition_Livre(maillon_Livre *p) {
  return (p->dateEdition);
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

int valeur_dateEdition_days_Livre(maillon_Livre *p) {
  return (p->dateEdition.days);
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

int valeur_dateEdition_month_Livre(maillon_Livre *p) {
  return (p->dateEdition.month);
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

int valeur_dateEdition_years_Livre(maillon_Livre *p) {
  return (p->dateEdition.years);
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

char *valeur_titre_Livre(maillon_Livre *p) { return (p->titre); }

/**--------------------------------------------------------------------------------------------------------------------------------**/

char *valeur_auteur_Livre(maillon_Livre *p) { return (p->auteur); }

/**--------------------------------------------------------------------------------------------------------------------------------**/

char *valeur_editeur_Livre(maillon_Livre *p) { return (p->editeur); }

/**--------------------------------------------------------------------------------------------------------------------------------**/

char *valeur_motCle_Livre(maillon_Livre *p) { return (p->motCle); }

/**--------------------------------------------------------------------------------------------------------------------------------**/

char *valeur_resume_Livre(maillon_Livre *p) { return (p->resume); }

/**--------------------------------------------------------------------------------------------------------------------------------**/

void aff_adr_Emprunteur(maillon_Emprunteur *p, maillon_Emprunteur *q) {
  p->suiv = q;
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

void aff_ordreInscription_Emprunteur(maillon_Emprunteur *p,
                                     int ordreInscription) {
  p->ordreInscription = ordreInscription;
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

void aff_penalite_Emprunteur(maillon_Emprunteur *p, int penalite) {
  p->penalite = penalite;
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

void aff_dateDeInscription_Emprunteur(maillon_Emprunteur *p,
                                      struct date dateDeInscription) {
  p->dateDeInscription.days = dateDeInscription.days;
  p->dateDeInscription.month = dateDeInscription.month;
  p->dateDeInscription.years = dateDeInscription.years;
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

void aff_dateDeInscription_days_Emprunteur(maillon_Emprunteur *p, int days) {
  p->dateDeInscription.days = days;
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

void aff_dateDeInscription_month_Emprunteur(maillon_Emprunteur *p, int month) {
  p->dateDeInscription.month = month;
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

void aff_dateDeInscription_years_Emprunteur(maillon_Emprunteur *p, int years) {
  p->dateDeInscription.years = years;
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

void aff_nom_Emprunteur(maillon_Emprunteur *p, char nom[]) {
  sprintf(p->nom, "%s", nom);
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

void aff_prenom_Emprunteur(maillon_Emprunteur *p, char prenom[]) {
  sprintf(p->prenom, "%s", prenom);
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

void aff_adresseActuelle_Emprunteur(maillon_Emprunteur *p,
                                    char adresseActuelle[]) {
  sprintf(p->adresseActuelle, "%s", adresseActuelle);
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

void aff_nDeTelephone_Emprunteur(maillon_Emprunteur *p, char nDeTelephone[]) {
  sprintf(p->nDeTelephone, "%s", nDeTelephone);
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

int valeur_ordreInscription_Emprunteur(maillon_Emprunteur *p) {
  return (p->ordreInscription);
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

int valeur_penalite_Emprunteur(maillon_Emprunteur *p) { return (p->penalite); }

/**--------------------------------------------------------------------------------------------------------------------------------**/

struct date valeur_dateDeInscription_Emprunteur(maillon_Emprunteur *p) {
  return (p->dateDeInscription);
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

int valeur_dateDeInscription_days_Emprunteur(maillon_Emprunteur *p) {
  return (p->dateDeInscription.days);
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

int valeur_dateDeInscription_month_Emprunteur(maillon_Emprunteur *p) {
  return (p->dateDeInscription.month);
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

int valeur_dateDeInscription_years_Emprunteur(maillon_Emprunteur *p) {
  return (p->dateDeInscription.years);
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

char *valeur_nom_Emprunteur(maillon_Emprunteur *p) { return (p->nom); }

/**--------------------------------------------------------------------------------------------------------------------------------**/

char *valeur_prenom_Emprunteur(maillon_Emprunteur *p) { return (p->prenom); }

/**--------------------------------------------------------------------------------------------------------------------------------**/

char *valeur_adresseActuelle_Emprunteur(maillon_Emprunteur *p) {
  return (p->adresseActuelle);
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

char *valeur_nDeTelephone_Emprunteur(maillon_Emprunteur *p) {
  return (p->nDeTelephone);
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

void aff_adr_Emprunt(maillon_Emprunt *p, maillon_Emprunt *q) { p->suiv = q; }

/**--------------------------------------------------------------------------------------------------------------------------------**/

void aff_Emprunteur_Emprunt(maillon_Emprunt *p,
                            maillon_Emprunteur *Emprunteur) {
  p->Emprunteur = Emprunteur;
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

void aff_livreEmprunte_Emprunt(maillon_Emprunt *p,
                               maillon_Livre *livreEmprunte) {
  p->livreEmprunte = livreEmprunte;
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

void aff_livreRendu_Emprunt(maillon_Emprunt *p, int livreRendu) {
  p->livreRendu = livreRendu;
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

void aff_dateDeEmprunt_Emprunt(maillon_Emprunt *p, struct date dateDeEmprunt) {
  p->dateDeEmprunt.days = dateDeEmprunt.days;
  p->dateDeEmprunt.month = dateDeEmprunt.month;
  p->dateDeEmprunt.years = dateDeEmprunt.years;
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

void aff_dateDeEmprunt_days_Emprunt(maillon_Emprunt *p, int days) {
  p->dateDeEmprunt.days = days;
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

void aff_dateDeEmprunt_month_Emprunt(maillon_Emprunt *p, int month) {
  p->dateDeEmprunt.month = month;
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

void aff_dateDeEmprunt_years_Emprunt(maillon_Emprunt *p, int years) {
  p->dateDeEmprunt.years = years;
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

void aff_dateDeRetour_Emprunt(maillon_Emprunt *p, struct date dateDeRetour) {
  p->dateDeRetour.days = dateDeRetour.days;
  p->dateDeRetour.month = dateDeRetour.month;
  p->dateDeRetour.years = dateDeRetour.years;
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

void aff_dateDeRetour_days_Emprunt(maillon_Emprunt *p, int days) {
  p->dateDeRetour.days = days;
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

void aff_dateDeRetour_month_Emprunt(maillon_Emprunt *p, int month) {
  p->dateDeRetour.month = month;
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

void aff_dateDeRetour_years_Emprunt(maillon_Emprunt *p, int years) {
  p->dateDeRetour.years = years;
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

maillon_Emprunteur *valeur_Emprunteur_Emprunt(maillon_Emprunt *p) {
  return (p->Emprunteur);
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

maillon_Livre *valeur_livreEmprunte_Emprunt(maillon_Emprunt *p) {
  return (p->livreEmprunte);
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

int valeur_livreRendu_Emprunt(maillon_Emprunt *p) { return (p->livreRendu); }

/**--------------------------------------------------------------------------------------------------------------------------------**/

struct date valeur_dateDeEmprunt_Emprunt(maillon_Emprunt *p) {
  return (p->dateDeEmprunt);
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

int valeur_dateDeEmprunt_days_Emprunt(maillon_Emprunt *p) {
  return (p->dateDeEmprunt.days);
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

int valeur_dateDeEmprunt_month_Emprunt(maillon_Emprunt *p) {
  return (p->dateDeEmprunt.month);
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

int valeur_dateDeEmprunt_years_Emprunt(maillon_Emprunt *p) {
  return (p->dateDeEmprunt.years);
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

struct date valeur_dateDeRetour_Emprunt(maillon_Emprunt *p,
                                        struct date dateDeRetour) {
  return (p->dateDeRetour);
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

int valeur_dateDeRetour_days_Emprunt(maillon_Emprunt *p) {
  return (p->dateDeRetour.days);
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

int valeur_dateDeRetour_month_Emprunt(maillon_Emprunt *p) {
  return (p->dateDeRetour.month);
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

int valeur_dateDeRetour_years_Emprunt(maillon_Emprunt *p) {
  return (p->dateDeRetour.years);
}

/**--------------------------------------------------------------------------------------------------------------------------------**/

#endif
