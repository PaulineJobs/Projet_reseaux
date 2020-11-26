#include <stddef.h>
#include <assert.h>
#include <math.h>
#include "matrices_struct.h"
#include <stdio.h>



/*
  Transpose m1 et met le résultat dans m2
 */
int transpose_matrice(struct matrice_s * m1, struct matrice_s * m2 )
{
   int i,j;
   //m2 = creation_matrice(m1->nb_cols, m2->nb_lignes);
   for (i=0; i< m2->nb_lignes; i++){
       for (j=0; j< m2->nb_cols; j++){
           m2->matrice[i][j] = m1->matrice[j][i];
       }
   }
   return 0;

}



int addition_matrice_scalaire(struct matrice_s * m1,struct matrice_s * m2,struct matrice_s * m3 ,float mu ){
	
	int  i,j;
	
	for (i=0; i< m1->nb_lignes ;i++){                                  //on crée une boucle pour parcourir toutes les lignes de chaque matrice
		for (j=0;j< m1->nb_cols;j++){                                  // on crée une boucle pour parcourir chaque element de la ligne dont il est question 
			m3->matrice[i][j]=m1->matrice[i][j]+mu*(m2->matrice[i][j]);     // on additionne les coefficients m1[i][j]+mu*(m2[i][j]) et on les met dans une troisième matrice à l'emplacement m3[i][j]
		}
	}                                                                 // gràce aux boucles on répète l'opération pour chaque case des matrices
	
	return 0;	
	
}

/*
  Les valeurs d'activation des neurones d'une couche sont stockées
  dans un vecteur ligne (une matrice \(1\times n\). On passe d'une
  couche à la suivante en multipliant par la matrice des synapses
  entre ces deux couches. Cette multiplication est donc utilisée pour
  la propagation.

  Note: on suppose que toutes les matrices sont déjà créées, et donc
  que |m3| a le même nombre de lignes que |m1| et le même nombre de
  colonnes que |m2|.
 */
 
int multiplication_matrice(struct matrice_s * m1, struct matrice_s * m2, struct matrice_s * m3 ){
	
	int  i,j,k;
	
	for(i=0;i< m1->nb_lignes ;i++){                        //on parcours toutes les lignes de la matrice A
		
            for(j=0;j< m2->nb_cols ;j++){                  // on parcours toutes lignes de la matrice B
				
                for(k=0;k<m2->nb_lignes;k++){             // on parcours toutes les lignes de la matrice B
					
					(m3->matrice[i][j])=(m3->matrice[i][j])+((m1->matrice[i][k])*(m2->matrice[k][j]));  //on fait le produit scalaire de la ligne i de la matrice 1 avec la colonne j de la matrice 2  
				}																						//et on place la résultats dans la matrice m3[i][j]
					
			}
																// grâce aux boucles on répète l'opération pour remplir toutes les cases de m3
	}
	return 0;
}




/*
  apply the function f on all the elements of m1 and puts the result in m2
 */

void matrice_apply_one_arg (struct matrice_s * m1 ,float(*f)(float),struct matrice_s * m2 ) {
   int i,j;

   for (i=0; i < m1->nb_lignes; i++) {
     for (j=0; j < m1->nb_cols; j++) {
       m2->matrice[i][j] = (*f) (m1->matrice[i][j]);
     }
   }

}



void matrice_apply_two_args ( struct matrice_s * m1 , struct matrice_s * m2 , float ( * f ) ( float , float ) , struct matrice_s * m3 ){
   int i,j;

   for (i=0; i < m1->nb_lignes; i++) {
     for (j=0; j < m1->nb_cols; j++) {
       m3->matrice[i][j] = (*f) (m1->matrice[i][j],m2->matrice[i][j]);
     }
   }

}
	
	


void matrice_apply_three_args ( struct matrice_s * m1 , struct matrice_s * m2 , struct matrice_s * m3 , float ( * f ) ( float , float , float ) ,struct matrice_s * m4 ){
   int i,j;

   for (i=0; i < m1->nb_lignes; i++) {
     for (j=0; j < m1->nb_cols; j++) {
       m4->matrice[i][j] = (*f) (m1->matrice[i][j],m2->matrice[i][j],m3->matrice[i][j]);
     }
   }

}



/*
  Pour la rétro-propagation, il faut multiplier le vecteur d'erreur
  (connu) de la couche \(n+1\) par la transposée de la matrice des
  synapses entre la couche \(n\) et la couche \(n+1\) pour trouver
  l'erreur sur la couche \(n\). C'est ce que fait cette fonction, ce
  qui permet de na pas avoir à créer la transposée de la matrice.
  Cette fonction est donc utilisée lors de la rétro-propagation de
  l'erreur.

  le premier argument est maintenant la ligne sur la couche \(n+1\),
  et le troisième est la ligne sur la couche \(n\).
 */
 
int multiplication_matrice_retro_propagation(struct matrice_s * m1, struct matrice_s * m2,struct matrice_s * m3 ) {
    if (m1->nb_cols != m2->nb_cols){
        printf("erreur : nbr cols de matrice 1 différent de nbr cols matrice 2");
        return 1;
    } else if (m1->nb_lignes != m3->nb_lignes){
        printf("erreur : nbr lignes de matrice 1 différent de nbr lignes matrice 3");
        return 1;
    } else if (m2->nb_lignes != m3->nb_cols){
        printf("erreur : nbr lignes de matrice 2 différent de nbr cols matrice 3");
        return 1;
    } else {
        for (int i=0;i<m3->nb_lignes;i++){
            for (int j=0;i<m3->nb_cols;j++){
                int norme =0;
                m3->matrice[i][j]=0;
                for (int k=0;i<m1->nb_cols;k++){
                    m3->matrice[i][j]-=m1->matrice[i][j]*m2->matrice[i][j];
                    norme = norme + (m2->matrice[i][j])*(m2->matrice[i][j]);
                }
            m3->matrice[i][j]=(m3->matrice[i][j])/(sqrt(norme));
            }
        }
    }
    return 0 ;
}

void matrice_mise_a_jour_coefficients( struct matrice_s * erreurs_couche_suivante ,struct matrice_s * activations_couche_precedente , struct matrice_s * coefficients ,float lambda ){

	
}
