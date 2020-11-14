#include <stddef.h>
#include <assert.h>
#include <math.h>
#include "matrices_struct.h"

/*
  Transpose m1 et met le résultat dans m2
 */
int transpose_matrice(
		      struct matrice_s * m1,
		      struct matrice_s * m2 )
{
}

/*
  Additionne 2 matrices de même dimension et met le résultat dans m3.
 */
int addition_matrice_scalaire(
			      struct matrice_s * m1,
			      struct matrice_s * m2,
			      struct matrice_s * m3 ,
			      float mu ) 
{
  int  i , j ;
  return 0 ;
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
int multiplication_matrice(
			   struct matrice_s * m1,
			   struct matrice_s * m2,
			   struct matrice_s * m3 )
{
  return 0 ;
}




void matrice_mise_a_jour_coefficients (
				       struct matrice_s * erreurs_couche_suivante ,
				       struct matrice_s * activations_couche_precedente ,
				       struct matrice_s * coefficients ,
				       float lambda )
{
  int j , i ;
  float x_i , erreur_j ;
  for ( i = 0 ; i < coefficients->nb_lignes ; i ++ )
    {
      x_i=activations_couche_precedente->matrice[0][i] ;
	for ( j = 0 ; j < coefficients->nb_cols ; j ++ )
	  {
	   erreur_j= erreurs_couche_suivante->matrice[0][j] ;
	   coefficients->matrice[i][j]= coefficients->matrice[i][j] + lambda * x_i * erreur_j ;
	  }
    }
}

/*
  Les fonctions suivantes peuvent être écrites et utilisées.
 */

void
matrice_apply_one_arg (
		       struct matrice_s * m1 ,
			float ( * f ) ( float ) ,
			struct matrice_s * m2 )
{

}



void
matrice_apply_two_args (
			struct matrice_s * m1 ,
			 struct matrice_s * m2 ,
			 float ( * f ) ( float , float ) ,
			struct matrice_s * m3 )
{
 
}
void
matrice_apply_three_args (
			  struct matrice_s * m1 ,
			   struct matrice_s * m2 ,
			   struct matrice_s * m3 ,
			   float ( * f ) ( float , float , float ) ,
			   struct matrice_s * m4 )
{
}
