#ifndef MATRICES_ACCESSEURS_H
#define MATRICES_ACCESSEURS_H

/*
  Accesseurs sur les matrices
 */
int nb_lignes ( struct matrice_s * m ) ;

int nb_cols ( struct matrice_s * m ) ;

int matrice_set (struct matrice_s * m, int num_ligne , int num_colonne, float value);

int matrice_get (struct matrice_s * m, int num_ligne, int num_colonne , float * value );

// adresse stockant l'adresse des coefficients
float *** matrice_raw(struct matrice_s * m ) ;


#endif
