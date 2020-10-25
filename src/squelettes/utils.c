#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#include "utils.h"


/*
	C'est cadeau parce que ça fait plaisir :)
	(et qu'on ne verra pas la fonction ftell de toutes façons)
*/
void
log_show_position ( FILE * f )
{
  assert ( f != NULL ) ;
  log ( "position %ld" , ftell ( f ) ) ;
}


void
lire_donnee ( FILE * f , char * format , void * res )
{
}

int lire_entier ( FILE * f )
{
}

/*
	Recommence lire_entier tant que l'entier n'est pas >= au
	min et < au max. Si le max est inférieur ou égal au min,
	il n'est pas testé. Donc:
		lire_entier_positif ( & n ) ;
	fait la même chose que:
		lire_entier_intervalle ( stdin , 0 , 0 ) ;
*/
int lire_entier_intervalle ( FILE * f , int min, int max )
{
}
float lire_float ( FILE * f )
{
}
char * lire_string ( FILE * f)
{
}
