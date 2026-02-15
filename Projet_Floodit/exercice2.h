#ifndef __EXERCICE2__
#define __EXERCICE2__

#include "API_Grille.h"
#include "Liste_case.h"

typedef struct {
  int dim ; /* dimension de la grille */
  int nbcl ; /* nombre de couleurs */

  ListeCase Lzsg ; /* Liste des cases de la zone Zsg */
  ListeCase * B ; /* Tableau de listes de cases de la bordure*/
  int ** App ; /* Tableau a double entree des appartenances */

} S_Zsg ;

void init_Zsg(int dim, int nbcl,S_Zsg *S);
void ajoute_Zsg(S_Zsg *S,int i, int j);
void ajoute_Bordure(S_Zsg *S, int cl,int i,int j);
int appartient_Zsg(S_Zsg *S,int i,int j);
int appartient_Bordure (S_Zsg *S, int cl,int i,int j);
int agrandit_Zsg(int **M, S_Zsg *Z, int cl, int k, int l);
int sequance_aleatoire_rapide(int **M, Grille *G, int dim, int nbcl, int aff);

#endif 