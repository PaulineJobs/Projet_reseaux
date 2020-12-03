#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <assert.h>
#include <math.h>
#include "matrices_struct.h"




/*
  Transpose m1 et met le résultat dans m2
 */
int transpose_matrice(struct matrice_s * m1, struct matrice_s * m2 )
{
   int c1,l1;
   for (l1=0; l1< m2->nb_lignes; l1++){                //on parcourt les lignes de la matrice1
       for (c1=0; c1< m2->nb_cols; c1++){               // on parcourt ses colonnes
           m2->matrice[l1][c1] = m1->matrice[c1][l1];       // on inverse les coefficients des lignes et des colonnes
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
	
	int  l1,l2,c2;
	
	for(l1=0;l1< m1->nb_lignes ;l1++){                        //on parcours toutes les lignes de la matrice 1
		
            for(c2=0;c2< m2->nb_cols ;c2++){                  // on parcours toutes les colonnes de la matrice 2
				
                for(l2=0;l2<m2->nb_lignes;l2++){             // on parcours toutes les lignes de la matrice 2
					
                    //on fait le produit scalaire de la ligne l1 de la  matrice 1  avec la colonne c2 de la matrice 2 
                    //et on place la résultats dans la matrice m3 [l1][c2] 
					(m3->matrice[l1][c2])=(m3->matrice[l1][c2])+((m1->matrice[l1][l2])*(m2->matrice[l1][c2]));
				}																						
					
			}
																// grâce aux boucles on répète l'opération pour remplir toutes les cases de m3
	}
	return 0;
}




/*
  apply the function f on all the elements of m1 and puts the result in m2
 */

void matrice_apply_one_arg (struct matrice_s * m1 ,float(*f)(float),struct matrice_s * m2 ) {
   int l2,c2;

   for (l2=0; l2 < m1->nb_lignes; l2++) {
     for (c2=0; c2 < m1->nb_cols; c2++) {
        // chaque coef de la matrice m2 prends la valeur du coefficient de la matrice 1 à qui ont lui a appliqué une fonction 
        //m2[i][j]=f(m1[i][j]) 
       m2->matrice[l2][c2] = (*f) (m1->matrice[l2][c2]);
     }
   }

}



void matrice_apply_two_args ( struct matrice_s * m1 , struct matrice_s * m2 , float ( * f ) ( float , float ) , struct matrice_s * m3 ){
   int l3,c3;

   for (l3=0; l3 < m1->nb_lignes; l3++) {
     for (c3=0; c3 < m1->nb_cols; c3++) {
        // chaque coef de la matrice m2 prends la valeur du coefficient de la matrice 1 et 2 à qui ont leur a appliqué une fonction 
        //m3[i][j]=f(m1[i][j],m2[i][j])
       m3->matrice[l3][c3] = (*f) (m1->matrice[l3][c3],m2->matrice[l3][c3]);
     }
   }

}



	
	


void matrice_apply_three_args ( struct matrice_s * m1 , struct matrice_s * m2 , struct matrice_s * m3 , float ( * f ) ( float , float , float ) ,struct matrice_s * m4 ){
   int l4,c4;

   for (l4=0; l4 < m1->nb_lignes; l4++) {
     for (c4=0; c4 < m1->nb_cols; c4++) {
        // chaque coef de la matrice m2 prends la valeur du coefficient de la matrice 1,2,3 à qui ont leur a appliqué une fonction 
        //m3[i][j]=f(m1[i][j],m2[i][j],m3[i][j])
       m4->matrice[l4][c4] = (*f) (m1->matrice[l4][c4],m2->matrice[l4][c4],m3->matrice[l4][c4]);
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
        printf("erreur : nbr cols de matrice 1 différent de nbr cols matrice 2\n");
        return 1;
    } else if (m1->nb_lignes != m3->nb_lignes){
        printf("erreur : nbr lignes de matrice 1 différent de nbr lignes matrice 3\n");
        return 1;
    } else if (m2->nb_lignes != m3->nb_cols){
        printf("erreur : nbr lignes de matrice 2 différent de nbr cols matrice 3\n");
        return 1;
    } else {
        for (int l3=0;l3<m3->nb_lignes;l3++){
            for (int c3=0;c3<m3->nb_cols;c3++){
                int norme =0;
                m3->matrice[l3][c3]=0;
                for (int c1=0;c1<m1->nb_cols;c1++){
                    m3->matrice[l3][c3]-=m1->matrice[l3][c1]*m2->matrice[c3][c1];
                    norme = norme + (m2->matrice[c3][c1])*(m2->matrice[c3][c1]);
                }
                m3->matrice[l3][c3]=(m3->matrice[l3][c3])/(sqrt(norme));
            }
        }
    }
    return 0 ;
}



void matrice_mise_a_jour_coefficients( struct matrice_s * erreurs_couche_suivante ,struct matrice_s * activations_couche_precedente , struct matrice_s * coefficients ,float lambda ){
    for (int lc=0;lc<coefficients->nb_lignes;lc++){
        int vligne= activations_couche_precedente->matrice[0][lc];
        for (int cc=0;cc<coefficients->nb_cols;cc++){
            int erreur = erreurs_couche_suivante->matrice[0][cc];
            coefficients->matrice[lc][cc]=coefficients->matrice[lc][cc]+lambda*vligne*erreur;
        }
    }
}






