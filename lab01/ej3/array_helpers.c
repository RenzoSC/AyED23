#include "array_helpers.h"  
#include <assert.h>
#include <stdio.h>

unsigned int array_from_file(int array[],
                             unsigned int max_size,
                             const char *filepath) {
    //your code here!!!
    FILE* archivo = fopen(filepath, "r");
    unsigned int length;
    fscanf(archivo, "%u", &length);
    assert(length <= max_size);
    for (unsigned int i = 0; i < length; i++)
    {
        fscanf(archivo,"%i", &array[i]);
    }
    fclose(archivo);
    return length;
}

void array_dump(int a[], unsigned int length) {
    //your code here!!!
    if(!length == 0u){
        printf("[");
        for (unsigned int i = 0; i < length-1u; i++){
            printf("%i, ", a[i]);
        }
        printf("%i]\n", a[length-1u]);
    }
}