#include <stdio.h>
#include <malloc.h>
#include "matrices.h"
#include "matrices_accesseurs.h"
#include "couches_struct.h"
#include "utils.h"

/*
  Sur la couche d'entrée, la propagation consiste à recopier les entrées
  sur la couche de sortie de la couche d'entrée
 */
static void propagation ( struct matrice_s * entree , struct couche_s * c )
{
  copie_matrice ( entree , c->activation.s ) ;
}
/*
  Il n'y a rien à faire pour la rétro-propagation.
 */
static void retro_propagation ( struct matrice_s * sortie , float lambda , struct couche_s * c )
{
}

/*
  Il faut libérer la mémoire que vous avez allouée lors de la création de la couche.
 */
static void free_data ( struct couche_s * c )
{
  free ( c ) ;
}

/*
  C'est cadeau.
 */
static int sauve (  FILE * f, struct couche_s * c )
{
  fprintf ( f , "entree\n" ) ;
  return 0 ;
}

/*
  Fonction de création d'une couche entrée.  Il n'y a pas d'activation
  ni d'erreur précédentes, et les suivantes sont, comme d'habitude,
  celles de la couche suivante.
 */
struct couche_s *
couche_entree ( struct couche_s * suivante )
{
  return NULL;
}
