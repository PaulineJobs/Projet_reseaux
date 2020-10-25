# Projet_reseaux


A faire à chaque session de travail:
1)Au début,Pour la première fois, faire un git clone de ce projet
Pour les prochaines fois, faire un git pull pour récuperer les modifications de ton partenaire (sauf la première fois puisque tu as fait un git clone)
2) A la fin, faire un git push pour que ton collègue puisse récuperer tes modifications la prochaine fois

Conseils :
-Ne commit et ne push que quelque chose qui compile (sinon ton camarade va récuperer un truc qui ne copile pas bien et va avoir des difficultés à régler le soucis)
-Bien commenter le code dans les .c , .h  etc (pour s'y retrouver)
-Pour les commit:
  Bien commenter les commit(pour s'y retrouver)
-Ne pas hesiter à séparer les commit pour mieux expliquer leur modification
(ex : 4 fichiers modifiés, 2 modifiés pour une raison A et deux autres pour une raison B.
Mieux vaut commiter ensemble les 2 de la raison A avec un message expliquant la modif A puis commiter les 2 autres avec un message expliquant la raiosn B; plutot                            que de commiter les 4 ensemble avec une longue expliaction)
      (Cela permet de mieux s'y retrouver dans l'historique (avec un git log))

 Ce que j'ai modifié:
- J'ai copié les fichiers src/squelette/* puis mis dans src 
 -J'ai modifié le makefile en retirant l'option "Werror" (transforme un warning en error ce qui ici empeche la compilation)
 -J'ai rajouté le corps de la fonction "evaluation reseau" (sinon cela ne compilait pas)

Pour être au même niveau que moi:
1) Faire un git clone de ce projet.
2) Creer un repertoir lib au même niveau que src,bin etc...
3)Tapper la commande "make" et verifier que tout copile correctement 
(verifier que tous les fichier .o se soient crées dans lib et que 2 fichiers supplementaires se soient crées dans bin)


      
      

 
