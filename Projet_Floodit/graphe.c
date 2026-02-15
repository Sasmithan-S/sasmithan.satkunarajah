#include "exercice1.h"
#include "exercice2.h"
#include "exercice3.h"
#include "exercice4.h"
#include "API_Gene_instance.h"
#include <time.h>

//TEMPS!! 

//nbcl varie
//Analyse de la fonction sequence_aleatoire_rec pour nbcl de 25 à 125 de 10 en 10
void graphiques_exo1_nbcl(int dim,Grille *G, int graine) {
  FILE * fic = fopen ( "Courbes/donnees/temps/donnees_exo1_nbcl.txt" ,"w") ; 
  int **M;
  clock_t debut , fin ;
  double temps ;
  int aff=0;
  int nivdif = 5;
  for ( int nbcl=25; nbcl < 125; nbcl += 10) {
    M=(int **) malloc(sizeof(int*)*dim);
    for (int i=0;i<dim;i++){
      M[i]=(int*) malloc(sizeof(int)*dim);
        if (M[i]==0) {
          printf("Pas assez d'espace mémoire disponible\n");
       }
    }   
    Gene_instance_genere_matrice(dim, nbcl, nivdif, graine, M);
    debut = clock () ;
    sequence_aleatoire_rec(M, G, dim, nbcl, aff);
    fin = clock () ;
    temps = (( double ) ( fin - debut ) ) / CLOCKS_PER_SEC ;
    fprintf ( fic , "%d %f \n" , nbcl , temps ) ; 
    for(int i = 0; i< dim; i++) {
      if (M[i]) 
        free(M[i]);
      }
      if (M) {
         free(M);
      } 
      graine++; // incrémente la graine pour generer une nouvelle matrice 
  } 
  fclose ( fic ) ;
  
}  

//Analyse de la fonction sequance_aleatoire_rapide pour nbcl de 25 à 125 de 10 en 10
void graphiques_exo2_nbcl(int dim,Grille *G, int graine) {
  FILE * fic = fopen ("Courbes/donnees/temps/donnees_exo2_nbcl.txt" ,"w") ; 
  int **M;
  clock_t debut , fin ;
  double temps ;
  int aff=0;
  int nivdif = 5;
  for (int nbcl=25; nbcl < 125; nbcl += 10) {
    M=(int **) malloc(sizeof(int*)*dim);
    for (int i=0;i<dim;i++){
      M[i]=(int*) malloc(sizeof(int)*dim);
        if (M[i]==0) {
          printf("Pas assez d'espace mémoire disponible\n");
       }
    }   
    Gene_instance_genere_matrice(dim, nbcl, nivdif, graine, M);
    debut = clock () ;
    sequance_aleatoire_rapide(M, G, dim, nbcl, aff);
    fin = clock () ;
    temps = (( double ) ( fin - debut ) ) / CLOCKS_PER_SEC ;
    fprintf ( fic , "%d %f \n" , nbcl , temps ) ; 
    for(int i = 0; i< dim; i++) {
      if (M[i]) 
        free(M[i]);
      }
      if (M) {
         free(M);
      } 
      graine++; // incrémente la graine pour generer une nouvelle matrice 
  } 
  fclose ( fic ) ;
  
} 

//Analyse de la fonction max_bordure pour nbcl de 25 à 125 de 10 en 10
void graphiques_exo3_nbcl(int dim,Grille *G, int graine) {
  FILE * fic = fopen ("Courbes/donnees/temps/donnees_exo3_nbcl.txt" ,"w") ; 
  int **M;
  clock_t debut , fin ;
  double temps ;
  int aff=0;
  int nivdif = 5;
  for (int nbcl=25; nbcl < 125; nbcl += 10) {
    M=(int **) malloc(sizeof(int*)*dim);
    for (int i=0;i<dim;i++){
      M[i]=(int*) malloc(sizeof(int)*dim);
        if (M[i]==0) {
          printf("Pas assez d'espace mémoire disponible\n");
       }
    }   
    Gene_instance_genere_matrice(dim, nbcl, nivdif, graine, M);
    debut = clock () ;
    max_bordure(M, G, dim, nbcl, aff);
    fin = clock () ;
    temps = (( double ) ( fin - debut ) ) / CLOCKS_PER_SEC ;
    fprintf ( fic , "%d %f \n" , nbcl , temps ) ; 
    for(int i = 0; i< dim; i++) {
      if (M[i]) 
        free(M[i]);
      }
      if (M) {
         free(M);
      } 
      graine++; // incrémente la graine pour generer une nouvelle matrice 
  } 
  fclose ( fic ) ;
  
} 

//Analyse de la fonction max_bordure_zone pour nbcl de 25 à 125 de 10 en 10
void graphiques_exo4_nbcl(int dim,Grille *G, int graine) {
  FILE * fic = fopen ("Courbes/donnees/temps/donnees_exo4_nbcl.txt" ,"w") ; 
  int **M;
  clock_t debut , fin ;
  double temps ;
  int aff=0;
  int nivdif = 5;
  for (int nbcl=25; nbcl < 125; nbcl += 10) {
    M=(int **) malloc(sizeof(int*)*dim);
    for (int i=0;i<dim;i++){
      M[i]=(int*) malloc(sizeof(int)*dim);
        if (M[i]==0) {
          printf("Pas assez d'espace mémoire disponible\n");
       }
    }   
    Gene_instance_genere_matrice(dim, nbcl, nivdif, graine, M);
    debut = clock () ;
    max_bordure_zone(M, G, dim, nbcl, aff);
    fin = clock () ;
    temps = (( double ) ( fin - debut ) ) / CLOCKS_PER_SEC ;
    fprintf ( fic , "%d %f \n" , nbcl , temps ) ; 
    for(int i = 0; i< dim; i++) {
      if (M[i]) 
        free(M[i]);
      }
      if (M) {
         free(M);
      } 
      graine++; // incrémente la graine pour generer une nouvelle matrice 
  } 
  fclose ( fic ) ;
  
} 


//dim varie
//Analyse de la fonction sequence_aleatoire_rec pour dim de 25 à 125 de 10 en 10
void graphiques_exo1_dim(int nbcl,Grille *G, int graine) {
  FILE * fic = fopen ("Courbes/donnees/temps/donnees_exo1_dim.txt" ,"w") ; 
  int **M;
  clock_t debut , fin ;
  double temps ;
  int aff=0;
  int nivdif = 5;
  for ( int dim=25; dim <125; dim += 10) {
    M=(int **) malloc(sizeof(int*)*dim);
    for (int i=0;i<dim;i++){
      M[i]=(int*) malloc(sizeof(int)*dim);
        if (M[i]==0) {
          printf("Pas assez d'espace mémoire disponible\n");
       }
    }   
    Gene_instance_genere_matrice(dim, nbcl, nivdif, graine, M);
    debut = clock () ;
    sequence_aleatoire_rec(M, G, dim, nbcl, aff);
    fin = clock () ;
    temps = (( double ) ( fin - debut ) ) / CLOCKS_PER_SEC ;
    fprintf ( fic , "%d %f \n" , dim , temps ) ; 
    for(int i = 0; i< dim; i++) {
      if (M[i]) 
        free(M[i]);
      }
      if (M) {
         free(M);
      } 
      graine++; // incrémente la graine pour generer une nouvelle matrice 
  } 
  fclose ( fic ) ;
  
}

//Analyse de la fonction sequance_aleatoire_rapide pour dim de 25 à 125 de 10 en 10
void graphiques_exo2_dim(int nbcl,Grille *G, int graine) {
  FILE * fic = fopen ("Courbes/donnees/temps/donnees_exo2_dim.txt" ,"w") ; 
  int **M;
  clock_t debut , fin ;
  double temps ;
  int aff=0;
  int nivdif = 5;
  for ( int dim=25; dim <125; dim += 10) {
    M=(int **) malloc(sizeof(int*)*dim);
    for (int i=0;i<dim;i++){
      M[i]=(int*) malloc(sizeof(int)*dim);
        if (M[i]==0) {
          printf("Pas assez d'espace mémoire disponible\n");
       }
    }   
    Gene_instance_genere_matrice(dim, nbcl, nivdif, graine, M);
    debut = clock () ;
    sequance_aleatoire_rapide(M, G, dim, nbcl, aff);
    fin = clock () ;
    temps = (( double ) ( fin - debut ) ) / CLOCKS_PER_SEC ;
    fprintf ( fic , "%d %f \n" , dim , temps ) ; 
    for(int i = 0; i< dim; i++) {
      if (M[i]) 
        free(M[i]);
      }
      if (M) {
         free(M);
      } 
      graine++; // incrémente la graine pour generer une nouvelle matrice 
  } 
  fclose ( fic ) ;
  
}

//Analyse de la fonction max_bordure pour dim de 25 à 125 de 10 en 10
void graphiques_exo3_dim(int nbcl,Grille *G, int graine) {
  FILE * fic = fopen ("Courbes/donnees/temps/donnees_exo3_dim.txt" ,"w") ; 
  int **M;
  clock_t debut , fin ;
  double temps ;
  int aff=0;
  int nivdif = 5;
  for ( int dim=25; dim <125; dim += 10) {
    M=(int **) malloc(sizeof(int*)*dim);
    for (int i=0;i<dim;i++){
      M[i]=(int*) malloc(sizeof(int)*dim);
        if (M[i]==0) {
          printf("Pas assez d'espace mémoire disponible\n");
       }
    }   
    Gene_instance_genere_matrice(dim, nbcl, nivdif, graine, M);
    debut = clock () ;
    max_bordure(M, G, dim, nbcl, aff);
    fin = clock () ;
    temps = (( double ) ( fin - debut ) ) / CLOCKS_PER_SEC ;
    fprintf ( fic , "%d %f \n" , dim , temps ) ; 
    for(int i = 0; i< dim; i++) {
      if (M[i]) 
        free(M[i]);
      }
      if (M) {
         free(M);
      } 
      graine++; // incrémente la graine pour generer une nouvelle matrice 
  } 
  fclose ( fic ) ;
  
}

//Analyse de la fonction max_bordure_zone pour dim de 25 à 125 de 10 en 10
void graphiques_exo4_dim(int nbcl,Grille *G, int graine) {
  FILE * fic = fopen ("Courbes/donnees/temps/donnees_exo4_dim.txt" ,"w") ; 
  int **M;
  clock_t debut , fin ;
  double temps ;
  int aff=0;
  int nivdif = 5;
  for ( int dim=25; dim <125; dim += 10) {
    M=(int **) malloc(sizeof(int*)*dim);
    for (int i=0;i<dim;i++){
      M[i]=(int*) malloc(sizeof(int)*dim);
        if (M[i]==0) {
          printf("Pas assez d'espace mémoire disponible\n");
       }
    }   
    Gene_instance_genere_matrice(dim, nbcl, nivdif, graine, M);
    debut = clock () ;
    max_bordure_zone(M, G, dim, nbcl, aff);
    fin = clock () ;
    temps = (( double ) ( fin - debut ) ) / CLOCKS_PER_SEC ;
    fprintf ( fic , "%d %f \n" , dim , temps ) ; 
    for(int i = 0; i< dim; i++) {
      if (M[i]) 
        free(M[i]);
      }
      if (M) {
         free(M);
      } 
      graine++; // incrémente la graine pour generer une nouvelle matrice 
  } 
  fclose ( fic ) ;
  
}


////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


//COUPS!!

//nbcl varie
//Analyse de la fonction sequence_aleatoire_rec pour nbcl de 25 à 125 de 10 en 10
void graphiques_exo1_nbcl_coups(int dim,Grille *G, int graine) {
  FILE * fic = fopen ("Courbes/donnees/coups/donnees_exo1_nbcl.txt" ,"w") ; 
  int **M;
  int aff=0;
  int nivdif = 5;
  for ( int nbcl=25; nbcl < 125; nbcl += 10) {
    M=(int **) malloc(sizeof(int*)*dim);
    for (int i=0;i<dim;i++){
      M[i]=(int*) malloc(sizeof(int)*dim);
        if (M[i]==0) { 
          printf("Pas assez d'espace mémoire disponible\n");
       }
    }   
    Gene_instance_genere_matrice(dim, nbcl, nivdif, graine, M);
    int nb_coups = sequence_aleatoire_rec(M, G, dim, nbcl, aff);
    fprintf ( fic , "%d %d \n" , nbcl , nb_coups ) ; 
    for(int i = 0; i< dim; i++) {
      if (M[i]) 
        free(M[i]);
      }
      if (M) {
         free(M);
      } 
  } 
  fclose ( fic ) ;
  
}  

//Analyse de la fonction sequance_aleatoire_rapide pour nbcl de 25 à 125 de 10 en 10
void graphiques_exo2_nbcl_coups(int dim,Grille *G, int graine) {
  FILE * fic = fopen ("Courbes/donnees/coups/donnees_exo2_nbcl.txt" ,"w") ; 
  int **M;
  int aff=0;
  int nivdif = 5;
  for (int nbcl=25; nbcl < 125; nbcl += 10) {
    M=(int **) malloc(sizeof(int*)*dim);
    for (int i=0;i<dim;i++){
      M[i]=(int*) malloc(sizeof(int)*dim);
        if (M[i]==0) {
          printf("Pas assez d'espace mémoire disponible\n");
       }
    }   
    Gene_instance_genere_matrice(dim, nbcl, nivdif, graine, M);
     int nb_coups = sequance_aleatoire_rapide(M, G, dim, nbcl, aff);
    fprintf ( fic , "%d %d \n" , nbcl , nb_coups ) ; 
    for(int i = 0; i< dim; i++) {
      if (M[i]) 
        free(M[i]);
      }
      if (M) {
         free(M);
      } 
  } 
  fclose ( fic ) ;
  
} 

//Analyse de la fonction max_bordure pour nbcl de 25 à 125 de 10 en 10
void graphiques_exo3_nbcl_coups(int dim,Grille *G, int graine) {
  FILE * fic = fopen ("Courbes/donnees/coups/donnees_exo3_nbcl.txt" ,"w") ; 
  int **M;
  int aff=0;
  int nivdif = 5;
  for (int nbcl=25; nbcl < 125; nbcl += 10) {
    M=(int **) malloc(sizeof(int*)*dim);
    for (int i=0;i<dim;i++){
      M[i]=(int*) malloc(sizeof(int)*dim);
        if (M[i]==0) {
          printf("Pas assez d'espace mémoire disponible\n");
       }
    }   
    Gene_instance_genere_matrice(dim, nbcl, nivdif, graine, M);
     int nb_coups = max_bordure(M, G, dim, nbcl, aff);
    fprintf ( fic , "%d %d \n" , nbcl , nb_coups ) ; 
    for(int i = 0; i< dim; i++) {
      if (M[i]) 
        free(M[i]);
      }
      if (M) {
         free(M);
      } 
  } 
  fclose ( fic ) ;
  
} 

//Analyse de la fonction max_bordure_zone pour nbcl de 25 à 125 de 10 en 10
void graphiques_exo4_nbcl_coups(int dim,Grille *G, int graine) {
  FILE * fic = fopen ("Courbes/donnees/coups/donnees_exo4_nbcl.txt" ,"w") ; 
  int **M;
  int aff=0;
  int nivdif = 5;
  for (int nbcl=25; nbcl < 125; nbcl += 10) {
    M=(int **) malloc(sizeof(int*)*dim);
    for (int i=0;i<dim;i++){
      M[i]=(int*) malloc(sizeof(int)*dim);
        if (M[i]==0) {
          printf("Pas assez d'espace mémoire disponible\n");
       }
    }   
    Gene_instance_genere_matrice(dim, nbcl, nivdif, graine, M);
     int nb_coups = max_bordure_zone(M, G, dim, nbcl, aff);
    fprintf ( fic , "%d %d \n" , nbcl , nb_coups ) ; 
    for(int i = 0; i< dim; i++) {
      if (M[i]) 
        free(M[i]);
      }
      if (M) {
         free(M);
      } 
  } 
  fclose ( fic ) ;
  
} 


//dim varie
//Analyse de la fonction sequence_aleatoire_rec pour dim de 25 à 125 de 10 en 10
void graphiques_exo1_dim_coups(int nbcl,Grille *G, int graine) {
  FILE * fic = fopen ("Courbes/donnees/coups/donnees_exo1_dim.txt" ,"w") ; 
  int **M;
  int aff=0;
  int nivdif = 5;
  for ( int dim=25; dim <125; dim += 10) {
    M=(int **) malloc(sizeof(int*)*dim);
    for (int i=0;i<dim;i++){
      M[i]=(int*) malloc(sizeof(int)*dim);
        if (M[i]==0) {
          printf("Pas assez d'espace mémoire disponible\n");
       }
    }   
    Gene_instance_genere_matrice(dim, nbcl, nivdif, graine, M);
     int nb_coups = sequence_aleatoire_rec(M, G, dim, nbcl, aff);
    fprintf ( fic , "%d %d \n" , dim , nb_coups ) ; 
    for(int i = 0; i< dim; i++) {
      if (M[i]) 
        free(M[i]);
      }
      if (M) {
         free(M);
      } 
  } 
  fclose ( fic ) ;
  
}

//Analyse de la fonction sequance_aleatoire_rapide pour dim de 25 à 125 de 10 en 10
void graphiques_exo2_dim_coups(int nbcl,Grille *G, int graine) {
  FILE * fic = fopen ("Courbes/donnees/coups/donnees_exo2_dim.txt" ,"w") ; 
  int **M;
  int aff=0;
  int nivdif = 5;
  for ( int dim=25; dim <125; dim += 10) {
    M=(int **) malloc(sizeof(int*)*dim);
    for (int i=0;i<dim;i++){
      M[i]=(int*) malloc(sizeof(int)*dim);
        if (M[i]==0) {
          printf("Pas assez d'espace mémoire disponible\n");
       }
    }   
    Gene_instance_genere_matrice(dim, nbcl, nivdif, graine, M);
     int nb_coups = sequance_aleatoire_rapide(M, G, dim, nbcl, aff);
    fprintf ( fic , "%d %d \n" , dim , nb_coups ) ; 
    for(int i = 0; i< dim; i++) {
      if (M[i]) 
        free(M[i]);
      }
      if (M) {
         free(M);
      } 
  } 
  fclose ( fic ) ;
  
}

//Analyse de la fonction max_bordure pour dim de 25 à 125 de 10 en 10
void graphiques_exo3_dim_coups(int nbcl,Grille *G, int graine) {
  FILE * fic = fopen ("Courbes/donnees/coups/donnees_exo3_dim.txt" ,"w") ; 
  int **M;
  double temps ;
  int aff=0;
  int nivdif = 5;
  for ( int dim=25; dim <125; dim += 10) {
    M=(int **) malloc(sizeof(int*)*dim);
    for (int i=0;i<dim;i++){
      M[i]=(int*) malloc(sizeof(int)*dim);
        if (M[i]==0) {
          printf("Pas assez d'espace mémoire disponible\n");
       }
    }   
    Gene_instance_genere_matrice(dim, nbcl, nivdif, graine, M);
    int nb_coups = max_bordure(M, G, dim, nbcl, aff);
    fprintf ( fic , "%d %d \n" , dim , nb_coups ) ; 
    for(int i = 0; i< dim; i++) {
      if (M[i]) 
        free(M[i]);
      }
      if (M) {
         free(M);
      } 
  } 
  fclose ( fic ) ;
  
}

//Analyse de la fonction max_bordure_zone pour dim de 25 à 125 de 10 en 10
void graphiques_exo4_dim_coups(int nbcl,Grille *G, int graine) {
  FILE * fic = fopen ("Courbes/donnees/coups/donnees_exo4_dim.txt" ,"w") ; 
  int **M;
  double temps ;
  int aff=0;
  int nivdif = 5;
  for ( int dim=25; dim <125; dim += 10) {
    M=(int **) malloc(sizeof(int*)*dim);
    for (int i=0;i<dim;i++){
      M[i]=(int*) malloc(sizeof(int)*dim);
        if (M[i]==0) {
          printf("Pas assez d'espace mémoire disponible\n");
       }
    }   
    Gene_instance_genere_matrice(dim, nbcl, nivdif, graine, M);
     int nb_coups = max_bordure_zone(M, G, dim, nbcl, aff);
    fprintf ( fic , "%d %d \n" , dim , nb_coups ) ; 
    for(int i = 0; i< dim; i++) {
      if (M[i]) 
        free(M[i]);
      }
      if (M) {
         free(M);
      } 
  } 
  fclose ( fic ) ;
  
}

