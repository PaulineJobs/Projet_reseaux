#include <stdio.h>
#include "specification.h"


int main ( int argc , char * argv[] )
{
  FILE * f ;
  struct couche_s * reseau ;
  struct specification_reseau_s * specification_reseau ;
  if ( argc != 2 ) return 1 ;

  specification_reseau = demande_specification_utilisateur() ;
  reseau = creation_reseau ( specification_reseau )
  if ( apprentissage ( argv[1] , reseau , 10 , & lambda ) )
    return 1 ;
  if ( ( f = fopen ( "reseau.mat" , "w" ) ) == NULL )
    {
      fprintf ( stderr , "Impossible d'écrire le réseau dans le fichier reseau.mat.\n" );
      return 1 ;
    }
  if ( ecrit_couche_fichier ( f , reseau ) )
    {
      fprintf ( stderr , "Erreur lors de l'écriture du reseau dans le fichier reseau.mat.\n" );
      fclose ( f ) ;
      return 1 ;
    }
  fprintf ( stderr , "Réseau sauvegardé dans le fichier reseau.mat.\n" );
  fclose ( f ) ;
  return 0 ;
}
