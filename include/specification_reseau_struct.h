#ifndef SPECIFICATION_RESEAU_STRUCT_H
#define SPECIFICATION_RESEAU_STRUCT_H
struct specification_couche_s {
  type_couche t ;
  /* nombre d'elements pour les couches d'entree et de
		  sortie,
  */
  union {
    int activation_id ;
    int taille_entrees ;
    int taille_sorties ;
    int taille_couche_precedente ;
  } parametre ;
} ;

struct specification_reseau_s {
  int nb_couches ;
  struct specification_couche_s * couche ;
} ;


#endif
