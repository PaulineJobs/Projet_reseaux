#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "matrices_struct.h"
#include "matrices_accesseurs.h"

struct matrice_s * creation_matrice ( int nb_lignes , int nb_colonnes ){
    int tmp_ligne;
    struct matrice_s * tmp_new_matrice;

    // demander au systeme d'allouer de la memoire pour stocker une structure matrice.
    tmp_new_matrice = (struct matrice_s *) malloc(sizeof(struct matrice_s *));
    //printf("Toute la matrice est ok");

    //a la matrice qui "pointe" vers le nombre de lignes (resp. colonnes) on lui donne la valeur nb_lignes (resp. nb_colonnes)
    tmp_new_matrice->nb_lignes = nb_lignes;
    tmp_new_matrice->nb_cols = nb_colonnes;

    //alloue un tableau de nb_lignes tableaux; (c'est ce qui est ecrit dans le code du prof)
    //demander au systeme d'allouer de la memoire pour qu'à chaque ligne il y ai assez de memoire pour y stocker un pointeur vers un float (qui sera le nb de colonne)
    tmp_new_matrice->matrice = (float **) malloc(tmp_new_matrice->nb_lignes * sizeof(float *)); 
    //printf("toute les lignes sont ok");

    for (tmp_ligne=0; tmp_ligne < tmp_new_matrice->nb_lignes; tmp_ligne++){
        // demander au systeme d'allouer de la memoire pour qu'a chaque colonne il y ai assez de memoire pour y stocker un float 
        tmp_new_matrice->matrice[tmp_ligne]= (float *) malloc (tmp_new_matrice->nb_cols*sizeof(float));
        //printf("toutes les colonnes sont ok");
    }

	return tmp_new_matrice;
}


int main()
{
	struct matrice_s * test = NULL;
	int l = 0;
	int c = 0;
	printf("Test pour le module matrice accesseur\n\nVous allez tout d'abord initialiser une matrice, pour pouvoir tester les fonctions\n");
	printf("Veuillez entrer un nombre de lignes, puis un nombre de colonnes\n");
	scanf("%d", &l);
	scanf("%d", &c);
	test = creation_matrice(l,c);
	printf("Matrice initialisee :\nligne = %d \ncolonne = %d \n_____\n\n", l, c);

	int ligne;
	int colonne;
	
	ligne=nb_lignes(test);
	printf("Test 1 pour la fonction nb_lignes\nLa matrice possede %d lignes\n_____\n\n", ligne);
	
	
	
	colonne=nb_cols(test);
	printf("Test 2 pour la fonction nb_cols\nLa matrice possede %d colonnes\n_____\n\n", colonne);
	
	
	int val1 = 0;
	int val2 = 0;
	float flt = 0.0;
	printf("Test 3 pour la fonction matrice_set :\n\n");
	
	printf("Renseignez la valeur a entrer dans la matrice\n");
	scanf("%f", &flt);
	
	printf("Veuillez indiquer la ligne a laquelle vous souhaitez entrer cette valeur (en considerant le nombre de lignes de votre matrice)\n");
	scanf("%d", &val1);
	
	printf("Veuillez indiquer la colonne a laquelle vous souhaitez entrer cette valeur (en considerant le nombre de colonnes de votre matrice\n");
	scanf("%d", &val2);
	
	matrice_set(test, val1, val2, flt);
	printf("La valeur %f est dans la matrice au bon emplacement\n____\n\n", flt);
	
	float *pointeurflt;
	pointeurflt = &(flt);
	printf("Pour le Test 4, on va pouvoir verifier si la fonction precedente a bien ete effectuee\n");
	matrice_get(test, val1, val2, pointeurflt);
	printf("Adresse modifiee par la fonction : %p \n", pointeurflt);
	printf("Valeur a cette adresse : %f\n_____\n\n", *pointeurflt);
	
	
	
	float *** raw;
	raw=matrice_raw(test);
	printf("Test 5 pour fonction matrice_raw\nRenvoie l'adresse : %p\n",raw);
	
	
	
	
	
	
	
	
	return 0;
}
	