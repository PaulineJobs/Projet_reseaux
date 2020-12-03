#include <stddef.h>
#include "matrices_struct.h"
#include "matrices_accesseurs.h"
/*
  accesseurs sur les matrices
*/

//Return le nombre de lignes de la matrice
int nb_lignes ( struct matrice_s * m )
{
  int ligne;
  ligne = m->nb_lignes;
  return ligne;
}

//Return le nombre de colonnes de la matrice
int nb_cols ( struct matrice_s * m )
{
  int colonne;
  colonne = m->nb_cols;
  return colonne;
}

//Entre une valeur (value) sur une certaine ligne (num_ligne) d'une certaine colonne (num_colonne) de la matrice
int matrice_set (struct matrice_s * m, int num_ligne , int num_colonne, float value)
{
  m->matrice[num_ligne][num_colonne]=value;
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
