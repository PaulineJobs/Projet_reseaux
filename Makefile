SHELL:=/bin/bash

MODULES_APPRENTISSAGE:= lib/specification.o lib/apprentissage.o lib/reseau.o lib/couches_entree.o lib/couches_sortie.o  lib/couches_activation.o  lib/couches_matrice.o lib/activation.o lib/matrices_accesseurs.o lib/matrices_operations.o lib/matrices.o lib/utils.o 

MODULES_EVALUATION:=lib/specification.o lib/lire_db.o lib/evaluation.o lib/reseau.o lib/couches_entree.o lib/couches_sortie.o  lib/couches_activation.o lib/couches_matrice.o  lib/activation.o lib/matrices_accesseurs.o lib/matrices_operations.o lib/matrices.o lib/utils.o 

MAIN:=bin/apprentissage bin/evaluation

LIBS:=-lm 
INCLUDE_PATH:= include
LIBRARY_PATH:= lib
DEBUG:= -g3 -Wno-unused-value
# DEBUG:= -DNDEBUG 
#CFLAGS:=-Wall  -Werror $(DEBUG)  -I $(INCLUDE_PATH) -L$(LIBRARY_PATH) 
CFLAGS:=-Wall $(DEBUG)  -I $(INCLUDE_PATH) -L$(LIBRARY_PATH)



all: $(MAIN) matrices_operations_tests matrice_test utils_test


matrices_operations_tests: bin/matrices_operations_tests

matrice_test: bin/matrice_test 

utils_test: bin/utils_test


bin/apprentissage: src/main_apprentissage.c $(MODULES_APPRENTISSAGE)
	gcc $(CFLAGS) src/main_apprentissage.c -o bin/apprentissage  $(MODULES_APPRENTISSAGE) $(LIBS)

bin/evaluation: src/main_evaluation.c $(MODULES_EVALUATION)
	gcc $(CFLAGS) src/main_evaluation.c -o bin/evaluation  $(MODULES_EVALUATION) $(LIBS)

# Pour le module matrices_operations.c : 
bin/matrices_operations_tests: tests/matrices_operations_tests.c lib/matrices_operations.o lib/matrices.o
	gcc $(CFLAGS) tests/matrices_operations_tests.c lib/matrices_operations.o lib/matrices.o -o bin/matrices_operations_tests $(LIBS)


# Pour le module matrices.c : 
bin/matrice_test: tests/matricestest.c  lib/matrices.o 
	gcc $(CFLAGS) tests/matricestest.c lib/matrices.o -o bin/matricestest $(LIBS)


# Programme de test du module utils
bin/utils_test: tests/utils_test.c  lib/utils.o
	gcc $(CFLAGS) tests/utils_test.c lib/utils.o -o bin/utils_test $(LIBS)


lib/%.o: src/%.c 
	gcc $(CFLAGS) -c $< -o $@ 



clean:
	find bin -maxdepth 1 -type f -exec \rm {} \;
	find lib -maxdepth 1 -type f -exec \rm {} \;
	find . -name '*~' -exec \rm {} \;
	if [[ -e "pmc.tgz" ]] ; then \rm mlp.tgz ; fi

pkg: clean
	cd .. ; tar czvf pmc.tgz PMC ; mv pmc.tgz PMC/

