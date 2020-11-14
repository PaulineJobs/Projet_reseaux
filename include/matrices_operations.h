#ifndef MATRICES_OPERATIONS_H
#define MATRICES_OPERATIONS_H


/*
  Opérations de base sur les matrices
 */

/*
  pré-condition: Les deux matrices existent. Si la matrice m1 a n lignes 
  et m colonnes, alors la matrice m2 a m lignes et n colonnes.
  effet: m2[i][j] = m1[j][i]
*/
int transpose_matrice(struct matrice_s * m1, struct matrice_s * m2) ;


/*
  pré-condition: les matrices m1, m2, et m3 existent, et ont les mêmes
  dimensions.
  effet: m3 = m1 + mu * m2
*/
int addition_matrice_scalaire (struct matrice_s * m1, struct matrice_s * m2, struct matrice_s * m3 , float mu) ;

/*
  pré-condition: les matrices m1, m2, et m3 existent, et ont les
  dimensions respectivent n x m, m * k, et n * k. 
  effet: m3 = m1 * m2
*/

int multiplication_matrice(struct matrice_s * m1, struct matrice_s * m2, struct matrice_s * m3) ;



/*
  pré-condition: les matrices erreurs_couche_suivante,
  activations_couche_precedente, et coefficients existent, et ont les
  dimensions respectivent 1 x n, 1 x m, et m * n.  
  effet: change change coefficient c_ij de coefficients en
      c_ij + lambda * activations_couche_precedente_i * erreurs_couche_suivante_j
*/
void matrice_mise_a_jour_coefficients (
				       struct matrice_s * erreurs_couche_suivante ,
				       struct matrice_s * activations_couche_precedente ,
				       struct matrice_s * coefficients ,
				       float lambda ) ;

/*
  Les fonctions suivantes ne sont pas nécessaires, mais peuvent être
  utilisées pour mieux implémenter les opérations sur les matrices
  dans les autres modules.
 */


/*
  pré-condition: les matrices m1 et m2 existent, et ont les mêmes
  dimensions.
  effet: m2[i][j] = f ( m1[i][j] ) 
*/
void
matrice_apply_one_arg ( struct matrice_s * m1 , float ( * f ) ( float ) , struct matrice_s * m2 ) ;

/*
  pré-condition: les matrices m1, m2, et m3 existent, et ont les mêmes
  dimensions.
  effet: m3[i][j] = f ( m1[i][j] ,m2[i][j] ) 
*/
void
matrice_apply_two_args ( struct matrice_s * m1 , struct matrice_s * m2 , float ( * f ) ( float , float ) , struct matrice_s * m3 ) ;

/*
  pré-condition: les matrices m1, m2, m3, et m4 existent, et ont les
  mêmes dimensions.
  effet: m4[i][j] = f ( m1[i][j] , m2[i][j] , m3[i][j] ) 
*/
void
matrice_apply_three_args ( struct matrice_s * m1 , struct matrice_s * m2 ,  struct matrice_s * m3 , float ( * f ) ( float , float , float ) , struct matrice_s * m4 ) ;

int multiplication_matrice_retro_propagation (struct matrice_s * m1, struct matrice_s * m2, struct matrice_s * m3) ;


#endif


