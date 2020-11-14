#include <stddef.h>
#include "matrices_struct.h"
#include "matrices_accesseurs.h"
/*
  accesseurs sur les matrices
*/
int nb_lignes ( struct matrice_s * m )
{
}
int nb_cols ( struct matrice_s * m )
{
}

int matrice_set (struct matrice_s * m, int num_ligne , int num_colonne, float value)
{
  return 0 ;
}

int matrice_get(struct matrice_s * m, int num_ligne, int num_colonne , float * value )
{
  return 0 ;
}

float *** matrice_raw(struct matrice_s * m )
{
  return NULL ;
}
