#ifndef RESEAU_H
#define RESEAU_H


void detruit_reseau ( struct reseau_s * r ) ;

struct matrice_s * reseau_get_sortie ( struct reseau_s * r ) ;

struct matrice_s * reseau_get_entree ( struct reseau_s * r ) ;

struct matrice_s * reseau_get_sortie ( struct reseau_s * r ) ;

void propagation (
		  struct matrice_s * entree ,
		  struct reseau_s * r ) ;

void retro_propagation (
			struct matrice_s * sortie_attendue ,
			float lambda ,
			struct reseau_s * r ) ;

int ecrit_reseau_fichier (
			   FILE * f ,
			   struct reseau_s * r ) ;

int lit_reseau_fichier (
			FILE * f ,
			struct reseau_s ** r ) ;

#endif
