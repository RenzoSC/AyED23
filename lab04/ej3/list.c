#include "list.h"
#include <stdlib.h>
#include <assert.h>
struct Node
{
    list_elem elem;
    struct Node *next;
};

list empty(){
    list q =malloc(sizeof(struct Node));   //PROBLEMS HERE
    return q;
}

list addl(list_elem elem, list lista){
    list p = empty();
    p->elem = elem;
    p->next = lista;                         
    lista = p;
    return lista;
}

list destroy(list l){
    list q;
    q=l;
    while (l!=NULL)
    {
        l = l->next;
        free(q);
        q = l;
    }
    return l;
}


bool is_empty(list l){
    return (l == NULL);                        //PROBLEMS HERE TOO
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

list concat(list l, list l_concat) {
    if (is_empty(l)) {
        return l_concat;
    }
    list p = l;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = l_concat;
    return l;
}


list_elem  index(list l, int n){
    assert(length(l)>n);
    list_elem e;
    list p = l;
    int i=1;
    while (i !=n)
    {
        p = p->next;
        i +=1;
    }
    e=p->elem;
    return e;
}

list take(list l, int n){
    list p,q;
    int i =0;
    p=l;
    while (i<n && p!=NULL)
    {
        p = p->next;
        i +=1;
    }
    if (!(n==0 || p==NULL))
    {
        q = p->next;
        p->next = NULL;
        destroy(q);
    }
    return l;
}

list drop(list l, int n){
    list p;
    int i = 0;
    if (n!=0)
    {
        p=l;
        while (i<n && p!=NULL)
        {
            l = p->next;
            free(p);
            p = l;
            i+=1;
        }
    }
    return l;
}

list copy(list l){
    list l2 = empty();
    list q = l;
    while (q!=NULL)
    {
        l2 = addl(q->elem, l2);
        q = q->next;
    }
    return l2;
}

