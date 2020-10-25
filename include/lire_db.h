#ifndef LIRE_DB_H
#define LIRE_DB_H


struct log_s 
{
	int nb_entrees ;
	int nb_sorties ;
	int nb_records ;
	float * data ;
}
	;

struct log_s *
lire_fichier ( const char * nom ) ;

#endif
