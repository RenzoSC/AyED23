#ifndef _LIST_H
#define _LIST_H
#include <stdbool.h>
typedef int list_elem;
typedef struct Node * list;

/*CONSTRUCTORES: */

list empty();

list addl(list_elem elem, list lista);
/*Agrega un elemento a la izquierda de la lista*/

/*OPERACIONES: */

bool is_empty(list l);

list_elem head(list l);

list tail(list l);

list addr(list_elem elem, list l);

int length(list l);

list concat(list l, list l_concat);

list_elem  index(list l, int n);

list take(list l, int n);

list drop(list l, int n);

list copy(list l);

/*DESTROY: */

list destroy(list l);
#endif