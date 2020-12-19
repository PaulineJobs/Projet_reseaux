#include <math.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
//#include <malloc.h>
#include "activation_struct.h"
#include "activation.h"
#include "utils.h"

int main(){
    FILE * fichier = NULL;
    fichier = fopen ("tests/fonction_activation.txt", "w+");

//test de la fonction choix_fonction_d_activation
    printf ("Test du module activation\n");
    printf ("\n");
    printf ("Test de la fonction choix_fonction_d_activation\n");
    id_fonction_d_activation id=0;
    float x=0 ;
    float y=0;
    struct fonction_d_activation_s * reseau;
    //printf ("veuillez choisir un id 0 ou 1 : ");
    //scanf ("%d", &id);
    id = demande_fonction_d_activation();
    reseau = choix_fonction_d_activation(id);
    printf ("veuillez choisir un entier pour vérifier votre fonction (vous pourrez en déduire s'il s'agit de la fonction identity ou racine carrée): ");
    scanf ( "%f", &x);
    printf("la fonction f(%f) est : %f\n",x,reseau-> applique(x));
    printf("Sa dérivée est f'(%f) : %f\n",x,reseau-> derivee(x,y));
    printf ("\n");
    fclose(fichier);

//test de la fonction sauve_fonction_d_activation

    printf("Test de la fonction sauve_fonction_d_activation\n");
    fichier = fopen ("tests/fonction_activation.txt", "w+");
    printf ("veuillez choisir un id 0 ou 1 : ");
    scanf ("%", &id);
    reseau = choix_fonction_d_activation(id);
    if (fichier != NULL){
        sauve_fonction_d_activation(fichier, reseau);
    }
    printf("Veuillez ouvrir le fichier tests/fonction_activation.txt et vérifiez que l'id soit bien %d",reseau->id);
    fclose(fichier);
    printf ("\n\n");

//test de la fonction lit_fonction_d_activation
    printf ("Test de la fonction lit_fonction_d_activation\n");
    fichier = fopen ("tests/fonction_activation.txt", "r");
    

    if (fichier !=NULL){
        printf ("l'id écrite par la fonction sauve_fonction_d_activation est :");
        lit_fonction_d_activation(fichier, &reseau);
        printf ("%d",reseau->id);
    }

    fclose(fichier);
    printf ("\n\n");


//test de la fonction demande_fonction_d_activation
    /*printf ("Test de la fonction demande_fonction_d_activation");
    int demande;
    demande = demande_fonction_d_activation();
    printf ("Vous avez demandé la fonction d'activation numéro %d \n", demande);
*/

}
