#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include "utils.h"
#include "matrices.h"
#include "matrices_accesseurs.h"
#include "activation.h"
#include "reseau.h"
#include "apprentissage.h"

void
apprentissage_une_donnee (
	       float * entrees , int nb_entrees ,
	       struct reseau_s * reseau ,
	       float * sorties , int nb_sorties ,
	       float lambda )
{
}

int
compte_nb_lignes ( FILE * f )
{
  return -1 ;
}
int
apprentissage_fichier ( char nom_fichier[] ,
		        struct reseau_s * reseau ,
			int nb_passes ,
			float ( * lambda ) ( int ) )
{
  return 1; 
}
