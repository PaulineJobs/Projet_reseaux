#include <stdio.h>
#include "matrices.h"
#include "activation.h"
#include "specification.h"
#include "reseau.h"
#include "apprentissage.h"
#include "specification.h"

static float lambda ( int n )
{
  return ( ( float ) 1 ) / ( 1 << ( n / 3 + 4 )  ) ;
}
int main ( int argc , char * argv[] )
{
  FILE * f ;
  struct reseau_s * reseau ;
  struct specification_reseau_s * specification_reseau ;
  if ( argc != 2 ) return 1 ;
  specification_reseau = demande_specification_utilisateur() ;
  reseau = creation_reseau ( specification_reseau ) ;
  detruit_specification ( specification_reseau ) ;
  
  if ( apprentissage_fichier ( argv[1] , reseau , 32 , & lambda ) )
    return 1 ;
  if ( ( f = fopen ( "reseau.mat" , "w" ) ) == NULL )
    {
      fprintf ( stderr , "Impossible d'écrire le réseau dans le fichier reseau.mat.\n" );
      return 1 ;
    }
  if ( ecrit_reseau_fichier ( f , reseau ) )
    {
      fprintf ( stderr , "Erreur lors de l'écriture du reseau dans le fichier reseau.mat.\n" );
      fclose ( f ) ;
      return 1 ;
    }
  fprintf ( stderr , "Réseau sauvegardé dans le fichier reseau.mat.\n" ) ;
  fclose ( f ) ;
  detruit_reseau ( reseau ) ;
  return 0 ;
}
