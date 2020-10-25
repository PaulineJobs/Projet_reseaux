#include <stdio.h>
#include <stdlib.h>
#define DIMENSION 3
#include <math.h>

float f ( float * x , float * coefficients , int nb_vars )
{
  float res ;
  int i ;
  for ( res = 0 , i = 0 ; i < nb_vars ; i++ )
    res += x[i] * coefficients[i] ;
  return res ;
}

void hasard ( float * x , int nb_vars )
{
  int i ;
  for ( i = 0 ; i < nb_vars ; i++ )
    {
      x[i] = ( float ) drand48() ;
      if ( isnan ( x[i] ) ) i-- ;
    }
}


int
main ( int argc , char * argv[] )
{
  float
    coefficients[DIMENSION] = { 1 , 1 , 1 } ,
    variable[DIMENSION]  ;
  int nb_tests = atol ( argv[1] )  ;
  int i , j ;
  srand48 ( atol ( argv[1] ) ) ;
  printf ( "%d %d\n" , DIMENSION , 1 ) ;
   for ( i = 0 ; i < nb_tests ; i ++ )
     {
       hasard ( variable , DIMENSION ) ;
       for ( j = 0 ; j < DIMENSION ; j++ )
	 printf ( "%f," ,variable[j] ) ;
       printf ( "%f\n" , f ( variable , coefficients , DIMENSION ) ) ;
     }
   return 0 ;
}
