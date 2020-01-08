#ifndef _Bib_Standare_H_
#define _Bib_Standare_H_

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int Max(int a, int b) {
  if (a < b)
    return b;
  else
    return a;
}
int Min(int a, int b) {
  if (a > b)
    return b;
  else
    return a;
}
char *UpperCase(char t[]) {

  /// TRANFERT LES LETTRES EN MINISCULE

  char p[2000];
  int i = 0;
  while (t[i] != 0) {
    p[i] = toupper(t[i]);
    i++;
  }
  p[i] = 0;
  return p;
}
void InitializerTableauxInt(int t[][50], int n, int n2, int m) {
  /// Initializer un tableaux de n*n2 cases par valeurs m
  int i, j;
  for (i = 0; i < n; i++)
    for (j = 0; j < n2; j++)
      t[i][j] = m;
}
int MaxJour(int y, int m) {

  /** DONNEZ LE MAXIMAN JOUR DE LA MOIS
   ** IL PRENDS COMPS LE ANNES DES 29 ET 28 FIVIRIER
   **/

  switch (m) {

  case 1:
    return 31;
  case 2:
    return ((y % 4) == 0) ? 29 : 28;
  case 3:
    return 31;
  case 4:
    return 30;
  case 5:
    return 31;
  case 6:
    return 30;
  case 7:
    return 31;
  case 8:
    return 31;
  case 9:
    return 30;
  case 10:
    return 31;
  case 11:
    return 30;
  case 12:
    return 31;
  }
}
char *LowerCase(char t[]) {

  /// TRANFERT LES LETTRES EN MINISCULE

  char p[2000];
  int i = 0;
  while (t[i] != 0) {
    p[i] = tolower(t[i]);
    i++;
  }
  p[i] = 0;
  return p;
}
void SupprimerChar(char m[], int Taille, int pos) {

  /** SUPPERMER UN CARACTERE A LA POSTION POS
   ** FAIRE DECALER LE RESTE DE CARACTERE APRES POSTION POS
   **/

  int i;
  for (i = pos; i < (Taille - 1); i++)
    m[i] = m[i + 1];
  m[Taille - 1] = 0;
}
int NbreMot(char ch[]) {

  /// COMPTER LE NOMBRE DES MOTS DANS CHAIN CH

  int cpt = 0, i = 0, rep = 0;
  while (ch[i] != 0) {
    if (ch[i] == ' ') {
      if (!rep)
        cpt++;
      rep = 1;
    } else
      rep = 0;
    i++;
  }
  if (!rep)
    cpt++;
  return cpt;
}
void AjoutezChar(char m[], int Taille, int pos, char c) {

  /** AJOUTEZ UN CARACTERE C A LA POSTION POS
   ** FAIRE DECALER A GAUCHE LE RESTE DE CARACTERE APRES POSTION POS
   **/

  int i;
  for (i = Taille - 1; i >= pos; i--)
    m[i + 1] = m[i];
  m[pos] = c;
  m[Taille + 1] = 0;
}
void DecopPhrase(char ch[], char *m[], int *NbrMot) {

  /// DECOPOSER PHRASE EN MOTS

  (*NbrMot) = 0;
  int i = 0, j = 0, rep = 1;
  m[(*NbrMot)] = malloc(20 * sizeof(char));
  while (ch[i] != 0) {
    if (ch[i] == ' ') {
      if (!rep) {
        m[*NbrMot][j] = 0;
        (*NbrMot)++;
        m[(*NbrMot)] = malloc(20 * sizeof(char));
        j = 0;
      }
      rep = 1;
    } else {
      rep = 0;
      m[(*NbrMot)][j] = ch[i];
      j++;
    }
    i++;
  }
  m[*NbrMot][j] = 0;
  (*NbrMot)++;
}
void DateDeRetour(int *jour, int *mois, int *anne, int NbreJour) {

  /** AJOUTEZ NbreJour A LA DATE JOUR/MOIS/ANNEE
   **/

  int i;
  do {
    i = MaxJour(*anne, *mois);
    if ((NbreJour + (*jour)) > i) {
      (*mois)++;
      NbreJour = NbreJour - i + (*jour) - 1;
      (*jour) = 1;
      if (*mois > 12) {
        (*anne)++;
        (*mois) = 1;
      }
    } else
      break;
  } while (NbreJour > 0);
  (*jour) += NbreJour;
}
void RamplcerCracrter(char *t, char a, char b) {

  /// RAMPLACER CRACRTER A PAR B SI IL EXISTE DANS T

  int i = 0;
  while (t[i] != 0) {
    if (t[i] == a)
      t[i] = b;
    i++;
  }
}
int DiffiranceEntre2Date(int jour1, int mois1, int annee1, int jour2, int mois2,
                         int annee2) {

  /** CALCULE LE NOMBRE DE JOUR QUE DATE1 ARRIVE A DATE2
   ** C'EST LA DATE1 DEJA DEPASSER DATE2 ON RETURN 0
   **/

  if (annee1 > annee2)
    return 0;
  if ((annee1 == annee2) && (mois1 > mois2))
    return 0;
  if ((annee1 == annee2) && (mois1 == mois2) && (jour1 >= jour2))
    return 0;
  int i = 0;
  do {
    i++;
    DateDeRetour(&jour1, &mois1, &annee1, 1);
  } while ((annee1 < annee2) || (mois1 < mois2) || (jour1 < jour2));
  return i;
}
int strstrcase(char *ch, char *rh) {

  /// RECHARCHEZ C'EST RH EXISTE DANS CH ET INGORER LE UPPER CASE

  int i = 0, j = 0;
  while (ch[i] != 0 && rh[j] != 0) {
    if (tolower(ch[i]) == tolower(rh[j]))
      j++;
    else {
      j = 0;
      if (tolower(ch[i]) == tolower(rh[j]))
        j++;
    }
    i++;
  }
  if (rh[j] == 0)
    return 1;
  else
    return 0;
}

#endif
