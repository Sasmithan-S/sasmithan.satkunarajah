



#include "exercice2.h"
#include <stdio.h>
#include <stdlib.h>

#include "API_Grille.h"
#include "Liste_case.h"



void init_Zsg(int dim, int nbcl,S_Zsg *S ) {
  S->dim = dim;
  S-> nbcl = nbcl;

  init_liste(&(S->Lzsg));
  
  S->B = (ListeCase*) malloc(nbcl*sizeof (ListeCase));
  for (int i=0;i<nbcl;i++){
    init_liste(&(S->B[i]));
  }

  S->App = (int**) malloc(dim*sizeof(int*));
  for (int i=0; i<dim;i++){
    S->App[i] = (int*) malloc(dim*sizeof(int));
  }
  for (int i=0; i<dim;i++){
    for (int j=0; j<dim; j++){
      S->App[i][j] = -2;
    }
  }
}



//ajoute la case (i,j) à la Lzsg 

void ajoute_Zsg(S_Zsg *S,int i, int j){
    //vérification bornes

  if ((i<0 || i>=S->dim) || (j<0 || j>=S->dim)){
      return;
    }
      //Arret si la case appartient deja a Lzsg

  if (S->App[i][j]==-1){
    return;
  }
    //sinon on lajoute et on met a jour App

  else {
    ajoute_en_tete(&(S->Lzsg),i,j);
    S->App[i][j]=-1;
  }
}


//ajoute une case dans la bordure d’une couleur cl donn ́ee

void ajoute_Bordure(S_Zsg *S, int cl,int i,int j){
    //vérification bornes

  if ((i<0 || i>=S->dim) || (j<0 || j>=S->dim)){
      return;
    }
      //arret si la case est deja dans la bordure de couleur cl  

  if (S->App[i][j] == cl){
    return;
  }
    //sinon on l'ajoute et on met a jour App

  ajoute_en_tete(&(S->B[cl]),i,j);
  S->App[i][j]=cl;
}


//renvoie vrai si une case est dans LZsg

int appartient_Zsg(S_Zsg *S,int i,int j){
   if ((i<0 || i>=S->dim) || (j<0 || j>=S->dim)){
     return 0;
    }
   return S->App[i][j]==-1;
}
	

//renvoie vrai si une case est dans la bordure de couleur cl donn ́ee

int appartient_Bordure (S_Zsg *S, int cl,int i,int j){
    if ((i<0 || i>=S->dim) || (j<0 || j>=S->dim)){
      return 0;
    }
    return S->App[i][j]== cl;
}
	

/*+ Met a jour les champs Lzsg et B 
d’une S Zsg lorsque qu’une case k, l de couleur cl, qui est dans la bordure B[cl],
doit basculer dans Lzsg (qui sera colori ́ee de couleur cl).
La fonction retourne le nombre de case qui a  été  ajouté a Lzsg
**/



int agrandit_Zsg(int **M, S_Zsg *Z, int cl, int k, int l) {
  int cpt = 0;
  int i, j;
  int n, s, e, o; // Nord, Sud, Est, Ouest
  int dim = Z->dim;

  //on fait une pile
  ListeCase p;
  init_liste(&p);

  //arret si la case est deja dans la zone
  if (appartient_Zsg(Z, k, l)) {
      return 0;
  }
  //empile la case(k,l) qui sera le point de depart
  ajoute_en_tete(&p, k, l);
  while (!(test_liste_vide(&p))) {
       //depile (stocke dans i et j les indices)
    enleve_en_tete(&p, &i, &j);
      //verification bornes

    if (i >= 0 && i < dim && j >= 0 && j < dim) {  
       
        if (!(appartient_Zsg(Z, i, j))) {  
           
            if (M[i][j] == cl) {  
              
                ajoute_Zsg(Z, i, j);
                cpt++;
                //on va verifier la case voisine d'au dessus, en dessous, a droite et a gauche 
                n = i - 1;
                s = i + 1;
                e = j + 1;
                o = j - 1;
               
                // --- NORD ---
                if (n >= 0) {
                    if (!(appartient_Zsg(Z, n, j))) {
                        if ((M[n][j]) == cl) {
                            //empile case si la case appartient pas deja a ZSG et quelle est de la couleur cl
                            ajoute_en_tete(&p, n, j);
                        }
                        else {
                            //sinon la case est une bordure donc on l'ajoute dans B
                            if (!(appartient_Bordure(Z, M[n][j], n, j))) {
                                ajoute_Bordure(Z, M[n][j], n, j);  
                            }
                        }
                    }
                }
                 //meme principe pour les autres cases voisines
                // --- SUD ---
                if (s < dim) {
                    if (!(appartient_Zsg(Z, s, j))) {
                        if ((M[s][j]) == cl) {
                            ajoute_en_tete(&p, s, j);
                        } else {
                            if (!(appartient_Bordure(Z, M[s][j], s, j))) {
                                ajoute_Bordure(Z, M[s][j], s, j);
                            }
                        }
                    }
                }
               
                // --- OUEST  ---
                if (o >= 0) {
                    if (!(appartient_Zsg(Z, i, o))) {
                        if ((M[i][o]) == cl) {
                            ajoute_en_tete(&p, i, o);
                        } else {
                            if (!(appartient_Bordure(Z, M[i][o], i, o))) {
                                ajoute_Bordure(Z, M[i][o], i, o);
                            }
                        }
                    }
                }
               
                // --- EST  ---
                if (e < dim) {
                    if (!(appartient_Zsg(Z, i, e))) {
                        if ((M[i][e]) == cl) {
                            ajoute_en_tete(&p, i, e);
                        } else {
                            if (!(appartient_Bordure(Z, M[i][e], i, e))) {
                                ajoute_Bordure(Z, M[i][e], i, e);
                            }
                        }
                    }
                }
               
            } 
        } 
    } 
  }
 
  detruit_liste(&p);  
  return cpt;
}

int sequance_aleatoire_rapide(int **M, Grille *G, int dim, int nbcl, int aff) {
    S_Zsg Z;
    int taille = 0;
    int cpt = 0;        
    int cl;             
    ListeCase tmp;
        


    init_Zsg(dim, nbcl, &Z); 
    //la couleur de la Zsg est celle de la seule case présente 
    cl = M[0][0]; 
    //appel de la fonction pour les valeurs initiales de la zone Zsg et de sa bordure
    taille = taille + agrandit_Zsg(M, &Z, cl, 0, 0);
    //on s'arrete lorsque la taille de la bordure=nombre de cases

    while (taille < dim * dim) {
        cpt++; 

        
        int c = rand() % nbcl;
        while (c == cl) {
            c = rand() % nbcl;
        }


        tmp = Z.Lzsg;
        //met a jour couleur de la zsg

        while (!test_liste_vide(&tmp)) {
            M[tmp->i][tmp->j] = c; 
              if (aff==1){
                Grille_attribue_couleur_case(G, tmp->i, tmp->j, c);

              }
            tmp = tmp->suiv;
          }

          //on s'occupe de la bordure pour agrandir la zone


          ListeCase tmp2=Z.B[c];
          init_liste(&(Z.B[c]));
          tmp=tmp2;

          while(!(test_liste_vide(&tmp))){
            taille += agrandit_Zsg(M, &Z, c, tmp->i, tmp->j);
            tmp=tmp->suiv;
          }

          cl=c;



        detruit_liste(&tmp2);
        
        if (aff == 1) { 
        Grille_redessine_Grille(G);
         

      }
  }

  detruit_liste(&Z.Lzsg);
  
  for (int i = 0; i < nbcl; i++) {
    detruit_liste(&Z.B[i]);
  }
  free(Z.B);

  for (int i = 0; i < dim; i++) {
    free(Z.App[i]);
  }
  free(Z.App);

  return cpt;
}