#include <stdio.h>
#include <malloc.h>
#include "matrices.h"
#include "matrices_accesseurs.h"
#include "matrices_operations.h"
#include "couches_struct.h"
#include "utils.h"


/*
  On propage une couche matrice en multipliant l'entrée par la matrice
  des coefficients pour trouver la sortie.
 */
static void propagation ( struct matrice_s * entree  __attribute__((unused)), struct couche_s * c )
{
}

/*
  Pour la rétro-propagation de l'erreur, on fait une multiplication
  de l'erreur suivante par la transposée de la matrice des coefficients 
  pour trouver l'erreur précédente.
 */
static 
void retro_propagation_accesseurs (
					  struct matrice_s * sortie ,
					  float lambda ,
					  struct couche_s * c )
{
}
/*
  Lors de la rétro-propagation, il faut calculer l'erreur sur la
  couche précédente et mettre à jour les coefficients de la matrice.
 */

static void retro_propagation ( struct matrice_s * sortie , float lambda , struct couche_s * c )
{
}

/*
  Cette doit libérer la mémoire allouée lors de la création de la
  couche: les activations et erreurs précédentes, et la matrice des
  coefficients.
 */
static void free_data ( struct couche_s * c )
{
}
/*
  Pour sauver une couche matrice, il faut écrire dans le fichier:
  matrice N
  où N est le nombre de neurones sur la couche précédente, suivi
  de la sauvegarde de la matrice des coefficients dans un fichier.
 */
static int sauve (  FILE * f, struct couche_s * c )
{
  return 0 ;
}

/*
  Comme les autres couches, la couche matrice créé les matrices erreur
  et activation de la couche précédente, et récupère celles de la
  couche suivante. Pour les data, il faut en plus créer une matrice aléatoire.
  ayant les bonnes dimensions.
 */

struct couche_s *
couche_matrice ( int n , struct couche_s * suivante )
{
  
  return NULL ;
}
