#ifndef COUCHES_MATRICE_H
#define COUCHES_MATRICE_H

// couche interne initialisée avec une fonction d'initialisation.  Le
// nombre de neurones en entrée est égale au nombre de neurones sur
// la couche précédente.
struct couche_s *
couche_matrice (
		   int n ,
		   struct couche_s * suivante  ) ;

#endif
