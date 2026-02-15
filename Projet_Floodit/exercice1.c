#include "exercice1.h"
#include <stdio.h>
#include <stdlib.h>

#include "API_Grille.h"
#include "Liste_case.h"


/**Cette fonction permet d’affecter dans la liste chainée L les cases de la zone de la matrice M contenant la meme couleur que la case (i, j) 
et stocke dans la variable taille le nombre de cases dans la zone*/

void trouve_zone_rec(int **M, int dim, int i, int j, int *taille, ListeCase *L){
  // verifie que la case (i,j) ne sort pas de la grille
   if (i<0 || i>=dim||  j<0 || j>=dim  ) {
      return;
   }
   // verifie si la case d'indice (i,j) n'est pas déja dans L 
   ListeCase tmp = *L;
   while (tmp!=NULL){

      if (tmp->i==i && tmp->j==j){
         return;
      }

      tmp=tmp->suiv;
   }

   
   
   ajoute_en_tete(L,i,j); //ajout de la case dans la liste des cases visités 
   (*taille)++;  //incrémente taille de la zone de 1 
  
//appel recursif en dessous de la case (i,j) si on ne sort pas des dimensions
   if (i+1<dim && M[i][j]== M[i+1][j]){
      trouve_zone_rec (M,dim,i+1,j,taille,L);      
   }
//appel recursif au dessus de la case (i,j) on ne sort pas des dimensions
   if (i-1>=0 && M[i][j]== M[i-1][j]){
       trouve_zone_rec (M,dim,i-1,j,taille,L);
      
   } 
//appel recursif à droite de la case (i,j) si on ne sort pas des dimensions

   if (j+1<dim && M[i][j]== M[i][j+1]){
      trouve_zone_rec (M,dim,i,j+1,taille,L);
         
   }
//appel recursif à gauche de la case (i,j) si on ne sort pas des dimensions
   if (j-1>=0 && M[i][j]== M[i][j-1]){
      trouve_zone_rec (M,dim,i,j-1,taille,L);
      }
}



/* Cette fonction joue une s ́equence de jeu al ́etatoire 
 La fonction retourne le nombre de changements de couleurs necessaires pour gagner*/
int sequence_aleatoire_rec(int **M, Grille *G, int dim, int nbcl, int aff){
 
   ListeCase L;
   init_liste(&L);
   int taille =0;
   //Appel qui affecte a L les cases de la meme couleur que la premiàre et seule case de la ZSG (0,0)
   trouve_zone_rec(M,dim,0,0,&taille,&L);
   int t=dim*dim;
   //si la taille de la zone est egale a la taille de la grille on arrete 
   if (t <=taille){
      detruit_liste(&L);
      return 0;
   
   }
   //tirage au sort et stocke dans c une couleur diff ́erente de la couleur de la Zsg .
   int c= rand()%nbcl; 
   while (c==M[0][0]){
      c=rand()%nbcl;
   }     

   ListeCase tmp = L;
   // parcours de la liste pour mettre a jour la matrice avec la nouvelle couleur c
   while(!(test_liste_vide(&tmp))){
      M[tmp->i][tmp->j]=c; 
      tmp=tmp->suiv;
   } 
   //S'il y a l'affichage, on met a jour la grille G
   if (aff == 1){ 
      for (int i=0;i<dim;i++){
         for (int j=0;j<dim;j++){
         Grille_attribue_couleur_case(G,i,j,M[i][j]);     
         } 
      }
      Grille_redessine_Grille(G);      
   } 
   
   //desallocation
   detruit_liste(&L);

   //appel recursif (qui s'arrête donc lorsque toutes les cases de la matrice M seront de la même couleur)
   return 1+sequence_aleatoire_rec(M,G,dim,nbcl,aff);

   

}