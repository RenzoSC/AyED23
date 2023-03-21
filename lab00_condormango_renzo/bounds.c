#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 4

struct bound_data {
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    int where;    //Cambio de unsigned int --> int
};

struct bound_data check_bound(int value, int arr[], unsigned int length) {
    struct bound_data res;
    //inicializo un res con valores por default

    res.is_lowerbound = true;
    res.is_upperbound = true;
    res.exists = false;
    res.where = -1;
    
    for (int i = 0; i < length; i++)
    {
        //aplico condiciones para checkear si existe, si el valor es el mayor o el menor y en base a eso cambio res
        if (value == arr[i])
        {
            res.exists = true;
            res.where = i;
        }
        if (value > arr[i])
        {
            res.is_lowerbound = false;
        }
        if (value < arr[i])
        {
            res.is_upperbound = false;
        }
    }
    return res;
}

int main(void) {
    int a[ARRAY_SIZE] = {0, -1, 9, 4};
    int value=9;
    printf("Ingresa el valor a checkear:\n");
    scanf("%i", &value);
    printf("Ahora ingresa los valores que tendrá el array de %i elementos\n", ARRAY_SIZE);
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        printf("Valor del array en la posición %i: ",i);
        scanf("%i", &a[i]);
    }
    struct bound_data result = check_bound(value, a, ARRAY_SIZE);

    if (result.exists && result.is_upperbound)
    {
        printf("El valor dado es máximo\n");
        printf("Se encuentra en la posición %i del arreglo\n", result.where);
    }else if (result.is_upperbound)
    {
        printf("El valor dado es cota superior\n");
    }else if (result.exists && result.is_lowerbound)
    {
        printf("El valor dado es mínimo\n");
        printf("Se encuentra en la posición %i del arreglo\n", result.where);
    }else if (result.is_lowerbound)
    {
        printf("El valor dado es cota inferior\n");
    }
    return EXIT_SUCCESS;
}

