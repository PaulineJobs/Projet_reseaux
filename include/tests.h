#ifndef _TESTER_H
#define _TESTER_H

#include "iso6429.h"
#include <stdio.h>


#define POSITION "Fichier "__FILE__ ", ligne %d (fonction %s):\n"

#define USECOLORS

#ifdef USECOLORS

#define COULEUR_SUCCES \
  ISO6429_COULEUR(ISO6429_GRAS ISO6429_SEP ISO6429_TEXTE(ISO6429_VERT))
#define COULEUR_ECHEC \
  ISO6429_COULEUR(ISO6429_GRAS ISO6429_SEP ISO6429_TEXTE(ISO6429_ROUGE))
#define COULEUR_INFO \
  ISO6429_COULEUR(ISO6429_GRAS ISO6429_SEP ISO6429_TEXTE(ISO6429_BLEU)) 
#define COULEUR_NORMALE \
  ISO6429_COULEUR(ISO6429_REMISE_A_ZERO)

#else
#define COULEUR_SUCCES  ""
#define COULEUR_ECHEC   ""
#define COULEUR_INFO    ""
#define COULEUR_NORMALE ""
#endif


#ifdef PRODUCTION

#define VAL_INT(n)  ( ( void ) 0 )

#define TEST_RES(x) ( ( void ) 0 )

#define debug(...)  ( ( void ) 0 )

#define test(x)     ( ( void ) 0 )

#else

#define TEST_str(x) #x

#define VALEUR_INT(n)  fprintf ( stderr , COULEUR_INFO POSITION "\t" TEST_str(n) " = %d\n" \
			     COULEUR_NORMALE , __LINE__ , __func__ , n )
#define VALEUR_CHAR(n)  fprintf ( stderr , COULEUR_INFO POSITION "\t" TEST_str(n) " = %c\n" \
			     COULEUR_NORMALE , __LINE__ , __func__ , n )
#define VALEUR_STRING(n)  fprintf ( stderr , COULEUR_INFO POSITION "\t" TEST_str(n) " = %s\n" \
			     COULEUR_NORMALE , __LINE__ , __func__ , n )
#define VALEUR_FLOAT(n)  fprintf ( stderr , COULEUR_INFO POSITION "\t" TEST_str(n) " = %f\n" \
			     COULEUR_NORMALE , __LINE__ , __func__ , n )
#define VALEUR_POINTER(n)  fprintf ( stderr , COULEUR_INFO POSITION "\t" TEST_str(n) " = %p\n" \
				  COULEUR_NORMALE , __LINE__ , __func__ , (void *) n )

#define TEST_SUPERIEUR(x,y) ( x > y ) ?					\
      fprintf ( stderr , COULEUR_SUCCES POSITION "\t" TEST_str(x) " > " TEST_str(y) \
		COULEUR_NORMALE , __LINE__ , __func__ ) :		\
      fprintf ( stderr , COULEUR_ECHEC POSITION "\t" TEST_str(x)  " <= " TEST_str(x) \
		COULEUR_NORMALE , __LINE__ , __func__ )

#define TEST_SUPERIEUR_EGAL(x,y) ( x >= y ) ?					\
      fprintf ( stderr , COULEUR_SUCCES POSITION "\t" TEST_str(x) " >= " TEST_str(y) \
		COULEUR_NORMALE , __LINE__ , __func__ ) :		\
      fprintf ( stderr , COULEUR_ECHEC POSITION "\t" TEST_str(x)  " < " TEST_str(x) \
		COULEUR_NORMALE , __LINE__ , __func__ )

#define TEST_EGAL(x,y) ( x == y ) ?					\
  fprintf ( stderr , COULEUR_SUCCES POSITION "\t" TEST_str(x)  " == " TEST_str(y) " \n" \
		COULEUR_NORMALE , __LINE__ , __func__ ) :		\
      fprintf ( stderr , COULEUR_ECHEC POSITION "\t" TEST_str(x) " != " TEST_str(y) " \n" \
		COULEUR_NORMALE , __LINE__ , __func__ )

#define TEST_DIFFERENT(x,y) ( x != y ) ?					\
  fprintf ( stderr , COULEUR_SUCCES POSITION "\t" TEST_str(x)  " != " TEST_str(y) " \n" \
		COULEUR_NORMALE , __LINE__ , __func__ ) :		\
      fprintf ( stderr , COULEUR_ECHEC POSITION "\t" TEST_str(x) " == " TEST_str(y) " \n" \
		COULEUR_NORMALE , __LINE__ , __func__ )


#define ASSERT(x)   do { \
    if ( ! ( x ) ) {							\
      fprintf ( stderr , COULEUR_ECHEC POSITION "\t" TEST_str(x)  " --> faux \n" \
		COULEUR_NORMALE , __LINE__ , __func__ ) ;		\
      exit ( EXIT_FAILURE ) ;						\
    } } while ( 0 )

#define debug(...) fprintf ( stderr , COULEUR_INFO __VA_ARGS__ )
#define test(x) ( x ) ?                                     \
  fprintf ( stderr , COULEUR_SUCCES POSITION "\t" TEST_str(x) " \n" \
                COULEUR_NORMALE , __LINE__ , __func__ ) :               \
      fprintf ( stderr , COULEUR_ECHEC POSITION "\t" TEST_str(x)  " \n" \
                COULEUR_NORMALE , __LINE__ , __func__ )


#endif

#endif
