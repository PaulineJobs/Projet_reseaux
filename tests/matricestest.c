//#include <malloc.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
//#include "utils.h"
#include "matrices.h"
#include "matrices_struct.h"



int main (){

    struct matrice_s* matrice = NULL;
    struct matrice_s* m1 = NULL;
    struct matrice_s* m2 = NULL;

    FILE * fichier = NULL;
    int result = 0;

    int lignes = 2;
    int colonnes = 2;

    //initialisation/création et affichage de la matrice utilisateur :
    matrice = creation_matrice_utilisateur();
    printf("\nLa matrice utilisateur est : \n");

    affiche_matrice(matrice);

    //ecriture de la matrice utiisateur dans un fichier : 
    fichier = fopen("tests/matrice_ecrite.txt", "w");
    if (fichier != NULL) {
        result = sauve_matrice_fichier(fichier, matrice);
    }
    printf("\nsauve_matrice_fichier renvoie : <%d>\n", result);
    fclose(fichier);

    detruit_matrice(matrice);
    printf("La mémoire occupée par la matrice a été libéré \n");

    //lecture d'une matrice dans un fichier : 
    fichier = fopen("matrice.txt", "r");
    if (fichier != NULL) {
        result = lire_matrice_fichier(fichier, &matrice);
    }
    printf("lire_matrice_fichier renvoie : <%d>\n\n", result);
    fclose(fichier);
    
    //initialisation/création et affichage de la matrice aléatoire : 
    matrice = creation_matrice_aleatoire(lignes, colonnes);
    printf("La matrice aléatoire est : \n");
    affiche_matrice(matrice);

    //copie de la matrice m1 dans la matrice m2.
    printf("\nTest de la fonction copie_matrice\n");
    printf("La matrice m1 est : \n");
    m1 = creation_matrice_aleatoire(lignes,colonnes);
    affiche_matrice(m1);
    printf("La matrice m2 est la copie de la matrice m1 : \n");
    m2 = creation_matrice(lignes, colonnes);
    copie_matrice(m1,m2);
    affiche_matrice(m2);


}

