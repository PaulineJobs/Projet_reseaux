#pragma once

#include "matrice_structure.h"


matrice_t creation_matrice ( int nb_lignes , int nb_colonnes ) ;

matrice_t creation_matrice_aleatoire ( int nb_lignes , int nb_colonnes ) ;

matrice_t creation_matrice_utilisateur (  ) ;

void affiche_matrice ( matrice_t m ) ;

int lire_matrice_fichier ( const char * fichier , matrice_t * m ) ;

int sauve_matrice_fichier ( const char * fichier , matrice_t m ) ;

int ajoute_valeur(matrice_t *m1, int num_ligne , int num_colonne, float value);

int recupere_valeur(matrice_t m1, int num_ligne, int num_colonne , float * value );

int copie_matrice(matrice_t m1, matrice_t *m2);

int addition_matrice(matrice_t m1, matrice_t m2, matrice_t *m3) ;

int multiplication_matrice(matrice_t m1, matrice_t m2, matrice_t *m3) ;
