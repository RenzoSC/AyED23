#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 1000

static void dump(char a[], unsigned int length) {
    printf("\"");
    for (unsigned int j=0u; j < length; j++) {
        printf("%c", a[j]);
    }
    printf("\"");
    printf("\n\n");
}

int main(int argc, char * argv[]) {
    FILE *file;
    unsigned int indexes[MAX_SIZE];
    char letters[MAX_SIZE];
    char sorted[MAX_SIZE];
    unsigned int length=0;
    //  .----------^
    //  :
    // Debe guardarse aqui la cantidad de elementos leidos del archivo
    
    /* -- completar -- */
    unsigned int index;
    
    if (argc != 2)
    {
        printf("EXPECTED UN FILE AS ARGUMENT \nCORRECT USE: ./ejecutable ./file.in\n");
        exit(EXIT_FAILURE);
    }
     
    file = fopen(argv[1], "r");
    while (!feof(file) && length <MAX_SIZE)
    {
        fscanf(file, "%u -> *%c* ", &index, &letters[length]);
        if (index >= MAX_SIZE){
            printf("INDEX MÁXIMO ALCANZADO, INVALID FILE\n");
            exit(EXIT_FAILURE);}
        indexes[length] = index;
        length++;
    }
    fclose(file);
    for (unsigned int i = 0; i < length; i++)
    {
        sorted[indexes[i]] = letters[i];
    }

    dump(sorted, length);

    return EXIT_SUCCESS;
}

