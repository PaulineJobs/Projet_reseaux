//#include <malloc.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
//#include "utils.h"
#include "matrices.h"
#include "matrices_struct.h"
#include "matrices_operations.h"


int main (){

    matrice_t matrice1 = NULL;
	matrice_t matrice2 = NULL;
	matrice_t matrice3 = NULL;

	matrice_t matrice4 = NULL;
	matrice_t matrice5 = NULL;


	int nb_lignes=2 ;
	int nb_colonnes=2;
	
	matrice3=creation_matrice (nb_lignes ,nb_colonnes);
	int mu=2;

	matrice5 = creation_matrice (nb_lignes, nb_colonnes);
	
    //initialisation/création et affichage de la matrice utilisateur :
    matrice1 = creation_matrice_utilisateur();
    printf("la matrice utilisateur 1 est : \n");
	affiche_matrice(matrice1);
	
	//initialisation/création et affichage de la matrice utilisateur :
    matrice2 = creation_matrice_utilisateur();
    printf("la matrice utilisateur 2 est : \n");
	affiche_matrice(matrice1);
	
	
	addition_matrice_scalaire(matrice1,matrice2, matrice3, mu );
	printf("la nouvelle matrice utilisateur 3 est : \n");
	affiche_matrice(matrice3);

	matrice4 = creation_matrice_utilisateur();
	printf("la matrice utilisateur 4 est : \n");
	affiche_matrice(matrice4);

	transpose_matrice(matrice4, matrice5);
	printf("la nouvelle matrice 5 (transposée de la matrice 4) est : \n");
	affiche_matrice(matrice5);
 

}
