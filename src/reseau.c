#include <malloc.h>
#include "utils.h"
#include "matrices.h"
#include "matrices_accesseurs.h"
#include "activation.h"
#include "couches_struct.h"
#include "reseau_struct.h"
#include "reseau.h"

/*
  Libère la mémoire allouée lors de la création d'un réseau
 */
void detruit_reseau ( struct reseau_s * r )
{
}

/*
  Renvoie activation.s de la couche d'entrée
 */
struct matrice_s * reseau_get_entree ( struct reseau_s * r )
{
  return NULL ;
}
/*
  Renvoie activation.p de la couche de sortie
 */
struct matrice_s * reseau_get_sortie ( struct reseau_s * r )
{
  return NULL ;
}
  

/*
  Appelle la fonction propagation de chaque couche en partant de
  la couche 0.
 */
void propagation (
		  struct matrice_s * entree ,
		  struct reseau_s * r )
{
}

/*
  Appelle la fonction retro-propagation de chaque couche en partant de
  la dernière couche.
 */

void retro_propagation (
			struct matrice_s * sortie_attendue ,
			float lambda ,
			struct reseau_s * r )
{
}

/*
  Écrit le nombre de couche, et appelle la fonction sauve de chaque couche 
  en partant de la dernière couche.
 */
int ecrit_reseau_fichier (
			   FILE * f ,
			   struct reseau_s * r )
{
}

/*
  cadeau: lit un type de couche, renvoie 0 si un type est trouvé, et 1 sinon.
*/
static int
lire_type_de_couche ( FILE * f , type_couche * t )
{
  if ( lire_mot_clef ( f , "sortie" ) )
    *t = type_couche_sortie ;
  else if  ( lire_mot_clef ( f , "entree" ) )
    *t = type_couche_entree ;
  else if ( lire_mot_clef ( f , "matrice" ) )
    *t = type_couche_matrice ;
  else if  ( lire_mot_clef ( f , "activation" ) )
    *t = type_couche_activation ;
  else
    return 1 ;
  return 0 ;
}



#include "couches_entree.h"
#include "couches_sortie.h"
#include "couches_activation.h"
#include "couches_matrice.h"

/*
  Lit un réseau dans un fichier qui a été écrit par ecrit_reseau_fichier.
 */
int lit_reseau_fichier ( FILE * f ,  struct reseau_s ** r )
{
  return 0 ;
}
