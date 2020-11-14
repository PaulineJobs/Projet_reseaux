#include <malloc.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "utils.h"
#include "matrices.h"
#include "matrices_struct.h"

/*
  Cette fonction doit libérer la mémoire allouée lors de la création d'une matrice
 */
void
detruit_matrice ( struct matrice_s * m )
{
}

/*
  Cette fonction crée une matrice 
 */
struct matrice_s * creation_matrice ( int nb_lignes , int nb_colonnes )
{
  return NULL ;
}

/*
  Si *e == NULL , il faut créer une matrice 1 x n et la mettre dans
  *e.  Maintenant que *e contient une matrice 1 x n, il faut recopier
  les coefficients du tableau t dans cette matrice.  
 */
int
matrice_ligne ( struct matrice_s * * e , float * t , int n )
{
  int i ; 
  if( *e == NULL ) 
	  {
	    *e = creation_matrice ( 1 , n ) ;
   	  }
  for ( i = 0 ; i < n ; i++ )
    (*e)->matrice[0][i] = t[i] ;
  return 0 ;
}



/*
  Cette fonction crée et initialise une matrice n x m avec des |float|
  dans [ -1 , 1 ].
*/
struct matrice_s * creation_matrice_aleatoire ( int nb_lignes , int nb_colonnes )
{
}


/*
  Cette fonction demande à l'utilisateur les dimensions et les
  coefficients d'une matrice, et renvoie la matrice correspondante.
*/
struct matrice_s * creation_matrice_utilisateur ( )
{  
}

/*
  Cette fonction lit une matrice qui a été stockée dans un fichier.
*/
int lire_matrice_fichier ( FILE * f , struct matrice_s * * m )
{
  return 0 ;
}
/*
  Cette fonction sauve une matrice dans un fichier. Elle
  doit utiliser la même format que lit_matrice_fichier
*/
int sauve_matrice_fichier ( FILE * f , struct matrice_s * m )
{
  return 0 ;
}
/*
  Cette fonction affiche une matrice.
*/
void affiche_matrice ( struct matrice_s * m )
{
}


/*
  Copie le contenu de la matrice m1 dans la matrice m2.
  Les 2 matrices existent et ont les mêmes dimensions.
*/
int copie_matrice(
		  struct matrice_s * m1,
		  struct matrice_s * m2 )
{
  return 0 ;
}
