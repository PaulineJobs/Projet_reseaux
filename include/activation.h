#ifndef ACTIVATION_H
#define ACTIVATION_H
  /*
  Ce module contient une liste de fonctions d'activation piochée sur
  Wikipédia. Elle peut facilement être étendue en définissant de
  nouvelles constantes
 */

typedef enum  {
				       fonction_d_activation_identity = 0,
				       fonction_d_activation_binary_step = 1 ,
				       fonction_d_activation_logistic = 2 ,
				       fonction_d_activation_tan_h = 3 ,
				       fonction_d_activation_arctan = 4 ,
				       fonction_d_activation_signe_doux = 5 ,
				       fonction_d_activation_relu = 6 ,
				       fonction_d_activation_nombre ,
} id_fonction_d_activation ;


typedef struct fonction_d_activation_s * fonction_d_activation ;



fonction_d_activation 
choix_fonction_d_activation ( id_fonction_d_activation id ) ;

int sauve_fonction_d_activation ( FILE * f , fonction_d_activation fun ) ;

int lit_fonction_d_activation ( FILE * f , fonction_d_activation * fun ) ;



#endif
