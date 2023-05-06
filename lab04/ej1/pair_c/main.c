#include <stdlib.h>  /* EXIT_SUCCESS... */
#include <stdio.h>   /* printf()...     */
#include "pair.h"    /* TAD Par         */

static
void show_pair(pair_t p) {
    printf("(%d, %d)\n", pair_first(p), pair_second(p));
}

int main(void) {
    pair_t p, q;
    // Nuevo par p
    p = pair_new(3, 4);
    // Se muestra el par por pantalla
    printf("p = ");
    show_pair(p);
    // Nuevo para q con elementos de p intercambiados
    q = pair_swapped(p);
    // Se muestra q
    printf("q = ");
    show_pair(q);
    // Se destruyen p y q
    p = pair_destroy(p);
    q = pair_destroy(q);
    return EXIT_SUCCESS;
}

/*
ESTA IMPLEMENTACION SI LOGRA ENCAPSULAMIENTO
En este caso, se ha definido la estructura "pair" dentro del archivo "pair.c" y 
no se ha expuesto su definición en el archivo de cabecera "pair.h". 
En su lugar, se ha definido un puntero a la estructura (s_pair_t) que se puede utilizar 
para declarar variables y pasarlas como argumentos a las funciones públicas.
*/
