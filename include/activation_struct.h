#ifndef ACTIVATION_STRUCT_H
#define ACTIVATION_STRUCT_H

struct fonction_d_activation_s {
  int id ;
  /*
    L'application d'une fonction d'activation est supposée être sur la
    somme des entrées du neurone. Ce n'est pas toujours le cas, comme
    par exemple avec les fonctions SOFTMAX, pas implémentée dans ce
    module.
   */
  float ( * applique ) ( float ) ; // calcule f(x)
  /*
    Lors de la rétro-propagation, on dispose de la valeur x et de la
    valeur f(x) calculée lors de la propagation. Comme les fonctions
    d'activations utilisées sont choisies aussi pour la simplicité du
    calcul en fonction de x et/ou de f(x), on donne ces deux
    paramètres aux fonctions dérivées: le premier argument est x, le
    second f(x).
   */
  float ( * derivee ) ( float , float ) ; 
}  ;

#endif
