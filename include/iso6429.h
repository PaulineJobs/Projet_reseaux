#ifndef _ISO_6429
#define _ISO_6429

#define ISO6429_REMISE_A_ZERO "0"
#define ISO6429_GRAS "1"
#define ISO6429_SOULIGNE "4"
#define ISO6429_CLIGNOTE "5"
#define ISO6429_FIN_CLIGNOTE "25"
#define ISO6429_INVERSE "7"
#define ISO6429_FONTE(n) "1" ISO6429_str(n)
#define ISO6429_NOIR "0"
#define ISO6429_ROUGE "1"
#define ISO6429_VERT "2"
#define ISO6429_JAUNE "3"
#define ISO6429_BLEU "4"
#define ISO6429_MAGENTA "5"
#define ISO6429_CYAN "6"
#define ISO6429_BLANC "7"
#define ISO6429_TEXTE(couleur) "3" couleur
#define ISO6429_FOND(couleur) "4" couleur
#define ISO6429_SEP ";"
#define ISO6429_READ "R"
#define ISO6429_CSI "\33["
#define ISO6429_CMD_COULEUR "m"
#define ISO6429_COULEUR(spec) ISO6429_CSI spec ISO6429_CMD_COULEUR

/*
  Utilisation:
  ISO6429_FONTE(5)  -> "15" // fontes entre 10 et 19 
  ISO6429_COULEUR(ISO6429_GRAS ISO6429_SEP ISO6429_TEXTE(ISO6429_BLEU)) --> "\33[1;34m" // texte entre 30 et 37
  ISO6429_COULEUR(ISO6429_FOND(ISO6429_ROUGE)) --> "\33[1;41m" // fond entre 40 et 47
*/

#define ISO6429_CURSEUR_HAUT(n)           ISO6429_CSI #n "A"
#define ISO6429_CURSEUR_BAS(n)            ISO6429_CSI #n "B"
#define ISO6429_CURSEUR_DROIT(n)          ISO6429_CSI #n "C"
#define ISO6429_CURSEUR_GAUCHE(n)         ISO6429_CSI #n "D"
#define ISO6429_LIGNE_SUIVANTE(n)         ISO6429_CSI #n "E"
#define ISO6429_LIGNE_PRECEDENTE(n)       ISO6429_CSI #n "F"
#define ISO6429_CURSEUR_POS_X(n)          ISO6429_CSI #n "G"
#define ISO6429_CURSEUR_POS_Y(n)          ISO6429_CSI #n "H"
#define ISO6429_CLEAR_SCREEN_ABOVE        ISO6429_CSI "1J"
#define ISO6429_CLEAR_SCREEN_BELOW        ISO6429_CSI "0J"
#define ISO6429_CLEAR_SCREEN              ISO6429_CSI "2J"
#define ISO6429_SUPPRIME_LIGNE_AVANT      ISO6429_CSI "1K"
#define ISO6429_SUPPRIME_LIGNE_APRES      ISO6429_CSI "0K"
#define ISO6429_SUPPRIME_LIGNE_TOUT       ISO6429_CSI "2K"
#define ISO6429_PAGE_DESSUS(n)            ISO6429_CSI #n "S"
#define ISO6429_PAGE_DESSOUS(n)           ISO6429_CSI #n "T"
#define ISO6429_POSITIONNE(x,y)           ISO6429_CSI #y ISO6429_SEP #x "f"
#define ISO6429_SAUVE_POSITION_CURSEUR    ISO6429_CSI "s"
#define ISO6429_RESTAURE_POSITION_CURSEUR ISO6429_CSI "u"
#define ISO6429_CACHE_CURSEUR             ISO6429_CSI "?25l"
#define ISO6429_MONTRE_CURSEUR            ISO6429_CSI "?25h"

#ifdef ISO_6429_WITH_POINT
#include <stdio.h>

struct iso6429_point { 
  int x ;
  int y ;
} ;

/*
  Pour l'utiliser sans problèmes, il vaut mieux que les entrées soient "hot"
 */
int iso6429_position_curseur (  struct iso6429_point  * point)
{
  int res ;
  printf ( ISO6429_CSI "6n" ) ;
  if ( res = scanf ( ISO6429_CSI "%d" ISO6429_SEP "%d" ISO6429_READ, &(point->x) , &(point->y) ) )
    return res ;
  return 0 ;
}
#endif
#endif
