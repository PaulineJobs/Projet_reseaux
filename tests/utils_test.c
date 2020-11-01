#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

/* Ce que contient le fichier testutils.txt:
 
 10 1 50 3.14 informatique
 
*/



int main(){
	
	FILE* fichier = NULL;
	fichier = fopen("testutils.txt", "r");
    
    printf("La fonction log_show_position renvoie : \n"); 
    log_show_position (fichier);
    printf("\n");
    
    int entier = lire_entier (fichier);
    printf("La fonction LireEntier renvoie entier = %d\n",entier); //renvoie la valeur 10
    log_show_position (fichier);                                   // renvoie la position de l'entier 10 (ici 2)
    printf("\n");
    
    int minimum=5;
    int maximum=100;
    int entierIntervalle = lire_entier_intervalle (fichier,minimum,maximum ); //lit 1 qui n'est pas dans l'intervalle puis renvoie 50
    printf("La fonction LireEntierIntervalle renvoie entier = %d\n",entierIntervalle);
    log_show_position (fichier);                                              // renvoie la position de l'entier 10 (ici 7)
    printf("\n");
    
    float flottant;
    flottant = lire_float (fichier);                                     
    printf("La fonction LireFlottant renvoie entier = %f\n",flottant); //renvoie la valeur 3.14
    
    char *chaine;
    chaine = lire_string (fichier);
    printf("La fonction lire_string renvoie : %s\n",chaine); //renvoie le mot informatique
  
	return 0;	
}


