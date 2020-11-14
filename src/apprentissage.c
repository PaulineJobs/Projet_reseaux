#include <stdio.h>
#include <malloc.h>
#include "utils.h"
#include "matrices.h"
#include "matrices_accesseurs.h"
#include "specification.h"
#include "reseau.h"
#include "apprentissage.h"

/*
  Cette fonction propage les entrées, et fait la rétro-propagation en
  partant de la sortie attendue. Le coefficient lambda sert à faire varier
  les coefficients.
 */
void
apprentissage_une_donnee (
	       float * entrees , int nb_entrees ,
	       struct reseau_s * reseau ,
	       float * sorties , int nb_sorties ,
	       float lambda )
{
}

/*
  Cette fonction ouvre le fichier, récupère les tailles des entrées et
  des sorties, et pour chaque ligne suivante, lit les entrées et les
  sorties et appelle la fonction apprentissage_une_donnee. Elle
  referme ensuite le fichier.
 */
int
apprentissage_une_passe ( char nom_fichier[] ,
		        struct reseau_s * reseau ,
			int passe ,
			float ( * lambda ) ( int ) )
  {

  return 0 ;
}

/*
  Cette fonction appelle la fonction apprentissage_une_passe autant de fois
  que demandé.
 */

int
apprentissage_fichier ( char nom_fichier[] ,
		        struct reseau_s * reseau ,
			int nb_passes ,
			float ( * lambda ) ( int ) )
{
  return 0 ;
}
