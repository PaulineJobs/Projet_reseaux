#include <stdio.h>
#include <stdlib.h>
//#include <malloc.h>
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
  Commentaire initial de M.Chevalier :
  
  Cadeau !!!  Mais vous pouvez améliorer le code, rien n'est testé
  (malloc qui réussissent, etc)
 */
 
 
 /*
 Je vais ajouter des commentaires pour une meilleure comprehension des fonctions
 */
 
 
 
 /*
 Libere en premier la memoire allouee a couche (voir struct specification_reseau s)
 Ensuite, libere la memoire allouee a spec
 */
void detruit_specification ( struct specification_reseau_s * spec )
{
	free ( spec->couche ) ;
	free ( spec ) ;
}


/*
Indique en premier le nombre de couches
A l'aide d'une boucle, on parcourt chaque couche
Pour chaque couche, reconnait quel est le type de couche dont il est question grace a l'enumeration type_couche
Ensuite, on utilise un switch pour print le nombre de neuronnes, ou la fonction d'activation suivant la couche dont il est question
Dans le cas ou l'on aurait renseigne un type de couche inexistant, renvoie une erreur
*/
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


/*
La fonction permet de savoir si la couche suivante est une matrice ou une fonction d'activation
On accede a cette information en lisant un fichier
*/
type_couche demande_type_couche_interne ()
{
  printf ( "Quel est le type de la couche suivante ?\n" ) ;
  printf ( "\t1- matrice\n\t2- fonction d'activation\n" ) ;
  printf ( "Choisissez 1 ou 2: " ) ;
  return  lire_entier_intervalle ( stdin , 1 , 3 ) + 1 ;
}

 

/*

*/
struct specification_reseau_s * demande_specification_utilisateur ( )
{
  struct specification_reseau_s * res ; //On declare un pointeur sur la structure specification_reseau_s
  int
    i , //variable compteur
    nb_couches_internes ,
    taille_couche_precedente ;
  type_couche t ; //On initialise l'enumeration
  printf ("Combien de couches internes ?" ) ;
  nb_couches_internes = lire_entier_intervalle ( stdin , 0 , 0 ) ; //On lit combien il y a de couches internes
  res = malloc ( sizeof ( struct specification_reseau_s ) ) ; //Allocation de memoire pour le pointeur sur la struct
  
  res->nb_couches =  nb_couches_internes + 2 ; //Ajout de deux couches pour l'entree et la sortie
  res->couche = malloc ( res->nb_couches * sizeof ( struct specification_couche_s ) ) ; //Allocation de memoire pour couche
  //Couche etant un pointeur sur la structure specification_couche_s, il faut allouer la memoire
  res->couche[0].t = type_couche_entree ; //type_couche_entree = 0
  printf ( "Combien de neurones dans la couche d'entree ?\n" ) ; //On cherche a savoir combien il y a de neuronnes en entree
  res->couche[0].parametre.taille_entrees = lire_entier_intervalle ( stdin , 0 , 0 ) ; //la taille_entrees (dans struct specification_couche_s)
  //prend la valeur lue par lire_entier_intervalle
  taille_couche_precedente = res->couche[0].parametre.taille_entrees ; //taille_couche_precedent prend la valeur que l'on a defini precedement
  
  for ( i = 1 ; i < res->nb_couches -1 ; i++ ) //Boucle pour obtenir le type et agir suivant chaque type
    {
      t = demande_type_couche_interne() ; //Utilisation de la fonction precedente pour obtenir le type de la couche suivante
      switch ( t )
	{
	case type_couche_matrice: //Si la couche suivante est une matrice
	  res->couche[i].t = type_couche_matrice ; //Le type_couche a cet emplacement prend la valeur 2
	  res->couche[i].parametre.taille_couche_precedente = taille_couche_precedente ; //dans l'union parametre, taille_couche_precedent
	  //prend la valeur que l'on a defini juste avant la boucle
	  printf ( "Combien de neurones sur la couche suivante ?\n" ) ;
	  taille_couche_precedente = lire_entier_intervalle ( stdin , 0 , 0 ) ; //On obtient le nombre de neuronnes dans la couche suivante
	  break ; 

	case type_couche_activation: //Si la couche suivante est une fonction d'activation
	  res->couche[i].t = type_couche_activation ; //Le type_couche a cet emplacement prend la valeur 3
	  res->couche[i].parametre.activation_id = demande_fonction_d_activation () ; //dans l'union parametre, activation_id est obtenue
	  //a l'aide de la fonction demande_fonction_d_activation du module activation
	  break ;
	  
	default: 
	  return NULL  ; // impossible apres les tests dans
			 // demande_type_couche_interne
	}
    }
  res->couche[res->nb_couches - 1].t = type_couche_sortie ; //La couche a cet emplacement prend la valeur 1
  printf ( "Combien de neurones dans la couche de sortie ?\n" ) ;
  res->couche[res->nb_couches - 1].parametre.taille_sorties = lire_entier_intervalle ( stdin , 0 , 0 ) ; //dans l'union parametre,
  //on obtient la taille_sortie en lisant dans le fichier grace a la fonction lire_entier_intervalle du module utils
  print_specification ( res ) ; //Utilisation d'une des fonctions precedentes pour print le resultat final
  return res ; //On retourne le pointeur sur la structure, maintenant rempli
}


//Structure que l'on retrouve normalement dans reseau_struct.h
struct reseau_s {
  int nb_couches ;
  struct couche_s ** couche ;
} ;



struct reseau_s * creation_reseau ( struct specification_reseau_s * spec )
{
  struct reseau_s * res ; //On declare un pointeur sur la structure reseau_s
  int i ; //Declaration d'une variable compteur

  res = malloc ( sizeof ( struct reseau_s ) ) ; //On alloue la memoire necessaire a res
  res->nb_couches = spec->nb_couches ; //nombre de couches de res est egal au nombre de couches de spec, le parametre de la fonction
  res->couche = malloc ( res->nb_couches * sizeof ( struct couche_s * ) ) ; //Allocation de memoire pour couche, dans la structure reseau_s

  i= res->nb_couches -1 ;
  res->couche[i] = couche_sortie (spec->couche[i ].parametre.taille_sorties ) ; //res->couche[i] est egal au nombre de donnees en sortie
  //(on recupere donc la taille_sortie dans l'union de specification_couche_s)
  
  for ( i = res->nb_couches - 2 ; i > 0 ; i-- ) //Boucle pour parcourir les couches
    {
      switch ( spec->couche[i].t ) //On differe les cas
	{
	case type_couche_matrice: //Dans le cas ou la couche est de type matrice
	  res->couche[i] = couche_matrice(spec->couche[i].parametre.taille_couche_precedente, res->couche[i+1] ) ;
	  //L'emplacement i de couche prend la valeur renvoyee par la fonction couche_matrice (voir couche_matrice.c)
	  break ;
	case type_couche_activation: //Dans le cas ou la couche est de type fonction d'activation
	  res->couche[i] = couche_activation(choix_fonction_d_activation (spec->couche[i].parametre.activation_id ), res->couche[i+1] ) ;
	  //L'emplacement i de couche prend la valeur renvoyee par la fonction couche_activation (voir couche_activation.c)
	  break ;
	default: //Normalement ce cas la est impossible
	  return NULL ;
	}
    }
  res->couche[0] = couche_entree ( res->couche[1] ) ; //type_couche t prend la valeur renvoye par la fonction couche_entree (voir couche_entree.c)
  return res ; //On renvoie le reseau final
  
}
