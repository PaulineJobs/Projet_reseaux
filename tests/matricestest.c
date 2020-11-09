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

    matrice_t matrice = NULL;
    FILE * fichier = NULL;
    int result = 0;

    int lignes = 2;
    int colonnes = 2;

    //initialisation/création et affichage de la matrice utilisateur :
    matrice = creation_matrice_utilisateur();
    printf("la matrice utilisateur est : \n");

    affiche_matrice(matrice);

    //ecriture de la matrice utiisateur dans un fichier : 
    fichier = fopen("matrice_ecrite.txt", "w");
    if (fichier != NULL) {
        result = sauve_matrice_fichier(fichier, matrice);
    }
    printf("sauve_matrice_fichier renvoie : <%d>\n", result);
    fclose(fichier);

    detruit_matrice(matrice);
    printf("La mémoire occupée par la matrice a été libéré \n");

    //lecture d'une matrice dans un fichier : 
    fichier = fopen("matrice.txt", "r");
    if (fichier != NULL) {
        result = lire_matrice_fichier(fichier, &matrice);
    }
    printf("lire_matrice_fichier renvoie : <%d>\n", result);
    fclose(fichier);
    
    //initialisation/création et affichage de la matrice aléatoire : 
    matrice = creation_matrice_aleatoire(lignes, colonnes);
    printf("La matrice aléatoire est : \n");
    affiche_matrice(matrice);

}

