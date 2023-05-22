/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "abb.h" /* TAD abb */


void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n",
           program_name);
}

char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;

    if (argc < 2) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return (result);
}

abb abb_from_file(const char *filepath) {
    FILE *file = NULL;
    abb read_tree;

    read_tree = abb_empty();
    file = fopen(filepath, "r");
    if (file == NULL) {
        fprintf(stderr, "File does not exist.\n");
        exit(EXIT_FAILURE);
    }
    unsigned int i = 0u;
    unsigned int size = 0u;
    int res = 0;
    res = fscanf(file, " %u ", &size);
    if (res != 1) {
        fprintf(stderr, "Invalid format.\n");
        exit(EXIT_FAILURE);
    }
    while (i < size) {
        abb_elem elem;
        res = fscanf(file," %d ", &(elem));
        if (res != 1) {
            fprintf(stderr, "Invalid array.\n");
            exit(EXIT_FAILURE);
        }
        read_tree = abb_add(read_tree, elem);

       ++i;
    }
    fclose(file);
    return read_tree;
}

int main(int argc, char *argv[]) {
    char *filepath = NULL;

    /* parse the filepath given in command line arguments */
    filepath = parse_filepath(argc, argv);

    /* parse the file to obtain an abb with the elements */
    abb tree = abb_from_file(filepath);

    /*dumping the tree*/
    abb_dump(tree);
    if (!abb_is_empty(tree)) {
        printf("\n");
        printf("raiz: %d\n minimo: %d\n maximo: %d\n", abb_root(tree),
                                                       abb_min(tree),
                                                       abb_max(tree));
    } else {
        printf("\nÁrbol vacío\n");
    }

    tree = abb_destroy(tree);
    /*
     * Modificar e implementar con un ciclo una interfaz que permita al usuario
     * realizar una de las siguientes operaciones en cada iteración:
     *
     * 1 ........ Mostrar árbol por pantalla
     * 2 ........ Agregar un elemento
     * 3 ........ Eliminar un elemento
     * 4 ........ Chequear existencia de elemento
     * 5 ........ Mostrar longitud del árbol
     * 6 ........ Mostrar raiz, máximo y mínimo del árbol
     * 7 ........ Salir
     *
     * Se debe solicitar un número de entrada para realizar una de las acciones.
     *
     * Para las opciones 2, 3 y 4 se le deberá pedir al usuario que ingrese el
     * elemento a agregar, eliminar o chequear respectivamente.
     *
     * Al salir debe liberarse toda la memoria utilizada.
     *
     */

    abb user_tree= abb_empty();
    bool flag= true;
    int entry;
    while (flag)
    {  
        printf("\n\nPor favor, ingrese cual de las siguientes operaciones desea realizar (numero):\n\n");
        printf("1 ........ Mostrar árbol por pantalla\n2 ........ Agregar un elemento\n3 ........ Eliminar un elemento\n4 ........ Chequear existencia de elemento\n5 ........ Mostrar longitud del árbol\n6 ........ Mostrar raiz, máximo y mínimo del árbol\n7 ........ Salir\n\n");
        scanf("%d", &entry);
        abb_elem num_toadd;
        abb_elem num_tocheck;
        abb_elem num_todel;
        switch (entry) {
            case 1:
                printf("\nElegiste la opción de mostrar el arbol por pantalla\n");
                if (abb_is_empty(user_tree))
                {
                    printf("\nArbol vacio\n");
                }else{
                    abb_dump(user_tree);
                }
                
                break;
            case 2:
                
                printf("\nElegiste la opción de agregar un elemento");
                printf("\nIngresa el numero para añadir:");
                scanf("%d", &num_toadd);
                user_tree = abb_add(user_tree, num_toadd);
                break;
            case 3:
                
                printf("\nElegiste la opción de eliminar un elemento");
                printf("\nIngresa el numero para eliminar:");
                scanf("%d", &num_todel);
                if (abb_exists(user_tree, num_todel))
                {
                    user_tree = abb_remove(user_tree, num_todel);
                    printf("\nElemento eliminado con exito");
                }else{
                    printf("\nEl elemento dado no existe dentro del arbol");
                }
                break;
            case 4:
                
                printf("\nElegiste la opción de chequear existencia de elemento\n");
                printf("\nIngresa el numero para chequear:");
                scanf("%d", &num_tocheck);
                if (abb_exists(user_tree, num_todel))
                {
                    printf("\nEl elemento dado existe dentro del arbol");
                }else{
                    printf("\nEl elemento dado no existe dentro del arbol");
                }
                break;
            case 5:
                printf("\nElegiste la opción de mostrar la longitud del árboln");
                printf("\nLa longitud del arbol es: %u\n", abb_length(user_tree));
                break;
            case 6:
                printf("\nElegiste la opción de mostrar raiz, máximo y mínimo del árbol\n");
                if (!abb_is_empty(user_tree)) {
                    printf("\nraiz: %d\n minimo: %d\n maximo: %d\n", abb_root(user_tree),
                                                                abb_min(user_tree),
                                                                abb_max(user_tree));
                } else {
                    printf("\nÁrbol vacío\n");
                }
                break;
            case 7:
                printf("\nElegiste la opción para salir\n");
                user_tree = abb_destroy(user_tree);
                return (EXIT_SUCCESS);
                break;
            default:
                printf("\nOpción no válida\n");
            }
    }
    return (EXIT_SUCCESS);
}


//NO MEM-LEAKS CHECKED WITH VALGRIND