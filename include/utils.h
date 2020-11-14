#ifndef _UTILS_H
#define _UTILS_H

#ifndef NDEBUG
#define log(...)				\
  do {							\
    fprintf ( stderr ,  __VA_ARGS__ ) ;	\
    fflush ( stderr ) ;					\
  } while ( 0 )
#else
#define log(...) ((void) 0)
#endif


void lire_donnee ( FILE * f , char * format , void * res ) ;
int lire_entier ( FILE * f ) ;
// de min inclus à max exclus. max ignoré si max <= min
int lire_entier_intervalle ( FILE * f , int min, int max ) ;
float lire_float ( FILE * f ) ;
char * lire_string ( FILE * f) ;
int lire_mot_clef ( FILE * f , const char * mot ) ;

#endif
