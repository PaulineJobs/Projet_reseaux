SHELL:=/bin/bash
MODULES_APPRENTISSAGE:= lib/specification.o lib/apprentissage.o lib/reseau.o lib/couches_entree.o lib/couches_sortie.o  lib/couches_activation.o  lib/couches_matrice.o lib/activation.o lib/matrices_accesseurs.o lib/matrices_operations.o lib/matrices.o lib/utils.o 
MODULES_EVALUATION:=lib/specification.o lib/lire_db.o lib/evaluation.o lib/reseau.o lib/couches_entree.o lib/couches_sortie.o  lib/couches_activation.o lib/couches_matrice.o  lib/activation.o lib/matrices_accesseurs.o lib/matrices_operations.o lib/matrices.o lib/utils.o 
MAIN:=bin/apprentissage bin/evaluation
LIBS:=-lm 
INCLUDE_PATH:= include
LIBRARY_PATH:= lib
DEBUG:= -g3 -Wno-unused-value
# DEBUG:= -DNDEBUG 
CFLAGS:=-Wall  -Werror $(DEBUG)  -I $(INCLUDE_PATH) -L$(LIBRARY_PATH) 

all: $(MAIN)

bin/apprentissage: src/main_apprentissage.c $(MODULES_APPRENTISSAGE)
	gcc $(CFLAGS) src/main_apprentissage.c -o bin/apprentissage  $(MODULES_APPRENTISSAGE) $(LIBS)

bin/evaluation: src/main_evaluation.c $(MODULES_EVALUATION)
	gcc $(CFLAGS) src/main_evaluation.c -o bin/evaluation  $(MODULES_EVALUATION) $(LIBS)

lib/%.o: src/%.c 
	gcc $(CFLAGS) -c $< -o $@ 



clean:
	find bin -maxdepth 1 -type f -exec \rm {} \;
	find lib -maxdepth 1 -type f -exec \rm {} \;
	find . -name '*~' -exec \rm {} \;
	if [[ -e "pmc.tgz" ]] ; then \rm mlp.tgz ; fi

pkg: clean
	cd .. ; tar czvf pmc.tgz PMC ; mv pmc.tgz PMC/

