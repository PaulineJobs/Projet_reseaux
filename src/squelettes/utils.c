#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "utils.h"
/*
  Voir les TPs, = libentrée, sauf qu'on lit dans un fichier f
 */
void
lire_donnee ( FILE * f , char * format , void * res )
{
}

int lire_entier ( FILE * f )
{
  return 0 ;
}
int lire_entier_intervalle ( FILE * f , int min, int max )
{
  return 0 ;
}
float lire_float ( FILE * f )
{
  return 0 ;
}
char * lire_string ( FILE * f)
{
  return NULL ;
}
/*
  Cadeau, fonction compliquée sur un fichier... On tente de lire un
  mot, si ça échoue, on revient au point de départ et on revoie 1,
  si ça réussit, on reste à la fin du mot et on renvoie 0.
 */
int lire_mot_clef ( FILE * f , const char * mot )
{
  int c ;
  long int
    position_debut,
    position_fin ;
  while ( isspace ( c = getc ( f) ) )
    ;
  ungetc ( c , f ) ;
  position_debut = ftell ( f ) ;
  fscanf ( f , mot ) ;
  position_fin = ftell ( f ) ;
  if ( position_fin != position_debut + strlen ( mot ) )
    {
      fseek ( f , position_debut , SEEK_SET ) ;
      return 0 ;
    }
  else return 1 ;
}
