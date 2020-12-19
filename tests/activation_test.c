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

    //int result = 0;
    int id;
    //int  fun = 0;
    struct fonction_d_activation_s * reseau;

    printf ("veuillez choisir un id 0 ou 1\n");
    scanf ("Vous avez choisi l'id : %d \n", &id);
//test de la fonction choix_fonction_d_activation
    reseau = choix_fonction_d_activation(id);
    printf ("le choix de la fonction d'activation est : %d \n", reseau -> id);

//test de la fonction sauve_fonction_d_activation
    printf("Test de la fonction sauve_fonction_d_activation\n");
    if (fichier != NULL){
        fprintf (fichier,"%s", "la fonction a affiché : \n");
        sauve_fonction_d_activation(fichier, reseau);
    }
    printf("Il faut aller vérifier dans le fichier fonction_activation.txt ce qu'a écrit la fonction \n\n");


//test de la fonction lit_fonction_d_activation
    printf ("Test de la fonction lit_fonction_d_activation\n");
    if (fichier !=NULL){
        lit_fonction_d_activation(fichier, &reseau);
    }
    printf("Il faut aller vérifier dans le fichier fonction_activation.txt ce qu'a lu la fonction \n\n");

    fclose(fichier);

//test de la fonction demande_fonction_d_activation
    int demande;
    demande = demande_fonction_d_activation();
    printf ("la demande de fonction d'activation est : %d \n", demande);


}