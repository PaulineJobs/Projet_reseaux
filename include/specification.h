#ifndef _SPECIFICATION_H
#define _SPECIFICATION_H

struct specification_reseau_s *
demande_specification_utilisateur ( void ) ;

void detruit_specification ( struct specification_reseau_s * spec ) ;

struct reseau_s *
creation_reseau ( struct specification_reseau_s * spec ) ;

#endif

