#ifndef _SPECIFICATION_H
#define _SPECIFICATION_H

typedef struct specification_reseau_s * specification_reseau ;

void detruit_specification ( struct specification_reseau_s * spec ) ;

specification_reseau
demande_specification_utilisateur ( void ) ;

struct reseau_s *
creation_reseau ( specification_reseau spec ) ;

#endif

