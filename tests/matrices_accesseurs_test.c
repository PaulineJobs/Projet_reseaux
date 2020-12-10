#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "matrices_struct.h"
#include "matrices_accesseurs.h"

struct matrice_s * creation_matrice ( int nb_lignes , int nb_colonnes ){
    int tmp_ligne;
    struct matrice_s * tmp_new_matrice;

    // demander au systeme d'allouer de la mémoire pour stocker une structure matrice.
    tmp_new_matrice = (struct matrice_s *) malloc(sizeof(struct matrice_s *));
    //printf("Toute la matrice est ok");

    //a la matrice qui "pointe" vers le nombre de lignes (resp. colonnes) on lui donne la valeur nb_lignes (resp. nb_colonnes)
    tmp_new_matrice->nb_lignes = nb_lignes;
    tmp_new_matrice->nb_cols = nb_colonnes;

    //alloue un tableau de nb_lignes tableaux; (c'est ce qui est écrit dans le code du prof)
    //demander au systeme d'allouer de la mémoire pour qu'à chaque ligne il y ai assez de mémoire pour y stocker un pointeur vers un float (qui sera le nb de colonne)
    tmp_new_matrice->matrice = (float **) malloc(tmp_new_matrice->nb_lignes * sizeof(float *)); 
    //printf("toute les lignes sont ok");

    for (tmp_ligne=0; tmp_ligne < tmp_new_matrice->nb_lignes; tmp_ligne++){
        // demander au systeme d'allouer de la mémoire pour qu'a chaque colonne il y ai assez de memoire pour y stocker un float 
        tmp_new_matrice->matrice[tmp_ligne]= (float *) malloc (tmp_new_matrice->nb_cols*sizeof(float));
        //printf("toutes les colonnes sont ok");
    }

	return tmp_new_matrice;
}


int main()
{
	struct matrice_s * test = NULL;
	int l=2;
	int c=3;
	test = creation_matrice(l,c);
	//test = malloc(sizeof(struct matrice_s *));
	//test->nb_lignes=2;
	//test->nb_cols=3;
	printf("Matrice initialisee :\nligne =2\ncolonne=3\n_____\n\n");
	
	int ligne;
	int colonne;
	
	ligne=nb_lignes(test);
	printf("Test 1 pour la fonction nb_lignes (doit afficher 2): %d \n\n", ligne);
	
	
	
	colonne=nb_cols(test);
	printf("Test 2 pour la fonction nb_cols (doit afficher 3): %d \n\n", colonne);
	
	
	int val1 = 1;
	int val2 = 2;
	float flt = 40;
	printf("Test 3 pour la fonction matrice_set :\nOn va entrer la valeur 40 a la ligne 1, colonne 2\n");
	matrice_set(test, val1, val2, flt);
	printf("La valeur 40 est dans la matrice au bon emplacement\n\n");
	
	float *pointeurflt;
	pointeurflt = &(flt);
	printf("Pour le Test 4, on va pouvoir vérifier si la fonction précédente a bien été effectuee\n");
	matrice_get(test, val1, val2, pointeurflt);
	printf("Adresse modifiee par la fonction : %p \n\n", pointeurflt);
	printf("Valeur a cette adresse : %f\n\n", *pointeurflt);
	
	
	
	float *** raw;
	raw=matrice_raw(test);
	printf("Test 5 pour fonction matrice_raw, renvoie l'adresse : %p\n",raw);
	
	
	
	
	
	
	
	
	return 0;
}
	