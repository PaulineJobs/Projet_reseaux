//#include <malloc.h>
#include <stdio.h>
#include "utils.h"
#include "matrices.h"
#include "matrices_accesseurs.h"
#include "activation.h"
#include "couches_struct.h"
#include "reseau_struct.h"
#include "reseau.h"

#include "couches_entree.h"
#include "couches_sortie.h"
#include "couches_activation.h"
#include "couches_matrice.h"

/*
  Libère la mémoire allouée lors de la création d'un réseau
 */
void detruit_reseau ( struct reseau_s * r ){
		//on fait une boucle qui parcourt toutes les couches du reseau en partant de la dernière
    for ( int i = r->nb_couches - 1 ; i >= 0  ; i-- ){ 
		//Pour chaque couche, on appelle la fonction détruit qui se trouve dans la structure couche_s du reseau r (dans couches_struct.h)
		//Cela permet de détruire la struct couche_s sur laquelle pointe le réseau
		r->couche[i]->detruit(r->couche[i]);
    }
    //Ensuite on détruit le réseau
    free(r);
}

/*
  Renvoie activation.s de la couche d'entrée
 */
struct matrice_s * reseau_get_entree ( struct reseau_s * r ){
	//Dans le fichier "couches_struct.h"
	//On voit que la fonction réseau pointe sur une structure "couche_s"
	//On choisi de pointer sur la couche d'entrée 
	//Cette structure couche_s pointe sur une structure "inter_couche_s activation"
	//Celle ci pointe sur "la couche précédente" notée "s" (de type "struct matrice_s *")
	// et donc on renvoie cette couche suivante en parcourant le chemin décrit ci-dessus pour y arriver
	
	//Mais avant tout il faut savoir quelle est la couche d'entrée, alors on parcourt toutes les couches du réseau,
	// et on test le type jusqu'à ce qu'on tombe sur la couche d'entrée
	for (int i=0; i<r->nb_couches ; i++){
		if ( r->couche[i]->t == 0){ //lorsque t=0 on est sur une couche d'entrée
			return (r->couche[i]->activation.s) ;
		}
	}
	return NULL;
}

/*
  Renvoie activation.p de la couche de sortie
 */
struct matrice_s * reseau_get_sortie ( struct reseau_s * r ){
	//On voit que la fonction réseau pointe sur une structure "couche_s"
	//On choisi de pointer sur la couche de sortie qui est la couche d'indice "r->nb_couches-1"
	//Cette structure couche_s pointe sur une structure "inter_couche_s activation"
	//Celle ci pointe sur "la couche précedente" notée "p" (de type "struct matrice_s *")
	// et donc on renvoie cette couche précédente en parcourant le chemin décrit ci-dessus pour y arriver
	
	//Mais avant tout il faut savoir quelle est la couche d'entrée, alors on parcourt toutes les couches du réseau,
	// et on test le type jusqu'à ce qu'on tombe sur la couche d'entrée
	for (int i=0; i<r->nb_couches ; i++){
		if ( r->couche[i]->t == 1){ //lorsque t=1 on est sur une couche de sortie
			return (r->couche[i]->activation.s );
		}
	}
	return NULL;
}
  

/*
  Appelle la fonction propagation de chaque couche en partant de
  la couche 0.
 */
void propagation (struct matrice_s * entree , struct reseau_s * r ){
	//on fait une boucle qui parcourt toutes les couches du reseau en partant de la dernière
    for ( int i = r->nb_couches - 1 ; i >= 0  ; i-- ){
		//Pour chaque couche, on appelle la fonction de propagation qui se trouve dans la structure couche_s du reseau r (dans couches_struct.h)
		r->couche[i]->propagation (entree ,r->couche[i]);
    }
}

/*
  Appelle la fonction retro-propagation de chaque couche en partant de
  la dernière couche.
 */

void retro_propagation (struct matrice_s * sortie_attendue , float lambda ,struct reseau_s * r ){
	//on fait une boucle qui parcourt toutes les couches du reseau en partant de la dernière
    for ( int i = r->nb_couches - 1 ; i >= 0  ; i-- ){ 
		//Pour chaque couche, on appelle la fonction de retropropagation qui se trouve dans la structure couche_s du reseau r (dans couches_struct.h)  
		r->couche[i]->retro_propagation (sortie_attendue,lambda,r->couche[i]);
    }
}

/*
  Écrit le nombre de couche, et appelle la fonction sauve de chaque couche 
  en partant de la dernière couche.
 */
int ecrit_reseau_fichier(FILE * f, struct reseau_s *r) {
    int i ;
    //on ecrit le nombre de couche dans le fichier f
	fprintf ( f , "%d\n" , r->nb_couches ) ;
	//on fait une boucle qui parcourt toutes les couches du reseau en partant de la dernière
	for ( i = r->nb_couches - 1 ; i >= 0  ; i-- ){
		//Pour chaque couche, on appelle la fonction sauve qui se trouve dans la structure couche_s du reseau r (dans couches_struct.h)
        r->couche[i]->sauve ( f , r->couche[i] ) ;
    }
  return 0 ;
}

/*
  cadeau: lit un type de couche, renvoie 0 si un type est trouvé, et 1 sinon.
*/
static int lire_type_de_couche ( FILE * f , type_couche * t ) {
  if ( lire_mot_clef ( f , "sortie" ) )
    *t = type_couche_sortie ;
  else if  ( lire_mot_clef ( f , "entree" ) )
    *t = type_couche_entree ;
  else if ( lire_mot_clef ( f , "matrice" ) )
    *t = type_couche_matrice ;
  else if  ( lire_mot_clef ( f , "activation" ) )
    *t = type_couche_activation ;
  else
    return 1 ;
  return 0 ;
}





/*
  Lit un réseau dans un fichier qui a été écrit par ecrit_reseau_fichier.
 */
 
//ecrit_reseau_fichier écrit le nombre de couches d'un réseau et le contenu de chacune des couches, nous allons donc les lires
int lit_reseau_fichier ( FILE * f ,  struct reseau_s ** r ) {
    int i ;
    //on lit d'abord le nombre de ligne et on le stocke dans le réseau à son emplcement 
	fscanf ( f , "%d\n" , &((*r)->nb_couches)) ; 
	//on lit ensuite toutes les couches une par une avec une boucle et on mets les résulats dans le reseau à leurs emplacements 
    for (i=0; i< (*r)->nb_couches; i++){
		fscanf ( f , "%p\n" ,&((*r)->couche[i]));
    }
    return 0;
}








