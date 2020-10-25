#include <stddef.h>
#include <assert.h>
#include <math.h>
#include "matrices_struct.h"



int copie_matrice(
		  struct matrice_s * m1,
		  struct matrice_s * m2 )
{
}



int transpose_matrice(
		      struct matrice_s * m1,
		      struct matrice_s * m2 )
{
}

int addition_matrice_scalaire(
			      struct matrice_s * m1,
			      struct matrice_s * m2,
			      struct matrice_s * m3 ,
			      float mu ) 
{
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
}



/*
  apply the function f on all the elements of m1 and puts the result in m2
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
  int i , j ;
  for ( i = 0 ; i < m1->nb_lignes ; i++ )
    for ( j = 0 ; j < m1->nb_cols ; j++ )
      m4->matrice[i][j] = (*f) ( m1->matrice[i][j] , m2->matrice[i][j] , m3->matrice[i][j] ) ;
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
int multiplication_matrice_retro_propagation(
					     struct matrice_s * m1,
					     struct matrice_s * m2,
					     struct matrice_s * m3 )
{
  return 1 ;
}

void matrice_mise_a_jour_coefficients (
				       struct matrice_s * erreurs_couche_suivante ,
				       struct matrice_s * activations_couche_precedente ,
				       struct matrice_s * coefficients ,
				       float lambda )
{
}
