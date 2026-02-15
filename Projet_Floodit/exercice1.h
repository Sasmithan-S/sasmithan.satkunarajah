#ifndef __EXERCICE1__
#define __EXERCICE1__

#include "API_Grille.h"
#include "Liste_case.h"


void trouve_zone_rec(int **M, int dim, int i, int j, int *taille, ListeCase *L);
int sequence_aleatoire_rec(int **M, Grille *G, int dim, int nbcl, int aff);

#endif 