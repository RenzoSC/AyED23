#include "array_helpers.h"
#include <stdbool.h>
#include <assert.h>
#include <stdio.h>
unsigned int array_from_file(int array[],
           unsigned int max_size,
           const char *filepath) {
    //your code here!!!

    FILE * miArchivo = fopen(filepath, "r");
    unsigned int length;
    fscanf(miArchivo, "%ui", &length);
    assert(length <= max_size);
    for (unsigned int i = 0; i < length; i++)
    {
        fscanf(miArchivo, " %i",&array[i]);
    }
    fclose(miArchivo);
    return length;
}

void array_dump(int a[], unsigned int length) {
    //your code here!!!!!
    printf("[");
    for (unsigned int i = 0; i < length; i++){
        if (i == length-1)
        {
            printf("%i", a[i]);
        }else{
            printf("%i, ", a[i]);
        }
    }
    printf("]\n");
}

bool array_is_sorted(int a[], unsigned int length){
    for (unsigned int i = 0; i < length-1; i++)
    {
        if (a[i]>a[i+1])
        {
            return false;
        }
    }
    return true;
}