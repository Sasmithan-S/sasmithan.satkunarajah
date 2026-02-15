#include "exercice2.h"
#include "exercice3.h"
#include <stdio.h>
#include <stdlib.h>

#include "API_Grille.h"
#include "Liste_case.h"

// la fonction remplit occ[] avec le nombre de cases dans la bordure par couleur et 
// retourne le nombre de couleurs dans la bordure

int occurence_couleur_bordure (S_Zsg *S, int occ[]){
   int taille=0;
   int cl=S->nbcl;
     //parmi tt les couleurs dans la bordure
    for ( int i = 0; i< cl; i++){
       occ[i] = 0;  
        ListeCase tmp = S->B[i];
        while (tmp != NULL){
            occ[i]++;
            tmp = tmp->suiv;        
         } 
      if (occ[i]!=0){
         taille ++;
      }   
   } 
   return taille;
} 



int max_bordure(int **M, Grille *G, int dim, int nbcl, int aff) {
   S_Zsg Z;
   int cl=M[0][0];//couleur actuel de la ZSG
   init_Zsg(dim,nbcl,&Z); //initilialisation Z
   agrandit_Zsg(M,&Z,cl,0,0); //recupère les premières bordures
   int cpt=0; //compteur nbre de coups
   int occurences_tab[nbcl]; //tableau des occurences
   
   while (occurence_couleur_bordure(&Z,occurences_tab)) {
      cpt++;
      int max_couleur=-1;
      int max_occur=-1;
      //recherche de l'indice  du max du tableau et la couleur correspondante
      for (int i=0;i<nbcl;i++){
         if (occurences_tab[i]>max_occur){
            max_couleur=i;
            max_occur = occurences_tab[i];
         }
      }
  
      if (aff==1){
         ListeCase tmp_aff=Z.Lzsg;
         while(tmp_aff!=NULL) {
            M[tmp_aff->i][tmp_aff->j]=max_couleur;
            Grille_attribue_couleur_case(G,tmp_aff->i,tmp_aff->j,max_couleur);
            tmp_aff=tmp_aff->suiv;
         }

      }

      //s'il n'y a pas d'affichage, le jeu se termine quand il n'y a pas de bordure donc pas besoin de mettre a jours M
      ListeCase tmp= Z.B[max_couleur];
      init_liste(&Z.B[max_couleur]);
      ListeCase tmp2 = tmp;
      while(tmp2!=NULL){
            agrandit_Zsg(M,&Z,max_couleur,tmp2->i,tmp2->j);
            tmp2=tmp2->suiv;
            }
      
      if (aff==1){
         Grille_redessine_Grille(G);
      }
      detruit_liste(&tmp);
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

