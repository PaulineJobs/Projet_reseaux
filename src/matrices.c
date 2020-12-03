//#include <malloc.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
//#include "utils.h"
#include "matrices.h"
#include "matrices_struct.h"



/*
    La structure de FILE se trouve dans <stdio.h>
*/

/* 
Vocabulaire/syntaxe :
    a->b signifie "a qui pointe vers/dont le pointeur est sur b" on utilise "->" pour acceder a la valeur du pointeur. 
    Si a et b n'étaient pas des pointeurs, on aurait écrit "a.b".

    tmp = temporaire

    fscanf = permet de lire dans un fichier 
    fprintf = permet d'écrire dans un fichier 
    fopen = permet d'ouvrir un fichier 
    fclose = permet de fermer un fichier 

    Lorsqu'il n'y a qu'une seule ligne de code dans un boucle for, un if, while,... on n'est pas obligé de mettre d'accolades.

*/

/* 
Rappels : 
    \n : retour chariot
    \t : tabulation
*/

/*
Aides : 
    Cours OpenClassroom : 
            - Apprenez à programmer en C!
            - Lire et écrire dans des fichiers
*/

/* Cette fonction libère toute la mémoire qui a été allouée dans la
fonction suivante pour stocke une matrice */
void detruit_matrice ( struct matrice_s * m ){
    int i;
    int j;
    for (i=0; i < m->nb_lignes; i++){
        for (j=0; j< m->nb_cols; j++) {
            m->matrice[i][j] = 0;
         }
        //libere la memoire de m qui pointe vers la matrice ligne i :
        free(m->matrice[i]);
    }

    //libere la memoire de la matrice m qui pointe vers matrice :
    free(m->matrice);
    //le nombre de ligne et de colonnes de la matrice m vaut 0 :
    m->nb_lignes = 0; 
    m->nb_cols = 0;
    //libere la memoire de la matrice :
    free(m);
    return;
}



/*Cette fonction alloue de la place pour stocker une structure 
matrice, un tableau de ligne, ainsi que chaque ligne */
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

/*
  Si *e == NULL , il faut créer une matrice 1 x n et la mettre dans
  *e.  Maintenant que *e contient une matrice 1 x n, il faut recopier
  les coefficients du tableau t dans cette matrice.
 */
int matrice_ligne ( struct matrice_s * * e , float * t , int n ) {
  int i ;
  if( *e == NULL )
          {
            *e = creation_matrice ( 1 , n ) ;
          }
  for ( i = 0 ; i < n ; i++ )
    (*e)->matrice[0][i] = t[i] ;
  return 0 ;
}


/*
  Cette fonction crée et initialise une matrice n x m avec des |float|
  dans [ -1 , 1 ].
*/
/* Cette fonction appelle la fonction creation_matrice, puis 
met un nombre aléatoire entre -1 et 1 (un float) dans chaque
coefficient. */
struct matrice_s * creation_matrice_aleatoire ( int in_nb_lignes , int in_nb_colonnes ){
    int i,j;
    struct matrice_s *   tmp_out_matrice;
    float       tmp_valeur;

    //on alloue de la memoire pour contenir les valeur de la matrice aleatoire : 
    tmp_out_matrice = creation_matrice(in_nb_lignes, in_nb_colonnes);
    //initialisation de la fonction rand(). 'time' correspond au fichier time.h qui est en faite l'horloge du pc. : 
    srand(time(NULL));

    for (i=0; i<in_nb_lignes;i++){    // on peut remplacer par : for (i=0; i < tmp_out_matrice->nb_lignes; i++) 
        for (j=0;j<in_nb_colonnes;j++){  // on peut remplacer par : for (j=0; j < tmp_out_matrice->nb_cols; j++)

            /* la fonction rand() prend des valeurs entre 0 et RAND_MAX (se trouve dans la definition de la fonction rand())
            donc pour avoir des valeurs entre -1 et 1, on multiplie rand() par deux puis on divise par RAND_MAX.
            Ensuite on soustrait 1, ce qui va donner des valeurs entre -1 et 1*/  
            tmp_valeur = ((2*rand())-1);
            tmp_out_matrice->matrice[i][j]=tmp_valeur/RAND_MAX;
        }
    }
	return tmp_out_matrice;
}


/*
  Cette fonction demande à l'utilisateur les dimensions et les
  coefficients d'une matrice, et renvoie la matrice correspondante.
*/
/* Cette fonction commence par demander à un utilisateur le nombre de
lignes et de colonnes de la matrice à créer. Elle appelle la
fonction creation_matrice, puis demande à l'utilisateur chaque
coefficient. */
struct matrice_s * creation_matrice_utilisateur ( ){
    int i,j;
    int tmp_nb_lignes_lu = 0;
    int tmp_nb_cols_lu = 0;
    struct matrice_s * tmp_out_matrice;

    printf("Nbre de lignes désirées : ");
    scanf("%d", &tmp_nb_lignes_lu);
    printf("Nbre de colonnes désirées : ");
    scanf("%d", &tmp_nb_cols_lu);

    //on alloue de la memoire pour contenir les valeur de la matrice de l'utilisateur : 
    tmp_out_matrice = creation_matrice(tmp_nb_lignes_lu, tmp_nb_cols_lu);
    //printf("on a crée la memore matrice \n");

    for (i=0;i<tmp_nb_lignes_lu; i++){
        for (j=0; j<tmp_nb_cols_lu; j++){
            printf("Veuillez saisir un nombre entre -1 et 1 pour la valeur de la ligne %d  de la colonne %d : ", i,j);
            scanf("%f",&tmp_out_matrice->matrice[i][j]);
        }
    }
    return tmp_out_matrice;
}



/* les deux fonctions suivantes lisent et écrivent des matrices dans
des fichiers déjà ouverts. Le format choisi est d'écrire le nombre
de lignes et de colonnes de la matrice, puis tous les
coefficients.
*/
/*
  Cette fonction lit une matrice qui a été stockée dans un fichier.
*/
//La fonction suivante lit dans le fichier le nombre de lignes, colonnes, ainsi que les valeurs de la matrice.
int lire_matrice_fichier ( FILE * f , struct matrice_s * * m ){     // utilisation : result = lire_matrice_fichier (mon_fichier, ma_matrice);
    int i,j;
    struct matrice_s *  tmp_out_matrice;
    int tmp_nb_lignes_lu = 0;
    int tmp_nb_cols_lu = 0;

    //on lit d'abord le nombre de lignes et de colonnes de la matrice  dans le fichier f  
    fscanf(f, "%d", &tmp_nb_lignes_lu);
    fscanf(f, "%d", &tmp_nb_cols_lu);

    //on alloue de la memoire pour contenir les valeur de la matrice à lire : 
    tmp_out_matrice = creation_matrice (tmp_nb_lignes_lu, tmp_nb_cols_lu);

    for (i = 0; i < tmp_out_matrice->nb_lignes; i++) {
        for (j = 0; j < tmp_out_matrice->nb_cols; j++) {
            fscanf(f, "%f", &(tmp_out_matrice->matrice[i][j]) );
        }
    }
    
    printf("La matrice lue est : \n");
    affiche_matrice(tmp_out_matrice);

    m =  &tmp_out_matrice;

    return 1;
}

/*
  Cette fonction sauve une matrice dans un fichier. Elle
  doit utiliser la même format que lit_matrice_fichier
*/
//La fonction suivante ecrit dans le fichier le nombre de lignes, colonnes, ainsi que les valeurs de la matrice.
int sauve_matrice_fichier ( FILE * f , struct matrice_s * m ){
    int i,j;

    fprintf(f,"%d", m->nb_lignes);
    fprintf(f,"%d", m->nb_cols);
    
    for (i=0; i<m->nb_lignes; i++){
        for (j=0; j<m->nb_cols; j++){
            fprintf(f,"%f", m->matrice[i][j]);
        }
    }
    return 1 ;
}



/*
  Cette fonction affiche une matrice.
*/
// Affichage d'une matrice :  
void affiche_matrice ( struct matrice_s * m ){
    //affichage du nombre contenu dans la ligne i à la colonne j
    int i=0;
    int j=0;
    
    for (i=0; i<(m->nb_lignes); i++){
        for (j=0; j<(m->nb_cols); j++){
          printf("%f \t", (m->matrice[i][j]));

        }
        printf("\n");
    }
    return;
}

/*
  Copie le contenu de la matrice m1 dans la matrice m2.
  Les 2 matrices existent et ont les mêmes dimensions.
*/
int copie_matrice(
                  struct matrice_s * m1,
                  struct matrice_s * m2 )
{
  return 0 ;
}

