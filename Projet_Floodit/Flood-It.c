#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "API_Grille.h"
#include "API_Gene_instance.h"
#include "Liste_case.h"
#include "exercice1.h"
#include "exercice2.h"
#include "exercice3.h"
#include "exercice4.h"
#include "graphe.h"



int main(int argc,char**argv){

  int dim, nbcl, nivdif, graine, exo, aff,graph;
  Grille *G;
  int i,j;
  int **M;
  int taille =0;
  ListeCase L;
  init_liste(&L);
  
  clock_t
    temps_initial, /* Temps initial en micro-secondes */
    temps_final;   /* Temps final en micro-secondes */
  float
    temps_cpu;     /* Temps total en secondes */ 

  if(argc!=8){
    printf("usage: %s <dimension> <nb_de_couleurs> <niveau_difficulte> <graine> <exo:0-1-2> <aff 0/1> <graph 0/1>\n",argv[0]);
    return 1;
  }

  dim=atoi(argv[1]);
  nbcl=atoi(argv[2]);
  nivdif=atoi(argv[3]);
  graine=atoi(argv[4]);
  exo=atoi(argv[5]);
  aff=atoi(argv[6]);
  graph=atoi(argv[7]);

  /* Allocation puis generation de l'instance */

  M=(int **) malloc(sizeof(int*)*dim);
  for (i=0;i<dim;i++){
    M[i]=(int*) malloc(sizeof(int)*dim);
    if (M[i]==0) printf("Pas assez d'espace mémoire disponible\n");
  }

  Gene_instance_genere_matrice(dim, nbcl, nivdif, graine, M);

  

  if (aff==1){ /* Affichage de la grille */
    Grille_init(dim,nbcl, 500,&G);
    Grille_ouvre_fenetre(G);
    for (i=0;i<dim;i++)
      for (j=0;j<dim;j++){
	      Grille_attribue_couleur_case(G,i,j,M[i][j]);
      }
     Grille_redessine_Grille(G);
    // Grille_attente_touche();
  }

  temps_initial = clock ();
  
  //////////////////////////////////////
  //Appel des fonctions pzr exercice

  if (exo==0){
    trouve_zone_rec(M,dim,0,0,&taille,&L);
    printf("taille_zone: %d \n",taille);
    detruit_liste(&L);
  }

  if (exo==1){
    int nb_coups = sequence_aleatoire_rec(M, G, dim, nbcl, aff);
    printf("%d coups_rec \n", nb_coups); 
    if (graph==1) {
      graphiques_exo1_nbcl(dim,G,graine);
      graphiques_exo1_dim(nbcl,G,graine);

      graphiques_exo1_nbcl_coups(dim,G,graine);
      graphiques_exo1_dim_coups(nbcl,G,graine);
    }
  }

  if (exo==2){
    int nb_coups = sequance_aleatoire_rapide(M,G,dim,nbcl,aff);
    printf("%d coups_rapi \n", nb_coups);
    if (graph==1){
      graphiques_exo2_nbcl(dim,G,graine);
      graphiques_exo2_dim(nbcl,G,graine);  

      graphiques_exo2_nbcl_coups(dim,G,graine);
      graphiques_exo2_dim_coups(nbcl,G,graine);
      
    }  
  }

  if(exo==3){
    int nb_coups = max_bordure(M,G,dim,nbcl,aff);
    printf("%d coups_max_bordur \n", nb_coups);
    if (graph==1){
      graphiques_exo3_nbcl(dim,G,graine);
      graphiques_exo3_dim(nbcl,G,graine);  

      graphiques_exo3_nbcl_coups(dim,G,graine);
      graphiques_exo3_dim_coups(nbcl,G,graine);
    } 

  }

  if(exo==4){
    int nb_coups = max_bordure_zone(M,G,dim,nbcl,aff);
    printf("%d coups_max_bordurzone \n", nb_coups);
    if (graph==1){
      graphiques_exo4_nbcl(dim,G,graine);
      graphiques_exo4_dim(nbcl,G,graine);  

      graphiques_exo4_nbcl_coups(dim,G,graine);
      graphiques_exo4_dim_coups(nbcl,G,graine);
    } 

  }


  ///////////////////////////
  
  temps_final = clock ();
  temps_cpu = (temps_final - temps_initial) * 1e-6;
  printf("temps_cpu = %f\n",temps_cpu);

  
 /* Desallocation de la matrice */
  for(i = 0; i< dim; i++) {
    if (M[i]) 
      free(M[i]);
  }
  if (M) free(M);

  
  if (aff==1){ /* Fermeture et désallocation de la grille */
    Grille_ferme_fenetre();
    Grille_free(&G);
  }

  return 0;
}






