# __Projet Réseaux__


### *I - Compilation des fichiers sources*



Dans le terminal, entrer simplement 

    make

Pour compiler et exécuter l'ensemble du projet

    make test
    
*Dans notre cas, cette commande affiche un `segmentation fault` vu que nous n'avons pas traité le module couche.*

-------

### *II - Tester les modules*



   * #### Tester le module utils

Dans le terminal, entrer

    bin/utils_test

*L'utilisateur peut agir sur ce test en modifiant le fichier `utils_test.txt` dans le dossier test.*

*ATTENTION : Si vous souhaitez tester vos propres valeurs, conservez bien le type des valeurs à chaque emplacement.*


   * #### Tester le module matrice

Dans le terminal, entrer

    bin/matrice_test 
    
*L'intervention de l'utilisateur est requise pour tester ce module.*


   * #### Tester le module matrices opération

Dans le terminal, entrer

    bin/matrices_operations_tests

*L'intervention de l'utilisateur est requise pour tester ce module.*


   * #### Tester le module matrices accesseurs

Dans le terminal, entrer

    bin/matrices_accesseurs_test

*L'intervention de l'utilisateur est requise pour tester ce module.*


   * #### Tester le module activation
    
Dans le terminal, entrer

    bin/activation_test
    
*L'intervention de l'utilisateur est requise pour tester ce module.*
    
    
    
------

### *III - Modules non testés*

    
Les modules *`specification`* et *`reseau`* ne sont pas testés. Ils dépendent tous deux du module *`couche`* que nous n'avons pas traité.

Vous pouvez tout de même retrouver les explications de chaque fonction sur le pdf joint, ainsi que des explications supplémentaires dans *`reseau.c`* ainsi que *`specification.c`*.
    
    
    
    
    
    
    
    
    
    
 
