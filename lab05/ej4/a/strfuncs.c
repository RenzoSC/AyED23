#include "strfuncs.h"
#include <stdio.h>

size_t string_length(const char *str){
    size_t i =0;
    while (str[i] != '\0')
    {
        i+=1;
    }
    return i;
}

char* string_filter(const char *str, char c){
    size_t len_or = string_length(str);
    size_t new_len= 0;
    for (size_t i = 0; i < len_or; i++)               //Cuento la cantidad de caracteres que son != c
    {
        if (str[i] != c)
        {
            new_len +=1;
        }
    }
    /* reservo la memoria necesaria, hago new_len+1 para
    contemplar el ultimo caracter '\0' */                                                    
    char * new_str;
    new_str = (char *)malloc(sizeof(char) * (new_len+1));
    size_t j = 0;
    for (size_t i = 0; i < len_or; i++)
    {
        if (str[i] != c)
        {
            new_str[j++] = str[i];
        }
    }
    new_str[new_len] = '\0';                //en la ultima posicion guardo '\0'   
    return new_str;
}