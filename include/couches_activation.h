#ifndef COUCHES_ACTIVATION_H
#define COUCHES_ACTIVATION_H

// couche interne initialisée avec une fonction d'initialisation.  Le
// nombre de neurones en entrée est égale au nombre de neurones sur
// la couche suivante.
struct couche_s *
couche_activation (
		   struct fonction_d_activation_s * fun ,
		   struct couche_s * suivante  ) ;

#endif
