#ifndef MATRICES_H
#define MATRICES_H



/*
	Cette fonction alloue de la place pour stocker une structure
	matrice, un tableau de lignes, ainsi que chaque ligne.
 */
struct matrice_s * creation_matrice ( int nb_lignes , int nb_colonnes ) ;

/*
  	Cette fonction libère toute la mémoire qui a été allouée dans la
	fonction suivante pour stocker une matrice.	
 */
void detruit_matrice ( struct matrice_s * m ) ;

/*
 	Création d'une matrice ligne à partir d'un tableau:
 	- si *m est NULL, il faut allouer de la place pour la
   	  structure et l'adresse de la première ligne.
 	- puis, ou si *m n'est pas NULL, il faut juste mettre t dans
      l'adresse pour la premiere ligne.

	Il ne faut pas appeler detruit_matrice sur le resultat de cette
	fonction.
*/
int matrice_ligne ( struct matrice_s * * m , float * t , int n ) ;


/*
	Cette fonction appelle la fonction creation_matrice, puis 
	met un nombre aléatoire entre -1 et 1 (un float) dans chaque
	coefficient.
 */
struct matrice_s * creation_matrice_aleatoire ( int nb_lignes , int nb_colonnes ) ;


/*
	Cette fonction commence par demander à un utiliser le nombre de
	lignes et de colonnes de la matrice à créer. Elle appelle la
	fonction creation_matrice, puis demande à l'utilisateur chaque
	coefficient.
 */
struct matrice_s * creation_matrice_utilisateur (  ) ;

/* 
	les deux fonctions suivantes lisent et écrivent des matrices dans
	des fichiers déjà ouverts. Le format choisi est d'écrire le nombre
	de lignes et de colonnes de la matrice, puis tous les
	coefficients.
*/
int lire_matrice_fichier ( FILE * f , struct matrice_s * * m ) ;

int sauve_matrice_fichier ( FILE * f , struct matrice_s * m ) ;

/*
	Cette fonction affiche une matrice.
 */
void affiche_matrice ( struct matrice_s * m ) ;

/*
  pré-condition: les matrices m1 et m2 existent, et ont les mêmes
  dimensions.
  effet: copie les coefficients de m1 dans m2
*/
int copie_matrice(struct matrice_s * m1, struct matrice_s * m2);


#endif
