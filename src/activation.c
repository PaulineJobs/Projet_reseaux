#include <math.h>
#include <assert.h>
#include <stdio.h>
#include "activation_struct.h"
#include "activation.h"
#include "utils.h"

static float fonction_d_activation_ArcTangente ( float x )
{
  return atanf ( x ) ;
}
static float derivee_fonction_d_activation_ArcTangente ( float x , float fx )
{
  return 1 / ( 1 + x*x) ;
}

fonction_d_activation
choix_fonction_d_activation ( id_fonction_d_activation id )
{
}
   
						

int sauve_fonction_d_activation ( FILE * f , fonction_d_activation fun ) 
{
}

int lit_fonction_d_activation ( FILE * f , fonction_d_activation * fun )
{
}

