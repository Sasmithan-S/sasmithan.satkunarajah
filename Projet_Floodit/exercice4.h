#ifndef __EXERCICE4__
#define __EXERCICE4__

#include <stdio.h>
#include <stdlib.h>

#include "exercice2.h"

#include "API_Grille.h"
#include "Liste_case.h"

int taille_zone (int ** M, int dim, int i, int j, int cl, int **App_compte);
int max_bordure_zone (int **M, Grille *G, int dim, int nbcl, int aff);

#endif 