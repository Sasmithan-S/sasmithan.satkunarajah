#include <stdio.h>
#include <stdlib.h>

#include "exercice4.h"
#include "exercice2.h"

#include "Liste_case.h"

//calcule la taille d'une zone connexe de couleur cl
int taille_zone (int ** M, int dim, int i, int j, int cl, int **App_compte){
     //on verifie qu'on est bien dans la grille, dans la mm couleur, et pas déja compter
     if (i<0 || i >= dim || j<0 || j>= dim || M[i][j] !=cl || App_compte[i][j]  == 1){
        return 0;
     }

     int cpt=0;
     ListeCase L; //Contient les cases a visiter
     init_liste(&L);

     ajoute_en_tete(&L,i,j);
     App_compte[i][j] =1; //case i j visiter ? : oui

     while (!test_liste_vide(&L)){ //tant qu'il y ades cases a explorer 
        
        enleve_en_tete(&L,&i,&j);
        cpt++;

        int n= i-1; //nord
        int s= i+1; //sud
        int e= j+1; //est
        int o= j-1; //ouest

        //NORD 
        if (n>=0) {  //bien dans la grille?
            if (M[n][j] == cl && App_compte[n][j] ==0){ //bonne couleur et non visiter
                App_compte[n][j] = 1;
                ajoute_en_tete (&L,n,j);
      
                
            }
        }

        //SUD 
        if (s<dim) {  //bien dans la grille?
            if (M[s][j] == cl && App_compte[s][j] ==0){ //bonne couleur et non visiter
                App_compte[s][j] = 1;
                ajoute_en_tete (&L,s,j);
            }
        }

        //EST 
        if (e<dim) {  //bien dans la grille?
            if (M[i][e] == cl && App_compte[i][e] ==0){ //bonne couleur et non visiter
                App_compte[i][e] = 1;
                ajoute_en_tete (&L,i,e);
            }
        }

        //OUEST
        if (o>=0) {  //bien dans la grille?
            if (M[i][o] == cl && App_compte[i][o] ==0){ //bonne couleur et non visiter
                App_compte[i][o] = 1;
                ajoute_en_tete (&L,i,o);
            }
        }
    }
    detruit_liste(&L);
    return cpt;    
}

int max_bordure_zone (int **M, Grille *G, int dim, int nbcl, int aff){
    S_Zsg Z;
    int taille = 0;
    int cpt = 0;        
    int cl;  

    
    init_Zsg(dim, nbcl, &Z);
    cl = M[0][0]; 
    taille = taille + agrandit_Zsg(M, &Z, cl, 0, 0);
    //compte sera la matrice qui va permettre de marquer les cases
    int **compte = (int**)malloc(sizeof(int*)*dim);
    if(compte == NULL){
        printf ("Allocation Erreur");
        return -1;
    }
    for (int i=0; i < dim; i++){
        compte[i]=(int *)malloc( dim*sizeof(int));
        if(compte[i] == NULL){
            printf ("Allocation Erreur");
            return -1;
        }
        for(int j=0;j<dim;j++){
            compte[i][j]=0;
        }
    }
    //on continue tant que la grille n'est pas remplie
    while (taille < dim * dim) {
        cpt++; 
        int coul = -1;
        int taille_max= -1;
        //met a 0 toutes les cases de compte
        for (int i = 0; i < dim; i++) {
            for (int j = 0; j < dim; j++) {
                compte[i][j] =0;

            }
        }
        //pour chaque couleur dans la bordure différent de cl 
        for(int c=0;c<nbcl;c++){ 
            if(c!=cl && Z.B[c]!=NULL){
                int tot =0;
                ListeCase tmp2 =Z.B[c];
                //on parcours cette bordure si elle est pas deja compté
                while (tmp2 != NULL) {
                    if (compte[tmp2 ->i][tmp2->j] == 0) {
                        tot = tot + taille_zone(M,dim,tmp2->i,tmp2->j,c,compte);
                    }
                    tmp2=tmp2->suiv;
                }
                //recupere la couleur qui apporterai le plus de case
                if (tot>taille_max){
                    taille_max = tot;
                    coul = c;
                }
            }    
        }
        
        if (coul == -1){
            break;
        }
        //met a jour les couleurs de M avec la couleur qui apporte le plus de case
        ListeCase tmp = Z.Lzsg;
        while (!test_liste_vide(&tmp)) {
            M[tmp->i][tmp->j] = coul; 
              if (aff==1){
                Grille_attribue_couleur_case(G, tmp->i, tmp->j, coul);

              }
            tmp = tmp->suiv;
        }
    
        //on s'occupe de la bordure pour agrandir la zone
       ListeCase tmp2=Z.B[coul];
          init_liste(&(Z.B[coul]));
          tmp=tmp2;

          while(!(test_liste_vide(&tmp))){
            taille += agrandit_Zsg(M, &Z, coul, tmp->i, tmp->j);
            tmp=tmp->suiv;
        }

        cl =coul;
        detruit_liste(&tmp2);
        
        if (aff == 1) { 
            Grille_redessine_Grille(G);
        }   
    }
    

    for(int i = 0; i < dim; i++) {
        free(compte[i]);
    }

    free(compte);

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

