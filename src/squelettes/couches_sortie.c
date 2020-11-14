#include <stdio.h>
#include <malloc.h>
#include "matrices.h"
#include "matrices_accesseurs.h"
#include "couches_struct.h"
#include "utils.h"



/*
  Il n'y a pas de propagation après la couche de sortie.
 */
static void propagation ( struct matrice_s * entree __attribute__((unused)), struct couche_s * c )
{
}

/*
  Pour la rétro- propagation, on initialise erreur.p par la différence
  entre la sortie attendue et l'activation sur la couche de sortie.
 */
static void
retro_propagation (
			      struct matrice_s * sortie_attendue ,
			      float lambda ,
			      struct couche_s * c )
{
}



/*
  Cette fonction doit libérer la mémoire allouée lors de la création
  de la couche.
 */
static void free_data ( struct couche_s * c )
{
}

/*
  Pour sauver une couche de sortie, il suffit d'écrire:
  sortie N
  où N est le nombre de neurones sur la couche de sortie.
 */
static int sauve ( FILE * f , struct couche_s * c )
{
  return 0 ;
}


/*
   Pour créer une couche de sortie, il faut créer les matrices p pour
   l'activation et l'erreur.
 */
struct couche_s *
couche_sortie ( int n  )
{
  return NULL ;
}
