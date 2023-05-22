#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "abb.h"

struct _s_abb {
    abb_elem elem;
    struct _s_abb *left;
    struct _s_abb *right;
};

static bool elem_eq(abb_elem a, abb_elem b) {
    return a == b;
}

static bool elem_less(abb_elem a, abb_elem b) {
    return a < b;
}
static bool is_abb(abb tree){
    if(tree == NULL){
        return true;
    }else if(tree->right == NULL && tree->left==NULL)
    {
        return true;
    }else if (tree->right == NULL && tree->left!= NULL)
    {
        return is_abb(tree->left);
    }else if (tree->right != NULL && tree->left== NULL)
    {
        return is_abb(tree->right);
    }else
    {
        bool is_more = !elem_less(tree->right->elem,tree->elem);
        bool is_less = elem_less(tree->left->elem,tree->elem);
        bool der = is_abb(tree->right);
        bool izq = is_abb(tree->left);
        return(is_less && is_more && der && izq);
    }
}

static bool invrep(abb tree) {
    return is_abb(tree);
}

abb abb_empty(void) {
    abb tree = NULL;

    assert(invrep(tree) && abb_is_empty(tree));
    return tree;
}

abb abb_add(abb tree, abb_elem e) {
    assert(invrep(tree));
    abb nodo = (abb)malloc(sizeof(struct _s_abb));
    nodo->elem = e;
    nodo->left= NULL;
    nodo->right=NULL;
    if (abb_is_empty(tree))
    {
        tree = nodo;
    }else{
        abb pointer = tree;
        bool nonstop = true;
        while (nonstop)
        {
            if (elem_less(pointer->elem, e) && pointer->right !=NULL)
            {
                pointer = pointer->right;
            }else if (elem_less(e, pointer->elem) &&pointer->left !=NULL)
            {
                pointer = pointer->left;
            }else{
                nonstop = false;          //llego hasta la hoja
            }
        }

        if (elem_less(e, pointer->elem) && !elem_eq(e, pointer->elem))          //me fijo donde debo colocar el nuevo nodo y que no se repita
        {
            pointer->left = nodo;
        }else if (elem_less(pointer->elem, e) && !elem_eq(e, pointer->elem))
        {
            pointer->right = nodo;
        }
    }
    assert(invrep(tree) && abb_exists(tree, e));
    return tree;
}

bool abb_is_empty(abb tree) {
    assert(invrep(tree));
    return tree == NULL;
}

bool abb_exists(abb tree, abb_elem e) {
    bool exists=false;
    assert(invrep(tree));
    if (tree == NULL)
    {
        return false;
    }else if (elem_less(e, tree->elem))
    {
        exists = abb_exists(tree->left, e);
    }else if (elem_less(tree->elem, e))
    {
        exists = abb_exists(tree->right, e);
    }else if (elem_eq(e, tree->elem))
    {
        return true;
    }
    return exists;
}

unsigned int abb_length(abb tree) {
    unsigned int length=0;
    assert(invrep(tree));
    if (tree != NULL)
    {
        length = 1+ abb_length(tree->left);
        length += abb_length(tree->right);
    }
    
    assert(invrep(tree) && (abb_is_empty(tree) || length > 0));
    return length;
}

abb abb_remove(abb tree, abb_elem e) {
    assert(invrep(tree));
    
    if (abb_exists(tree, e))
    {
        abb taux = tree;
        abb parent = NULL;
        while (taux->elem != e)     //Este bucle me asegura terminar apuntando al elem a eliminar
        {
            parent = taux;
            taux = elem_less(e, taux->elem) ? taux->left: taux->right;   
        }
        
        //Dividimos en los 4 casos posibles
        if (taux->left == NULL && taux->right == NULL)
        {
            if (abb_root(tree) == taux->elem)   //si el elemento q quiero del es el root entonces no habrá parent
            {
                tree = abb_empty();
            }else if (elem_less(taux->elem, parent->elem)) //caso contrario me fijo si taux esta a la izq o der
            {
                parent->left = abb_empty();
            }else{
                parent->right = abb_empty();
            }
            free(taux);

        }else if (taux->left != NULL && taux->right == NULL)
        {
            if (abb_root(tree) == taux->elem)   //si el elemento q quiero del es el root entonces no habrá parent
            {
                tree = taux->left;
            }else if (elem_less(taux->elem, parent->elem)) //caso contrario me fijo si taux esta a la izq o der
            {
                parent->left = taux->left;
            }else{
                parent->right = taux->left;
            }
            free(taux);
        }else if(taux->left == NULL && taux->right != NULL){
            if (abb_root(tree) == taux->elem)   //si el elemento q quiero del es el root entonces no habrá parent
            {
                tree = taux->right;
            }else if (elem_less(taux->elem, parent->elem)) //caso contrario me fijo si taux esta a la izq o der
            {
                parent->left = taux->right;
            }else{
                parent->right = taux->right;
            }
            free(taux);
        }else{     //Este es el caso en el que taux->left!=NULL && taux->right !=NULL 
            parent = taux;
            abb reemplazo = taux->right;
            while (reemplazo->left != NULL)
            {
                parent = reemplazo;
                reemplazo = reemplazo->left;
            }                               //en este bucle me aseguro q reemp apunte al nodo más chico del arbol der
            taux->elem = reemplazo->elem;
            if (elem_less(reemplazo->elem, parent->elem))
            {
                parent->left = abb_empty();
            }else{
                parent->right = abb_empty();
            }
            
            free(reemplazo);
        }
    }
    assert(invrep(tree) && !abb_exists(tree, e));
    return tree;
}


abb_elem abb_root(abb tree) {
    abb_elem root;
    assert(invrep(tree) && !abb_is_empty(tree));
    
    root = tree->elem;

    assert(abb_exists(tree, root));
    return root;
}

abb_elem abb_max(abb tree) {
    abb_elem max_e;
    assert(invrep(tree) && !abb_is_empty(tree));
    
    abb pointer = tree;
    while (pointer->right != NULL)
    {
        pointer = pointer->right;
    }
    max_e = pointer->elem;

    assert(invrep(tree) && abb_exists(tree, max_e));
    return max_e;
}

abb_elem abb_min(abb tree) {
    abb_elem min_e;
    assert(invrep(tree) && !abb_is_empty(tree));
    
    abb pointer = tree;
    while (pointer->left != NULL)
    {
        pointer = pointer->left;
    }
    min_e = pointer->elem;

    assert(invrep(tree) && abb_exists(tree, min_e));
    return min_e;
}

void abb_dump(abb tree) {
    assert(invrep(tree));
    if (tree != NULL) {
        printf("%d ", tree->elem);    //para el ejc lo unico q hice fue cambiar la posicion del printf
        abb_dump(tree->left);
        //printf("%d ", tree->elem);
        abb_dump(tree->right);
    }
}

abb abb_destroy(abb tree) {
    assert(invrep(tree));
    if (tree == NULL) {
        return NULL;
    }
    tree->left=abb_destroy(tree->left);
    tree->right= abb_destroy(tree->right);
    free(tree);
    tree=NULL;
    assert(tree == NULL);
    return tree;
}

