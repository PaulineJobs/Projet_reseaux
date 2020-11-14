#ifndef COUCHES_STRUCT_H
#define COUCHES_STRUCT_H

#include "type_couche.h"

union couche_data {
  struct matrice_s * m ;
  struct fonction_d_activation_s * f ;
} ;

struct inter_couche_s {
  struct matrice_s * p ; // couche precedente
  struct matrice_s * s ; // couche suivante
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
  void ( * propagation )( struct matrice_s * , struct couche_s * ) ;
  void ( * retro_propagation ) ( struct matrice_s * , float , struct couche_s * ) ;
  int ( * sauve ) ( FILE * , struct couche_s * ) ;
} ;

#endif
