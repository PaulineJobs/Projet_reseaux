#ifndef MATRICES_ACCESSEURS_H
#define MATRICES_ACCESSEURS_H

/*
  Accesseurs sur les matrices
 */
int nb_lignes ( matrice_t m ) ;

int nb_cols ( matrice_t m ) ;

int matrice_set (matrice_t m, int num_ligne , int num_colonne, float value);

int matrice_get (matrice_t m, int num_ligne, int num_colonne , float * value );

// adresse stockant l'adresse des coefficients
float *** matrice_raw(matrice_t m ) ;


#endif
