#include <math.h>
#include <assert.h>
#include <stdio.h>
//#include <malloc.h>
#include "activation_struct.h"
#include "activation.h"
#include "utils.h"


/*
  static permet de rendre les fonctions invisibles en dehors du module
  (méthodes privées en Java)
 */
static float fonction_d_activation_Identity ( float x )
{
  return x ;
}
static float derivee_fonction_d_activation_Identity ( float x , float fx )
{
  return 1 ;
}
static float fonction_d_activation_Racine_carree (float y){
  return (sqrt(y));
}
static float derivee_fonction_d_activation_Racine_carree (float y,float fy){
  return (1/(2*sqrt(y)));
}

/*
  Il faut renvoyer une structure avec l'adresse d'une fonction
  d'activation et de la dérivée correspondante. Ces fonctions sont
  définies sur le modèle de la fonction d'identité
 */
 
struct fonction_d_activation_s * choix_fonction_d_activation ( id_fonction_d_activation id ){
  struct fonction_d_activation_s * res; // variable locale 
  res = malloc (sizeof (struct fonction_d_activation_s));
  //champs a remplir : 
  res->id ;
  if (id == 0) {
    res -> applique = &fonction_d_activation_Identity;
    res -> derivee = &derivee_fonction_d_activation_Identity;
  } 
  if (id != 0){
    res -> applique = &fonction_d_activation_Racine_carree;
    res -> derivee = &derivee_fonction_d_activation_Racine_carree;
  } 
  return NULL ;
}
   
/*
  Il suffit d'écrire l'id de la fonction d'activation
 */
int sauve_fonction_d_activation ( FILE * f , struct fonction_d_activation_s * fun ) {
  fprintf(f, "%d", fun);
  return 0 ;
}

/*
  il faut lire l'id d'une fonction d'activation dans le fichier f, et mettre le
  choix d'une fonction d'activation correspond à cet id dans *fun.
 */
int lit_fonction_d_activation ( FILE * f , struct fonction_d_activation_s ** fun ){
  int id = 0;
  id = fscanf(f, "%d", id);
  (*fun) = choix_fonction_d_activation(id); 
  return 0 ;
}
/*
  Il faut afficher les différents choix de fonction d'activation possibles, 
  lire le choix de l'utilisateur, et le renvoyer.
 */

id_fonction_d_activation demande_fonction_d_activation (){
  int id;
  //on prends dans le fichier utils.c une foncton qui se rapproche le plus possible de ce qu'on cherche a faire.
  //ici, on va utiliser lire_entier car on doit afficher l'id de la focntion d'activation chosie. 
  id = printf("l'id de la fonction d'activation est : %d ", lire_entier(stdin));
  return 0 ;
}
