#ifndef MATRICES_OPERATIONS_H
#define MATRICES_OPERATIONS_H


/*
  Opérations de base sur les matrices
 */
/*
  pré-condition: les matrices m1 et m2 existent, et ont les mêmes
  dimensions.
  effet: copie les coefficients de m1 dans m2
*/
int copie_matrice(matrice_t m1, matrice_t m2);



/*
  pré-condition: Les deux matrices existent. Si la matrice m1 a n lignes 
  et m colonnes, alors la matrice m2 a m lignes et n colonnes.
  effet: m2[i][j] = m1[j][i]
*/
int transpose_matrice(matrice_t m1, matrice_t m2) ;


/*
  pré-condition: les matrices m1, m2, et m3 existent, et ont les mêmes
  dimensions.
  effet: m3 = m1 + mu * m2
*/
int addition_matrice_scalaire (matrice_t m1, matrice_t m2, matrice_t m3 , float mu) ;

/*
  pré-condition: les matrices m1, m2, et m3 existent, et ont les
  dimensions respectivent n x m, m * k, et n * k. 
  effet: m3 = m1 * m2
*/

int multiplication_matrice(matrice_t m1, matrice_t m2, matrice_t m3) ;



/*
  pré-condition: les matrices m1 et m2 existent, et ont les mêmes
  dimensions.
  effet: m2[i][j] = f ( m1[i][j] ) 
*/
void
matrice_apply_one_arg ( matrice_t m1 , float ( * f ) ( float ) , matrice_t m2 ) ;

/*
  pré-condition: les matrices m1, m2, et m3 existent, et ont les mêmes
  dimensions.
  effet: m3[i][j] = f ( m1[i][j] ,m2[i][j] ) 
*/
void
matrice_apply_two_args ( matrice_t m1 , matrice_t m2 , float ( * f ) ( float , float ) , matrice_t m3 ) ;

/*
  pré-condition: les matrices m1, m2, m3, et m4 existent, et ont les
  mêmes dimensions.
  effet: m4[i][j] = f ( m1[i][j] , m2[i][j] , m3[i][j] ) 
*/
void
matrice_apply_three_args ( matrice_t m1 , matrice_t m2 ,  matrice_t m3 , float ( * f ) ( float , float , float ) , matrice_t m4 ) ;

int multiplication_matrice_retro_propagation (matrice_t m1, matrice_t m2, matrice_t m3) ;

void matrice_mise_a_jour_coefficients (
				       matrice_t erreurs_couche_suivante ,
				       matrice_t activations_couche_precedente ,
				       matrice_t coefficients ,
				       float lambda ) ;

#endif


