#include <malloc.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "utils.h"
#include "matrices.h"
#include "matrices_struct.h"


void
detruit_matrice ( matrice_t m )
{
}

matrice_t creation_matrice ( int nb_lignes , int nb_colonnes )
{
	return NULL ;
}



/*
  Cette fonction initialise une matrice avec des |float| dans [ -1 , 1 ].
*/
matrice_t creation_matrice_aleatoire ( int nb_lignes , int nb_colonnes )
{
	return NULL ;
}


matrice_t creation_matrice_utilisateur ( )
{
  return NULL ;
}

int lire_matrice_fichier ( FILE * f , matrice_t * m )
{
  return 1 ;
}

void affiche_matrice ( matrice_t m )
{
}

int sauve_matrice_fichier ( FILE * f , matrice_t m )
{
  return 1 ;
}

