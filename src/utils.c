#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include <string.h>
#include "utils.h"




/*
 
PREREQUIS (openclassroom "coder en c"):-La programmation modulaire
 										-A l'assaut des pointeurs
										-créez vos propres types de variables (structures)
										-Lire et ecrire dans des fichiers 
 

POINT CULTURE: LIRE ET ECRIRE DANS DES FICHIERS

	Il y a diverses fonctions qui permettentde manipuler un fichier à travers un programme:
	-"fopen" permet d'ouvrir un fichier
	-"fclose" permet de fermer un fichier 
	-"fscanf" permet de lire une donnée contenue dans le fichier 
	Ces fonctions renvoient un pointeur sur une structure de type FILE 



POINT CULTURE : LA STRUCTURE FILE

	-Se trouve dans le <stdio.h>
 
	-La structure FILE permet de stocker les informations relatives à la gestion d'un flux de données.
	 Il existe un grand nombre de fonctions qui acceptent un paramètre basé sur cette structure.

	-stdin : ce flot correspond au flux standard d'entrée de l'application.  
			Quelques fonctions utilisent implicitement ce flux (scanf, par exemple).

	-stdout : c'est le flux standard de sortie de votre application. 
			Quelques fonctions utilisent implicitement ce flux (printf, par exemple)
 
	-stderr : ce dernier flux est associé à la sortie standard d'erreur de votre application. 
			Tout comme stdout, ce flux est normalement redirigé sur la console de l'application.

*/


/*
	LOG_SHOW_POSITION: Indication des professeurs:
 
	C'est cadeau parce que ça fait plaisir :)
	(et on ne verra pas la fonction ftell de toutes façons)
* 
*/
 
void log_show_position ( FILE * f ) {
	                                         
	assert ( f != NULL ) ;                   
	log ( "position %ld" , ftell (f));   //La fonction ftell() retourne la position actuelle au sein du fichier sous forme d'un long
  
}


/*
  Voir les TPs, = libentrée, sauf qu'on lit dans un fichier f
 */
void lire_donnee ( FILE * f , char * format , void * res ){         //extrait la donnée correspondant au format dans le fichier et la retourne dans la variable pointée par res
	fscanf(f,format,res);                                           //fscanf lit "res" de format"format"
	
}


int lire_entier ( FILE * f ){          // lit un entier dans le fichier f de type FILE                  
	int entier;                                
	fscanf(f,"%d",&entier);              //fscanf lit le premier entier dans le fichier f et le met dans la variable "entier"         
	return entier;                     //on return l'entier lu        
}

/*
  LIRE_ENTIER_INTERVALLE: Indication des professeurs:
 
	Recommence lire_entier tant que l'entier n'est pas >= au
	min et < au max. Si le max est inférieur ou égal au min,
	il n'est pas testé. Donc:
		lire_entier_positif ( & n ) ;
	fait la même chose que:
		lire_entier_intervalle ( stdin , 0 , 0 ) ;
*/

int lire_entier_intervalle (FILE * f, int min, int max ) {       // lit un entier dans un intervalle donné dans le fichier f de type FILE             
	int entier;
	if (max < min){                                               // on verifie que l'intervalle soit bien defini
		printf("l'intervalle n'est pas défini");                  //Sinon, on indique à l'utilisateur que l'intervalle n'est pas defini         
		return min-1;                                             //Pour montrer qu'il y a une erreur, on retourne un nombre qui n'est pas compris dans l'intervalle (min-1 par exemple)          
	}
	else {                                                             
		entier=lire_entier (f);                                           //on appelle une première fois la fonction "lire_entier" que l'on stocke dans "entier"
		while (((entier < min) || ((max>min) && (entier >= max))) && (feof(f)==0)){      // on verifie si l'entier appartient à l'intervalle, et, si on ne se trouve pas en fin de fichier (pour eviter que la boucle tourne à l'infini)             
			entier=lire_entier (f);                                       // on recommence l'opération tant que l'entier n'est pas dans l'intervalle et tant qu'on est pas en fin de fichier                                 
		}
	}
	if (feof(f)==1){                                                                                //si on arrive en fin de fichier, 
		printf("Il n'y a pas d'entiers compris entre %d et %d dans votre fichier\n",min,max);       //on indique à l'utilisateur que l'on a pas d'entier compris dans l'intervalle.
		return (min-1);                                                                             //pour montrer qu'il y a une erreur on retourne un nombre qui n'est pas compris dans l'intervalle (min-1 par exemple)
	}
	 return entier;                                                      //Sinon, a la fin, on renvoie la valeur de l'entier lu
}


float lire_float ( FILE * f ){           // lit un flottant dans le fichier f de type FILE                            
	float flottant;                                
	fscanf(f,"%f",&flottant);              //fscanf lit le premier flottant dans le fichier f et le met dans la variable "flottant"        
	return flottant;                     //on return le flottant lu      
} 



char * lire_string (FILE * f ) {                       //lit une chaine de caractères dans le fichier f de type FILE (s'arrête à un espace)          
	char *chaine= NULL;                                // on crée un tableau de caractères
	chaine = malloc(sizeof(char) * 50);                // on alloue au tableau la mémoire nécessaire 
	if (chaine == NULL){                                                  // on verifie que l'allocation a bien marché
		printf("L'alloction de la chaine de caractères a échouée\n");     //Sinon on affiche un message d'erreur
		return (NULL);                                                      // On retourne NULL pour montrer qu'il y a eu une erreur 
		}
	else{	
		fscanf(f,"%s",chaine);                                             // on lit dans f la chaine de caractères et on la stocke dans le tableua "chaine" 
	}
	return chaine;                                                       //on renvoie le tableau "chaine" contenant la chaine de caractères lue 
}


//cadeau du prof

/*
  Cadeau, fonction compliquée sur un fichier... On tente de lire un
  mot, si ça échoue, on revient au point de départ et on revoie 1,
  si ça réussit, on reste à la fin du mot et on renvoie 0.
 */
int lire_mot_clef ( FILE * f , const char * mot ) {
  int c ;
  long int
    position_debut,
    position_fin ;
  while ( isspace ( c = getc ( f) ) )
    ;
  ungetc ( c , f ) ;
  position_debut = ftell ( f ) ;
  fscanf ( f , mot ) ;
  position_fin = ftell ( f ) ;
  if ( position_fin != position_debut + strlen ( mot ) ) {
      fseek ( f , position_debut , SEEK_SET ) ;
      return 0 ;
  }
  else return 1 ;
}
