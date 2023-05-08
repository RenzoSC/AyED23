#include "list.h"
#include <stdlib.h>
#include <assert.h>
struct Node
{
    list_elem elem;
    struct Node *next;
};

list empty(){
    list q =malloc(sizeof(struct Node));
    return q;
}

list addl(list_elem elem, list lista){
    list p = empty();
    p->elem = elem;
    p->next = lista;
    lista = p;
    return lista;
}

bool is_empty(list l){
    return (l == NULL);
}

list_elem head(list l){
    assert(!is_empty(l));
    return l->elem;
}

list tail(list l){
    assert(!is_empty(l));
    list p = l;
    l = l->next;
    free(p);
    return l;
}

list addr(list_elem elem, list l){
    list p, q;
    q = empty();
    q->elem = elem;
    q->next = NULL;
    if (!is_empty(l))
    {
        p = l;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = q;
    }else{
        l= q;
    }
    return l;
}

int length(list l){
    list p;
    int n=0;
    p = l;
    while (p!=NULL)
    {
        n+=1;
        p = p->next;
    }
    return n;
}

