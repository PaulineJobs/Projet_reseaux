#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include "utils.h"
#include "activation.h"
#include "matrices.h"
#include "couches_struct.h"
#include "couches_entree.h"
#include "couches_sortie.h"
#include "couches_matrice.h"
#include "couches_activation.h"
#include "specification.h"
#include "reseau_struct.h"


struct specification_couche_s {
  type_couche t ;
  /* nombre d'elements pour les couches d'entree et de
		  sortie,
  */
  union {
    int activation_id ;
    int taille_entrees ;
    int taille_sorties ;
    int taille_couche_precedente ;
  } parametre ;
} ;

struct specification_reseau_s {
  int nb_couches ;
  struct specification_couche_s * couche ;
} ;

void detruit_specification ( struct specification_reseau_s * spec )
{
}


void  print_specification ( struct specification_reseau_s * spec )
{
}


    
struct specification_reseau_s *
demande_specification_utilisateur ( )
{
	return NULL ;
}


struct reseau_s *
creation_reseau ( struct specification_reseau_s * spec )
{
	return NULL ;
}
