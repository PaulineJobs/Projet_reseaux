//#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "matrices.h"
#include "matrices_accesseurs.h"
#include "activation.h"
#include "couches_struct.h"
#include "reseau_struct.h"
#include "reseau.h"
#include "activation_struct.h"
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
		//Pour chaque couche, on appelle la fonction détruit qui se trouve dans la structure couche_s du reseau r 
		//Cela permet de détruire la struct couche_s sur laquelle pointe le réseau
		r->couche[i]->detruit(r->couche[i]);
    }
    // aprés avoir détruit toutes les couches du réseau,
    //on détruit le réseau
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
	// et on teste le type jusqu'à ce qu'on tombe sur la couche d'entrée
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
	//On choisi de pointer sur la couche de sortie
	//Cette structure couche_s pointe sur une structure "inter_couche_s activation"
	//Celle ci pointe sur "la couche précedente" notée "p" (de type "struct matrice_s *")
	// et donc on renvoie cette couche précédente en parcourant le chemin décrit ci-dessus pour y arriver
	
	//Mais avant tout il faut savoir quelle est la couche de sortiee, alors on parcourt toutes les couches du réseau,
	// et on teste le type jusqu'à ce qu'on tombe sur la couche d'entrée
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
	//on fait une boucle qui parcourt toutes les couches du reseau en partant de la première
    for (int i=0; i< r->nb_couches; i++){
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
    struct matrice_s * matricetmp;
    struct fonction_d_activation_s * funtmp;
    
    // allocation de la mémoire pour la structure
    r=malloc(sizeof (struct reseau_s));
    for (i=0; i< (*r)->nb_couches; i++){
		(*r)->couche[i]=malloc (sizeof (struct couche_s));
		
	}
    
    //on lit d'abord le nombre de couches et on le stocke dans le réseau à son emplacement 
	fscanf ( f , "%d\n" , &((*r)->nb_couches)) ; 
	//on parcourt les couches 
    
    //on verifie que le type couche soit bien définie
    if (lire_type_de_couche (f,&(*r)->couche[i]->t )==1){
        printf("le type de la couche est undéfini");
    } else {

	    for ( int i = (*r)->nb_couches - 1 ; i >= 0  ; i-- ){
		    // on lit le type de la couche, et selon son résultat on effectue les taches suivantes
		
		    if (lire_mot_clef(f, "entree")== 0 ) { //la couche est de type couche_entree
			    (*r)->couche[i]->t=type_couche_entree;
                // on appelle la fonction  struct couche_s *couche_entree (couche_s * suivante )
                //Je préfère le dire en commenatire plutot que de l'appeler car je ne sais pas comment elle se 
                //comporte et je ne voudrais pas faire de bétise
		    }
		    if (lire_mot_clef(f, "sortie") == 0){//la couche est de type couche_sortie
			    (*r)->couche[i]->t=type_couche_sortie;
                // on appelle la fonction  struct couche_s *couche_sortie (int n )
                //Je préfère le dire en commenatire plutot que de l'appeler car je ne sais pas comment elle se 
                //comporte et je ne voudrais pas faire de bétise
		    }
		    if (lire_mot_clef(f, "matrice") == 0){//la couche est de type couche_matrice
			    //on lit la matrice à l'aide de "lire_matrice_fichier"
			    // on la stocke dans la matrice de l'union data de la structure couche du reseau
			    (*r)->couche[i]->t=type_couche_matrice;
			    lire_matrice_fichier (f ,&matricetmp );
			    (*r)->couche[i]->data.m =matricetmp;
                // je sais qu'il faut appeler struct couche_s *couche_matrice (int n , struct couche_s * suivante  ) ;
                // mais je ne sais pas dans quelle condition
		    }
		    if (lire_mot_clef(f, "activation") == 0){//la couche est de type couche_activation
			    //on lit la fonction d'activation à l'aide de "lit_fonction_d_activation"
			    // on la stocke dans la fonction d'activation de l'union data de la structure couche du reseau
			    (*r)->couche[i]->t=type_couche_activation;
		        funtmp=malloc(sizeof(struct fonction_d_activation_s));
			    lit_fonction_d_activation (f ,&funtmp );
			    (*r)->couche[i]->data.f =funtmp;
                // je sais qu'il faut appeler struct couche_s * couche_activation (struct fonction_d_activation_s * fun ,struct couche_s * suivante ) ;
                // mais je ne sais pas dans quelle condition
		    }
	    }
    }
    return 0;
}








