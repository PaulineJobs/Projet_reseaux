#include <stddef.h>
#include "matrices_struct.h"
#include "matrices_accesseurs.h"
/*
  accesseurs sur les matrices
*/

//Retourne le nombre de lignes de la matrice
int nb_lignes ( struct matrice_s * m )
{
  int ligne;
  ligne = m->nb_lignes;
  return ligne;
}

//Retourne le nombre de colonnes de la matrice
int nb_cols ( struct matrice_s * m )
{
  int colonne;
  colonne = m->nb_cols;
  return colonne;
}

//Entre une valeur (value) à une certaine position (num_ligne et num_colonne)
int matrice_set (struct matrice_s * m, int num_ligne , int num_colonne, float value)
{
  m->matrice[num_ligne][num_colonne] = value;
  return 0;
}

//Accesseur sur la valeur d'une certaine position
int matrice_get(struct matrice_s * m, int num_ligne, int num_colonne , float * value )
{
  (*value)=m->matrice[num_ligne][num_colonne];
  return 0;
}


/*
Return l'adresse de *m
*/
float *** matrice_raw(struct matrice_s * m )
{
  return &(m->matrice);
}
