#include <assert.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>
#include "utils.h"
#include "matrices.h"
#include "matrices_accesseurs.h"
#include "matrices_operations.h"
#include "activation.h"
#include "couches_struct.h"
#include "reseau.h"

struct reseau_s {
  int nb_couches ;
  struct couche_s ** couche ;
} ;

void detruit_reseau ( struct reseau_s * r )
{
}


matrice_t reseau_get_entree ( struct reseau_s * r )
{
}
  

void propagation (
		  matrice_t entree ,
		  struct reseau_s * r )
{
}


void retro_propagation (
			matrice_t sortie_attendue ,
			float lambda ,
			struct reseau_s * r )
{
}


int ecrit_reseau_fichier (
			   FILE * f ,
			   struct reseau_s * r )
{
  return 1 ;
}


#include "couches_entree.h"
#include "couches_sortie.h"
#include "couches_activation.h"
#include "couches_matrice.h"

int lit_reseau_fichier ( FILE * f ,  struct reseau_s ** r )
{
}
