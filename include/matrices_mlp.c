#include <malloc.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
#include "utils.h"
#include "matrices.h"

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
int multiplication_matrice_retro_propagation(matrice_t m1, matrice_t m2, matrice_t m3)
{
  int i , j , k ;
  if ( ( m1->nb_cols != m2->nb_cols ) ||
       (m2->nb_lignes != m3->nb_cols ) ||
       (m1->nb_lignes != m3->nb_lignes ) )
    return 1 ;
  for ( i = 0 ; i < m3->nb_lignes ; i++ )
    for ( j = 0 ; j < m3->nb_cols ; j++ )
      {
	for ( k = 0 ; k < m1->nb_cols ; k++ )
	  m3->matrice[i][j] -= m1->matrice[i][k] * m2->matrice[j][k] ;
      }
  return 0 ;
}


/*
  apply the function f on all the elements of m1 and puts the result in m2
 */

void
matrice_apply_one_arg ( matrice_t m1 , float ( * f ) ( float ) , matrice_t m2 )
{
  int i , j ;
  assert ( m1 != NULL ) ;
  assert ( m2 != NULL ) ;
  assert ( m1->matrice != NULL ) ;
  assert ( m2->matrice != NULL ) ;
  assert ( m1->nb_cols == m2->nb_cols ) ;
  assert ( m1->nb_lignes == m2->nb_lignes ) ;
  for ( i = 0 ; i < m1->nb_lignes ; i++ )
    for ( j = 0 ; j < m1->nb_cols ; j++ )
      m2->matrice[i][j] = (*f) ( m1->matrice[i][j] ) ;
}



void
matrice_apply_two_args ( matrice_t m1 , matrice_t m2 , float ( * f ) ( float , float ) , matrice_t m3 )
{
  int i , j ;
  assert ( m1 != NULL ) ;
  assert ( m2 != NULL ) ;
  assert ( m3 != NULL ) ;
  assert ( m1->matrice != NULL ) ;
  assert ( m2->matrice != NULL ) ;
  assert ( m3->matrice != NULL ) ;
  assert ( m1->nb_cols == m2->nb_cols ) ;
  assert ( m1->nb_cols == m3->nb_cols ) ;
  assert ( m1->nb_lignes == m2->nb_lignes ) ;
  assert ( m1->nb_lignes == m3->nb_lignes ) ;
  for ( i = 0 ; i < m1->nb_lignes ; i++ )
    for ( j = 0 ; j < m1->nb_cols ; j++ )
      m3->matrice[i][j] = (*f) ( m1->matrice[i][j] , m2->matrice[i][j] ) ;
}
void
matrice_apply_three_args ( matrice_t m1 , matrice_t m2 ,  matrice_t m3 , float ( * f ) ( float , float , float ) , matrice_t m4 )
{
  int i , j ;
  assert ( m1 != NULL ) ;
  assert ( m2 != NULL ) ;
  assert ( m3 != NULL ) ;
  assert ( m4 != NULL ) ;
  assert ( m1->matrice != NULL ) ;
  assert ( m2->matrice != NULL ) ;
  assert ( m3->matrice != NULL ) ;
  assert ( m4->matrice != NULL ) ;
  assert ( m1->nb_cols == m2->nb_cols ) ;
  assert ( m1->nb_cols == m3->nb_cols ) ;
  assert ( m1->nb_cols == m4->nb_cols ) ;
  assert ( m1->nb_lignes == m2->nb_lignes ) ;
  assert ( m1->nb_lignes == m3->nb_lignes ) ;
  assert ( m1->nb_lignes == m4->nb_lignes ) ;
  for ( i = 0 ; i < m1->nb_lignes ; i++ )
    for ( j = 0 ; j < m1->nb_cols ; j++ )
      m4->matrice[i][j] = (*f) ( m1->matrice[i][j] , m2->matrice[i][j] , m3->matrice[i][j] ) ;
}

void matrice_mise_a_jour_coefficients (
				       matrice_t erreurs_couche_suivante ,
				       matrice_t activations_couche_precedente ,
				       matrice_t coefficients ,
				       float lambda )
{
  int j , i ;
  float x_i , erreur_j ;
  assert ( nb_cols ( activations_couche_precedente ) == nb_lignes ( coefficients ) ) ;
  assert ( nb_cols ( erreurs_couche_suivante ) == nb_cols ( coefficients ) ) ;
  for ( i = 0 ; i < nb_cols ( activations_couche_precedente ) ; i ++ )
    {
      x_i=activations_couche_precedente->matrice[0][i] ;
	for ( j = 0 ; j < nb_cols ( erreurs_couche_suivante ) ; j ++ )
	  {
	   erreur_j= erreurs_couche_suivante->matrice[0][j] ;
	   coefficients->matrice[i][j]= coefficients->matrice[i][j] - lambda * x_i * erreur_j ;
	  }
    }
}
