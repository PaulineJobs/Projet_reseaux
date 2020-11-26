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


/* Il s'agit d'un fichier pour tester le module matrice_operations
Nous vous invitons a compiler ce test avec un "make" puis de l'executer avec un "bin/matrices_operations_tests"
Tout vous sera indiqué lors de l'execution !"
*/



/* cest fonctions sont pour utiliser les fonctions one_arg,two args, et three args.
Elles additionnent les carré des coefficients des matrices prises en argument !
*/


float carre_one_arg(float a) {
  return a*a;
}

float carre_two_arg(float a,float b) {
  return (a*a)+(b*b);
}

float carre_three_arg(float a,float b,float c) {
  return (a*a)+(b*b)+(c*c);
}




int main (){
    printf("\n");
    printf("Test du module matrice_operation\n");
    printf("Pour que le test fonctionne, toutes les matrices crées seront des matrices carrées de même dimensions\n");
    printf("\n");

    printf("Création de matrice 1 : \n");
    //déclarartion de la matrice1
    matrice_t matrice1 = NULL;
    //initialisation/création et affichage de la matrice utilisateur :
    matrice1 = creation_matrice_utilisateur();
    printf("la matrice utilisateur 1 est : \n");
	affiche_matrice(matrice1);
    printf("\n");

    printf("Création de matrice 2 : \n");
    //déclarartion de la matrice2
    matrice_t matrice2 = NULL;
    //initialisation/création et affichage de la matrice utilisateur :
    matrice2 = creation_matrice_utilisateur();
    printf("la matrice utilisateur 2 est : \n");
	affiche_matrice(matrice2);
    printf("\n");

    //declaration de mu
    int mu;
    printf("Entrez un entier mu : ");
    scanf("%d",&mu);
    printf("\n");

    

    printf("Test de la fonction transposée_matrice\n");
    //declarartion matrice A
    int nb_lignes=matrice1->nb_lignes ;
	int nb_colonnes=matrice1->nb_lignes ;
    matrice_t matriceA = NULL;
    matriceA=creation_matrice (nb_lignes ,nb_colonnes);
    printf("La transposée de la matrice 1 est : \n");
    transpose_matrice(matrice1,matriceA);
    affiche_matrice(matriceA);
    printf("\n");
    printf("\n");


    printf("Test de la fonction addition_scalaire_matrice:\n");
    //déclaration+allocation matrice 3 
    matrice_t matriceB = NULL;
    matriceB=creation_matrice (nb_lignes ,nb_colonnes);
	addition_matrice_scalaire(matrice1,matrice2, matriceB, mu );
	printf("la matrice 1 + mu*2 est : \n");
	affiche_matrice(matriceB);
    printf("\n");
    printf("\n");

    printf("Test de la fonction multiplication_matrice:\n");
    //declaration matrice C
	matrice_t matriceC = NULL;
	matriceC=creation_matrice (nb_lignes ,nb_colonnes);
	multiplication_matrice(matrice1, matrice2, matriceC );
	printf("la matrice 1 * 2 est : \n");
	affiche_matrice(matriceC);
    printf("\n");
    printf("\n");

    printf("Test de la fonction matrice_apply_one_arg:\n");
    printf("La fonction utilisée élève tout les coefficients de matrice1 au carré\n");
    //declaration matrice D
    matrice_t matriceD = NULL;
    matriceD=creation_matrice (nb_lignes ,nb_colonnes);	
    float (*pointeur_sur_carre_one_arg)(float);
    pointeur_sur_carre_one_arg=&carre_one_arg;
	matrice_apply_one_arg (matrice1,pointeur_sur_carre_one_arg,matriceD);
    printf("f(matrice1[i][j]) est :\n");
    affiche_matrice(matriceD);
    printf("\n");
    printf("\n");
    
    printf("Test de la fonction matrice_apply_two_arg:\n");
    printf("La fonction utilisée élève tout les coefficients de matrice1 et 2 au carré et les additionne\n");
    //declaration matrice E
    matrice_t matriceE = NULL;
    matriceE=creation_matrice (nb_lignes ,nb_colonnes);	
    float (*pointeur_sur_carre_two_arg)(float,float);
    pointeur_sur_carre_two_arg=&carre_two_arg;
	matrice_apply_two_args (matrice1,matrice2,pointeur_sur_carre_two_arg,matriceE);
    printf("f(matrice1[i][j],matrice2[i][j]) est :\n");
    affiche_matrice(matriceE);
    printf("\n");
    printf("\n");

    printf("Test de la fonction matrice_apply_three_args:\n");
    printf("La fonction utilisée élève tout les coefficients de matrice1 ,2, et la transposéee de 1 au carré et les additionne\n");
    //declaration matrice F
    matrice_t matriceF = NULL;
    matriceF=creation_matrice (nb_lignes ,nb_colonnes);	
    float (*pointeur_sur_carre_three_arg)(float,float,float);
    pointeur_sur_carre_three_arg=&carre_three_arg;
	matrice_apply_three_args (matrice1,matrice2,matriceA,pointeur_sur_carre_three_arg,matriceF);
    printf("f(matrice1[i][j],matrice2[i][j],matrice1[i][j](transposée))) est :\n");
    affiche_matrice(matriceF);
    printf("\n");
    printf("\n");


}






