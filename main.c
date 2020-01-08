#include "Bib_Graphique.h"
#include "Bib_LLC_BIBLIO.h"
#include "Bib_Standare.h"
#include "Bib_TP.h"
#include "conio.h"
#include "conio2.h"
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void ChioxMenu() {
  int i;
  int a = 4;
  textbackground(colorbackground0);
  textcolor(colorText0);
  char *A[] = {"ESPACE ADMIN", "ESPACE UTILISATEUR", "GUIDE",
               "QUITER ET SAUVERGARDER"};
  int b1 = 3;
  char *B1[] = {"LES LIVRES", "LES EMPREINTEURS", "LES EMPRUNTS"};
  int b2 = 2;
  char *B2[] = {"CONNECTER", "INSCRIT"};
  int c1 = 2;
  char *C1[] = {"AJOUTEZ UN LIVRE", "VOIR LES LIVRES"};
  int c2 = 4;
  char *C2[] = {"LISTE DES EMPRUNTEUR TRIE SELON LE NOMBRE D'EMPRUNT",
                "LISTE DES EMPRUNTEUR", "LISTE DES EMPRUNTEUR PINALISER",
                "LISTE DES EMPRUNTEUR BLOQUER"};
  int c3 = 4;
  char *C3[] = {"LISTE DES EMPRUNTS", "LISTE DES EMPRUNTS EN COURS",
                "LISTE DES EMPRUNTS TERMINER",
                "ECLATER LA FICHIER DES EMPRUNTS EN 2 LISTE"};
  int c4 = 3;
  char *C4[] = {"EMPRUNTER UN LIVRE", "RENDER UN LIVRE", "VOIR LES LIVRES"};
  int d1 = 5;
  char *D1[] = {
      "LISTE DES LIVRES", "LIVRES DISPONIBLES", "LIVRES N'EST PAS DISPONIBLES",
      "LISTE DES LIVRES TRIE SELON LE NOMBRE D'EMPRUNT", "RECHARCHER UN LIVRE"};
  int e1 = 3;
  char *E1[] = {"PAR NUMERO DE COTE", "PAR AUTEUR", "PAR MOT CLE"};
  int quit = 0;
  maillon_Livre *TLivre, *N1, *N2;
  maillon_Emprunteur *TEmprunteur, *T, *NE;
  maillon_Emprunt *TEmprunt, *TEmpruntEnCours, *TEmpruntTerminer;
  Chargement(&TEmprunt, &TLivre, &TEmprunteur);

  do {
    Debut();
    do {
      system("CLS");
      i = Menu(A, a, PX, PY, LNGR, HTR);
      if (i == 0)
        break;
      if (i == 1) {
        /// CHOIX ESPACE ADMIT
        do {
          system("CLS");
          i = Menu(B1, b1, PX, PY, LNGR, HTR);
          if (i == 0)
            break;
          if (i == 1) {
            /// CHOIX LES LIVRES
            do {
              system("CLS");
              i = Menu(C1, c1, PX, PY, LNGR, HTR);
              if (i == 0)
                break;
              if (i == 1) {
                /// CHOIX AJOUTEZ UN LIVRE
                system("CLS");
                AjoutezUnLivre(&TLivre);
              } else if (i == 2) {
                /// CHOIX VOIR LES LIVRES
                do {
                  system("CLS");
                  i = Menu(D1, d1, PX, PY, LNGR, HTR);
                  if (i == 0)
                    break;
                  if (i == 1) {
                    /// CHOIX LISTE DES LIVRES
                    AffichezListeLivre(TLivre);
                  } else if (i == 2) {
                    /// CHOIX LIVRES DISPONIBLES
                    Eclater2ListeLivres(TLivre, &N1, &N2);
                    AffichezListeLivre(N1);
                  } else if (i == 3) {
                    /// CHOIX LIVRES N'EST PAS DISPONIBLES
                    Eclater2ListeLivres(TLivre, &N1, &N2);
                    AffichezListeLivre(N2);
                  } else if (i == 4) {
                    /// CHOIX LISTE DES LIVRES TRIE SELON LE NOMBRE D'EMPRUNT
                    N1 = CopierLivre(TLivre);
                    TrieListe(&N1);
                    AffichezListeLivre(N1);
                  } else if (i == 5) {
                    /// CHOIX RECHARCHER UN LIVRES
                    do {
                      system("CLS");
                      i = Menu(E1, e1, PX, PY, LNGR, HTR);
                      if (i == 0)
                        break;
                      if (i == 1) {
                        /// CHOIX PAR NUMERO DE COTE
                        RecharcheUnLivreCote(TLivre);
                      } else if (i == 2) {
                        /// CHOIX PAR AUTEUR
                        RecharcheUnLivreAuteur(TLivre);
                      } else if (i == 3) {
                        /// CHOIX PAR MOT CLE
                        RecharcheUnLivreMotsCles(TLivre);
                      }
                    } while (1);
                  }
                } while (1);
              }
            } while (1);
          } else if (i == 2) {
            /// CHOIX LES EMPREINTEURS
            do {
              system("CLS");
              i = Menu(C2, c2, PX, PY, LNGR, HTR);
              if (i == 0)
                break;
              if (i == 1) {
                /// CHOIX LISTE DES EMPRUNTEUR TRIE SELON LE NOMBRE D'EMPRUNT
                NE = CopierEmprunteur(TEmprunteur);
                TrieListeEmprunteur(&NE);
                AffichezListeEmprunteur(NE);

              } else if (i == 2) {
                /// CHOIX LISTE DES EMPRUNTEUR
                AffichezListeEmprunteur(TEmprunteur);

              } else if (i == 3) {
                /// CHOIX LISTE DES EMPRUNTEUR PINALISER
                NE = CopierEmprunteur(TEmprunteur);
                CalculePinaliterEncours(&NE);
                AffichezListeEmprunteur(NE);
              } else if (i == 4) {
                /// CHOIX LISTE DES EMPRUNTEUR BLOQUER
                NE = CopierEmprunteurBloquer(TEmprunteur);
                AffichezListeEmprunteur(NE);
              }
            } while (1);

          } else if (i == 3) {
            /// CHOIX LES EMPRUNTS
            do {
              system("CLS");
              i = Menu(C3, c3, PX, PY, LNGR, HTR);
              if (i == 0)
                break;
              if (i == 1) {
                /// CHOIX LISTE DES EMPRUNTS
                AffichezListeEmprunt(TEmprunt);
              } else if (i == 2) {
                /// CHOIX LISTE DES EMPRUNTS EN COURS
                Eclater2ListeEmprunt(TEmprunt, &TEmpruntEnCours,
                                     &TEmpruntTerminer);
                AffichezListeEmprunt(TEmpruntEnCours);
              } else if (i == 3) {
                /// CHOIX LISTE DES EMPRUNTS TERMINER
                Eclater2ListeEmprunt(TEmprunt, &TEmpruntEnCours,
                                     &TEmpruntTerminer);
                AffichezListeEmprunt(TEmpruntTerminer);
              } else if (i == 4) {
                /// CHOIX ECLATER LA FICHIER DES EMPRUNTS EN 2 LISTE
                EclaterEmprunt(TEmprunt);
              }
            } while (1);
          }
        } while (1);
      } else if (i == 2) {
        /// CHOIX ESPACE UTILISATEUR
        do {
          system("CLS");
          i = Menu(B2, b2, PX, PY, LNGR, HTR);
          if (i == 0)
            break;
          if (i == 1) {
            /// CHOIX CONNECTER
            do {
              system("CLS");
              i = Menu(C4, c4, PX, PY, LNGR, HTR);
              if (i == 0)
                break;
              if (i == 1) {
                /// CHOIX EMPRUNTER UN LIVRE
                EmprunterUnLivre(&TEmprunt, &TLivre, &TEmprunteur);
              } else if (i == 2) {
                /// CHOIX RENDER UN LIVRE
                RendreUnLivre(&TLivre);
              } else if (i == 3) {
                /// CHOIX VOIR LES LIVRES
                do {
                  system("CLS");
                  i = Menu(D1, d1, PX, PY, LNGR, HTR);
                  if (i == 0)
                    break;
                  if (i == 1) {
                    /// CHOIX LISTE DES LIVRES
                    AffichezListeLivre(TLivre);
                  } else if (i == 2) {
                    /// CHOIX LIVRES DISPONIBLES
                    Eclater2ListeLivres(TLivre, &N1, &N2);
                    AffichezListeLivre(N1);
                  } else if (i == 3) {
                    /// CHOIX LIVRES N'EST PAS DISPONIBLES
                    Eclater2ListeLivres(TLivre, &N1, &N2);
                    AffichezListeLivre(N2);
                  } else if (i == 4) {
                    /// CHOIX LISTE DES LIVRES TRIE SELON LE NOMBRE D'EMPRUNT
                    N1 = CopierLivre(TLivre);
                    TrieListe(&N1);
                    AffichezListeLivre(N1);
                  } else if (i == 5) {
                    /// CHOIX RECHARCHER UN LIVRES
                    do {
                      system("CLS");
                      i = Menu(E1, e1, PX, PY, LNGR, HTR);
                      if (i == 0)
                        break;
                      if (i == 1) {
                        /// CHOIX PAR NUMERO DE COTE
                        RecharcheUnLivreCote(TLivre);
                      } else if (i == 2) {
                        /// CHOIX PAR AUTEUR
                        RecharcheUnLivreAuteur(TLivre);
                      } else if (i == 3) {
                        /// CHOIX PAR MOT CLE
                        RecharcheUnLivreMotsCles(TLivre);
                      }
                    } while (1);
                  }
                } while (1);
              }
            } while (1);
          } else if (i == 2) {
            /// CHOIX INSCRIT
            InscriptionEmprunteur(&TEmprunteur);
          }
        } while (1);
      } else if (i == 3) {
        /// CHOIX GUIDE
        AffichezGuide();
      } else if (i == 4) {
        /// CHOIX QUITER
        Sauvergarder(&TEmprunt, &TLivre, &TEmprunteur);
        FIN();
        return 1;
      }
    } while (1);
  } while (1);
}

int main() {
  system("mode con LINES=100 COLS=160");
  system("CLS");
  ChioxMenu();

  return 0;
}
