#include <math.h>
#include <assert.h>
#include <stdio.h>
#include <malloc.h>
#include "activation_struct.h"
#include "activation.h"
#include "utils.h"


/*
  static permet de rendre les fonctions invisibles en dehors du module
  (méthodes privées en Java)
 */
static float fonction_d_activation_Identity ( float x )
{
  return x ;
}
static float derivee_fonction_d_activation_Identity ( float x , float fx )
{
  return 1 ;
}


/*
  Il faut renvoyer une structure avec l'adresse d'une fonction
  d'activation et de la dérivée correspondante. Ces fonctions sont
  définies sur le modèle de la fonction d'identité
 */
struct fonction_d_activation_s *
choix_fonction_d_activation ( id_fonction_d_activation id )
{
  return NULL ;
}
   
/*
  Il suffit d'écrire l'id de la fonction d'activation
 */
int sauve_fonction_d_activation ( FILE * f , struct fonction_d_activation_s * fun ) 
{
  return 0 ;
}

/*
  il faut lire l'id d'une fonction d'activation dans le fichier f, et mettre le
  choix d'une fonction d'activation correspond à cet id dans *fun.
 */
int lit_fonction_d_activation ( FILE * f , struct fonction_d_activation_s ** fun )
{
  return 0 ;
}
/*
  Il faut afficher les différents choix de fonction d'activation possibles, 
  lire le choix de l'utilisateur, et le renvoyer.
 */

id_fonction_d_activation
demande_fonction_d_activation ()
{
  return 0 ;
}
