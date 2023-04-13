#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int *y) {
    int *p = NULL;
    p= y;
    if (x>=0)
    {
        *p= x;   
    }else{
        *p= -x;
    }
    
}

int main(void) {
    int a, res;
    res=0;
    a=-98;
    absolute(a,&res);
    printf("%i\n", res);
    return EXIT_SUCCESS;
}
/*
el parametro int *y es de tipo in/out

C tiene parametros de tipo in/out
*/
