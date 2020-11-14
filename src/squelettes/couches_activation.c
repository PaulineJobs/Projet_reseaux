#include <stdio.h>
#include <malloc.h>
#include "matrices.h"
#include "matrices_accesseurs.h"
#include "activation_struct.h"
#include "activation.h"
#include "couches_struct.h"
#include "utils.h"


/*
  La propagation pour la couche d'activation consiste
  à mettre à jour, pour tout i;
  activation.s[i] <- f ( activation.p[i] ) 
 */
static void propagation ( struct matrice_s * entree  __attribute__((unused)), struct couche_s * c )
{
}

/*
  La rétro-propagation consiste à faire pour tout i:
  erreur.p[i] =  - f' ( activation.p[i] , activation.s[i] ) * erreur.s[i]
 */
static void retro_propagation (
				   struct matrice_s * sortie ,
				    float lambda ,
				    struct couche_s *  c )
{
}

/*
  Cette fonction doit libérer avec free toute la mémoire qui a été
  allouée pour la couche.
 */

static void free_data ( struct couche_s * c )
{
}
/*
  Cette fonction affiche :
activation i
où i est l'id de la fonction d'activation de cette couche
 */
static int sauve (  FILE * f, struct couche_s * c )
{
  return 0 ;
}
/*
  Cette fonction crée une couche d'activation à partir de la fonction.
  Les entrées et les sorties ont les mêmes tailles que les entrées de
  la couche suivante.
  
  Comme pour toutes les couches, cette fonction alloue de la mémoire
  pour les matrices en entrées, et les matrices en sortie sont les
  entrées de la couche suivante.
 */
struct couche_s *
couche_activation (
		   struct fonction_d_activation_s * fun ,
		   struct couche_s * suivante )
{
   return NULL ;  
}
