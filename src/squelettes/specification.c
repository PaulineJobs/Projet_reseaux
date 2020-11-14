#include <stdio.h>
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
#include "specification_reseau_struct.h"

/*
  Cadeau !!!  Mais vous pouvez améliorer le code, rien n'est testé
  (malloc qui réussissent, etc)
 */
void detruit_specification ( struct specification_reseau_s * spec )
{
	free ( spec->couche ) ;
	free ( spec ) ;
}


void  print_specification ( struct specification_reseau_s * spec )
{
  int i ;
  printf ( "il y a %d couches\n" , spec->nb_couches ) ;
  for ( i = 0 ; i < spec->nb_couches ; i++ )
    {
      printf ( "couche %d: " , i ) ;
      switch ( spec->couche[i].t )
	{
	case type_couche_entree:
	  printf ( "entree de %d neurones\n" , spec->couche[i].parametre.taille_entrees ) ;
	  break ;
	case type_couche_sortie:
	  printf ( "sortie de %d neurones\n" , spec->couche[i].parametre.taille_sorties ) ;
	  break ;
	case type_couche_matrice:
	  printf ( "matrice avec entrée de %d neurones\n" , spec->couche[i].parametre.taille_couche_precedente ) ;
	  break ;
	case type_couche_activation:
	  printf ( "fonction d'activation %d\n" , spec->couche[i].parametre.activation_id ) ;
	  break ;
	default:
	  printf ( "type inconnu\n" ) ;
	}
      fflush ( stdout ) ;
    }
}


type_couche
demande_type_couche_interne ()
{
  printf ( "Quel est le type de la couche suivante ?\n" ) ;
  printf ( "\t1- matrice\n\t2- fonction d'activation\n" ) ;
  printf ( "Choisissez 1 ou 2: " ) ;
  return  lire_entier_intervalle ( stdin , 1 , 3 ) + 1 ;
}
    
struct specification_reseau_s *
demande_specification_utilisateur ( )
{
  struct specification_reseau_s * res ;
  int
    i ,
    nb_couches_internes ,
    taille_couche_precedente ;
  type_couche t ;
  printf ("Combien de couches internes ?" ) ;
  nb_couches_internes = lire_entier_intervalle ( stdin , 0 , 0 ) ;
  res = malloc ( sizeof ( struct specification_reseau_s ) ) ;
  // on ajoute 2 couches pour l'entree et la sortie
  res->nb_couches =  nb_couches_internes + 2 ;
  res->couche = malloc ( res->nb_couches * sizeof ( struct specification_couche_s ) ) ;
  res->couche[0].t = type_couche_entree ;
  printf ( "Combien de neurones dans la couche d'entree ?\n" ) ;
  res->couche[0].parametre.taille_entrees = lire_entier_intervalle ( stdin , 0 , 0 ) ;
  taille_couche_precedente = res->couche[0].parametre.taille_entrees ;
  for ( i = 1 ; i < res->nb_couches -1 ; i++ )
    {
      t = demande_type_couche_interne() ;
      switch ( t )
	{
	case type_couche_matrice:
	  res->couche[i].t = type_couche_matrice ;
	  res->couche[i].parametre.taille_couche_precedente = taille_couche_precedente ;
	  printf ( "Combien de neurones sur la couche suivante ?\n" ) ;
	  taille_couche_precedente = lire_entier_intervalle ( stdin , 0 , 0 ) ;
	  break ;

	case type_couche_activation:
	  res->couche[i].t = type_couche_activation ;
	  res->couche[i].parametre.activation_id = demande_fonction_d_activation () ;
	  break ;
	  
	default:
	  return NULL  ; // impossible apres les tests dans
			 // demande_type_couche_interne
	}
    }
  res->couche[res->nb_couches - 1].t = type_couche_sortie ;
  printf ( "Combien de neurones dans la couche de sortie ?\n" ) ;
  res->couche[res->nb_couches - 1].parametre.taille_sorties =
    lire_entier_intervalle ( stdin , 0 , 0 ) ;
  print_specification ( res ) ;
  return res ;
}

struct reseau_s {
  int nb_couches ;
  struct couche_s ** couche ;
} ;

struct reseau_s *
creation_reseau ( struct specification_reseau_s * spec )
{
  struct reseau_s
    * res ;
  int i ;

  res = malloc ( sizeof ( struct reseau_s ) ) ;
  res->nb_couches = spec->nb_couches ;
  res->couche = malloc ( res->nb_couches * sizeof ( struct couche_s * ) ) ;

  i= res->nb_couches -1 ;
  res->couche[i] = couche_sortie (
				  spec->couche[i ].parametre.taille_sorties ) ;
  
  for ( i = res->nb_couches - 2 ; i > 0 ; i-- )
    {
      switch ( spec->couche[i].t )
	{
	case type_couche_matrice:
	  res->couche[i] = couche_matrice (
				spec->couche[i].parametre.taille_couche_precedente ,
				 res->couche[i+1] ) ;
	  break ;
	case type_couche_activation:
	  res->couche[i] = couche_activation (
				   choix_fonction_d_activation (
								spec->couche[i].
								parametre.activation_id ) ,
				   res->couche[i+1] ) ;
	  break ;
	default:
	  return NULL ;
	}
    }
  res->couche[0] = couche_entree ( res->couche[1] ) ;
  return res ;
  
}
