#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int y) {
    /*
    int *p = NULL;
    p= &y;
    */
    if (x>=0)
    {
        y=x;
        /*
        *p= x
        */
    }else{
        y=-x;
        /*
        *p= -x
        */
    }
    
}

int main(void) {
    int a, res;
    res=0;
    a=-98;
    absolute(a,res);
    printf("%i\n", res);
    return EXIT_SUCCESS;
}

/*
No devuelve el resultado esperado que sería en este caso 98, pero es porque estamos cambiando el valor que tiene la variable dentro
de la "vida" que tiene dentro de la funcion, no altera su valor original que está guardado en otra posición de memoria,
incluso si lo hiciera utilizando pointers dentro de absolute me devolvería el mismo valor
*/
