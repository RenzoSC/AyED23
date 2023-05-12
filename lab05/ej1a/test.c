#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"
 
 int main(){
    stack s = stack_empty();

    s = stack_push(s, 32);
    s = stack_pop(s);
    s = stack_push(s, 89);


    stack_elem el = stack_top(s);

    printf("Elemento tope: %u \n", el);

    stack_is_empty(s) ? printf("True\n") : printf("False\n");

    printf("Eliminamos el ultimo elemento\n");
    s = stack_pop(s);
    unsigned int tam = stack_size(s);
    printf("tam: %u\n", tam);
    stack_is_empty(s) ? printf("True\n") : printf("False\n");
    
    stack_elem *arr = NULL;
    arr = stack_to_array(s);
    if (arr == NULL)
    {
        printf("ARRAY NULL\n");
    }
    printf("Le agregamos elementos nuevamente\n");
    s = stack_push(s, 89);
    s = stack_push(s, 22);
    s = stack_push(s, 33);
    tam = stack_size(s);
    printf("tam: %u\n", tam);
    arr = stack_to_array(s);
    for (unsigned int i = 0; i < tam; i++) {
        printf("%u\n", arr[i]);
    }

    free(arr);

    s = stack_destroy(s);

    return 0;
 }