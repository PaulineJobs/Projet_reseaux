#pragma once
#include "matrices.h"

/* 
   NEURONES
*/

typedef float ( * fonction_d_activation_t ) ( float ) ;



/*
  On va regarder des réseaux de neurones qui sont organisés en
  couches.  Chaque couche est un tableau de neurones. On a choisi ici
  une version non optimisée qui est plus simple, où chaque neurone est
  représenté par son adresse de type neurone_t, mais il serait plus
  efficace de représenter chaque neurone par une structure de type
  struct neurone_s. Un tableau de neurones aurait ainsi le type 
  struct neurone_s * 
  = neurone_t
*/

typedef struct couche_s * couche_t ;

struct couche_s {
  couche_t suivante ;
  matrice_t poids ;
  int nb_neurones ;
  float * entree ;
  fonction_d_activation_t * f ;
  float * sortie ;
} ;

couche_t creation_couche ( int n , fonction_d_activation_t f , couche_t couche_suivante ) ;

couche_t creation_couche_aleatoire ( int n , couche_t couche_suivante ) ;

couche_t creation_reseau_aleatoire ( int nb_couches , int * tailles_couches ) ;

int nb_couches ( couche_t couche ) ;

int adresse_des_entrees ( couche_t couche , int * taille_entrees , float ** adresse_entrees ) ;

int adresse_des_sorties ( couche_t couche , int * taille_sorties , float ** adresse_sorties ) ;

int calcule_entrees_couche_suivante ( couche_t couche ) ;

int mise_a_jour_sortie_couche ( couche_t couche ) ;

int propagation ( couche_t couche ) ;


float derive ( float x , fonction_d_activation_t f ) ; 


int retro_propagation ( couche_t couche , float * attendu , float vitesse ) ;
