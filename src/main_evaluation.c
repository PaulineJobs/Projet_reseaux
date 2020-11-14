#include <stdio.h>
#include "utils.h"
#include "specification.h"
#include "reseau.h"
#include "evaluation.h"

int main ( int argc , char * argv[] )
{
  FILE
    * f_reseau  ;
  struct reseau_s
    * reseau ;

  if ( ( f_reseau = fopen ( "reseau.mat", "r" ) ) == NULL ) return 1 ;
  log ( "fichier contenant le réseau ouvert.\n" ) ;
  if ( lit_reseau_fichier ( f_reseau , & reseau  ) ) return 2 ;
  log ( "réseau lu.\n" ) ;
  fclose ( f_reseau ) ;
  log ( "fichier contenant le réseau fermé.\n" ) ;
  if ( argc != 2 ) return 3 ;
  
  if ( evaluation_reseau ( argv[1] , reseau  ) ) return  4;
  return 0 ;
}
