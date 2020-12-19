#include <math.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
//#include <malloc.h>
#include "activation_struct.h"
#include "activation.h"
#include "utils.h"


/*
  static permet de rendre les fonctions invisibles en dehors du module
  (méthodes privées en Java)
 */
//Si dessous sont la fonction d'activation identité ainsi que sa dérivée
static float fonction_d_activation_Identity ( float x ){
  return x ;
}
static float derivee_fonction_d_activation_Identity ( float x , float fx ){
  return 1 ;
}

//ci dessous sont la fonction d'activation racine carrée ansi que sa dérivée 
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
 
struct fonction_d_activation_s * choix_fonction_d_activation ( id_fonction_d_activation id_fonction_d_activation ){
  struct fonction_d_activation_s * res; // variable locale 
  res = malloc (sizeof (struct fonction_d_activation_s));
  //champs a remplir : 
  res->id = id_fonction_d_activation ;
  //Si l'id de la fonction d'activation est 0, alors cela correspond a la fonction d'activation identité.
  if (res->id == 0) {
    //Au réseau (res) qui pointe sur applique, on y met l'adresse de la fonction d'activation identité
    res -> applique = &fonction_d_activation_Identity;
    //Au réseau (res) qui pointe sur derivee, on y met l'adresse de la dérivée de la fonction d'activation identité
    res -> derivee = &derivee_fonction_d_activation_Identity;
  } 

  //Si l'id de la fonction d'activation est different de 0, cela correspond alors à la fonction d'activation racine carrée
  if (res->id != 0){
    //Au réseau (res) qui pointe sur applique, on y met l'adresse de la fonction d'activation racine carrée 
    res -> applique = &fonction_d_activation_Racine_carree;
    //Au réseau (res) qui pointe sur applique, on y met l'adresse de la dérivée de la fonction d'activation racine carrée
    res -> derivee = &derivee_fonction_d_activation_Racine_carree;
  } 
  return res ;
}
   
// Cette fonction permet d'ecrire l'id de la fonction d'activation dans un fichier f.
int sauve_fonction_d_activation ( FILE * f , struct fonction_d_activation_s * fun ) {
  fprintf(f, "%d", fun->id);
  return 0 ;
}



/*
  il faut lire l'id d'une fonction d'activation dans le fichier f, et mettre le
  choix d'une fonction d'activation correspond à cet id dans *fun.
 */
int lit_fonction_d_activation ( FILE * f , struct fonction_d_activation_s ** fun ){
  id_fonction_d_activation id;
  id=lire_entier (f);
  (*fun) = choix_fonction_d_activation(id); 
  return 0 ;
}



id_fonction_d_activation demande_fonction_d_activation (){
  id_fonction_d_activation id_choisi;
  printf("\n");
  printf("L'id de la fonction d'activation identité est 0 \n");
  printf("L'id de la fonction d'activation racine carrée est 1 \n");
  printf("Veuillez choisir l'id que vous souhaitez.\n");
  scanf ("%d", &id_choisi);
  printf("\n");

  return id_choisi ;
}
