#ifndef APPRENTISSAGE_H
#define APPRENTISSAGE_H


void
apprentissage_une_donnee (
	       float * entrees , int nb_entrees ,
	       struct reseau_s * reseau ,
	       float * sorties , int nb_sorties ,
	       float lambda ) ;


/*
  La fonction lambda prend en entrée le numéro de la passe courante et
  renvoie un float entre 0 et 1: plus il est petit, moins le réseau
  avance vite. S'il est trop grand, l'apprentissage va osciller autour
  d'un minimum sans s'en approcher
 */
int
apprentissage_fichier (
		       char nom_fichier[] ,
		       struct reseau_s * reseau ,
		       int nb_passes ,
		       float ( * lambda ) ( int ) ) ;

#endif
