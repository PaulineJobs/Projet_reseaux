#ifndef RESEAU_H
#define RESEAU_H

typedef struct reseau_s * reseau_t  ;

void detruit_reseau ( struct reseau_s * r ) ;

matrice_t reseau_get_sortie ( struct reseau_s * r ) ;

matrice_t reseau_get_entree ( struct reseau_s * r ) ;

matrice_t reseau_get_sortie ( struct reseau_s * r ) ;

void propagation (
		  matrice_t entree ,
		  struct reseau_s * r ) ;

void retro_propagation (
			matrice_t sortie_attendue ,
			float lambda ,
			struct reseau_s * r ) ;

int ecrit_reseau_fichier (
			   FILE * f ,
			   struct reseau_s * r ) ;

int lit_reseau_fichier (
			FILE * f ,
			struct reseau_s ** r ) ;

#endif
