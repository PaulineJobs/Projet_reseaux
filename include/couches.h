#ifndef COUCHES_H
#define COUCHES_H

#include "type_couche.h"

typedef struct couche_s * couche_t ;


void
detruit_couches ( struct couche_s *  ) ;

type_couche
couche_get_type ( struct couche_s * ) ;

matrice_t
couche_get_sortie ( struct couche_s * ) ;

matrice_t
trouve_sortie ( struct couche_s * c ) ;

  
// couche finale à n neurones
// n est la dimension de la sortie
struct couche_s * couche_sortie ( int n  ) ;


int ecrit_couche_fichier ( FILE * f , struct couche_s * c  ) ;

// suivante est NULL
int lit_couche_fichier ( FILE * f , struct couche_s ** c  , struct couche_s * suivante ) ;

// Cette fonction propage l'entrée le long du réseau.  Le résultat est
// stocké dans la dernière couche.
void
propagation_reseau (
	     matrice_t entree ,
	      struct couche_s * c ) ;

// Après la propagation, cette fonction repart de la couche de sortie
// pour propager l'erreur entre la sortie obtenue et la sortie
// attendue, et modifie le réseau pour minimiser cette erreur.
void
retro_propagation_reseau (
		   matrice_t sortie_attendue ,
		   float lambda ,
		   struct couche_s * c ) ;

#endif
