#ifndef COUCHES_STRUCT_H
#define COUCHES_STRUCT_H

#include "type_couche.h"

union couche_data {
  matrice_t m ;
  fonction_d_activation f ;
} ;

struct inter_couche_s {
  matrice_t p ; // couche precedente
  matrice_t s ; // couche suivante
} ;
/*
  chaque couche est responsable de l'allocation de la partie p
  de l'inter-couche
 */
struct couche_s {
  type_couche t ;
  struct couche_s * suivante ;
  struct inter_couche_s activation ;
  struct inter_couche_s erreur ;
  union couche_data data ;
  void ( * detruit )( struct couche_s * ) ;
  void ( * propagation )( matrice_t , struct couche_s * ) ;
  void ( * retro_propagation ) ( matrice_t , float , struct couche_s * ) ;
  int ( * sauve ) ( FILE * , struct couche_s * ) ;
} ;

#endif
