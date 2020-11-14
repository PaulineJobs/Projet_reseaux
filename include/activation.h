#ifndef ACTIVATION_H
#define ACTIVATION_H
  /*
  Ce module contient une liste de fonctions d'activation piochée sur
  Wikipédia. Elle peut facilement être étendue en définissant de
  nouvelles constantes
 */

typedef enum  {
				       fonction_d_activation_identity = 0,
				       fonction_d_activation_nombre ,
} id_fonction_d_activation ;





struct fonction_d_activation_s * 
choix_fonction_d_activation ( id_fonction_d_activation id ) ;

int sauve_fonction_d_activation ( FILE * f , struct fonction_d_activation_s * fun ) ;

int lit_fonction_d_activation ( FILE * f , struct fonction_d_activation_s * * fun ) ;

id_fonction_d_activation demande_fonction_d_activation () ;


#endif
