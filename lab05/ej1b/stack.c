#include <stdlib.h>
#include <assert.h>
#include "stack.h"
 
struct node
{
    stack_elem elem;
    struct node *next;
};
struct _s_stack{
    struct node * stack;
    unsigned int size;
};

/*
invariante:
cada elemento del stack, en el campo stack_len, tendra
la cantidad de elementos que hay desde el mismo hacia el final.
*/
stack stack_empty(){
    stack s = NULL;
    s = malloc(sizeof(struct _s_stack));
    s->stack = NULL;
    s->size = 0;
    return s;
}


stack stack_push(stack s, stack_elem e){
    struct node *aux = NULL;
    aux = malloc(sizeof(struct node));
    aux->elem = e;
    aux->next = s->stack ;
    s->stack = aux ;
    s->size = s->size+1;
    return s;
}


stack stack_pop(stack s){
    assert(!stack_is_empty(s));
     struct node *p = NULL;
    p = s->stack;
    s->stack = (s->stack)->next;
    s->size = s->size-1;
    p->next = NULL;
    free(p);
    p=NULL;
    return s;
}

unsigned int stack_size(stack s){
    return s->size;
}

bool stack_is_empty(stack s){
    return (s->size==0 && s->stack ==NULL);
}

stack_elem stack_top (stack s){
    assert(!stack_is_empty(s));
    stack_elem e = 0;
    e = (s->stack)->elem;
    return e ;
}



stack_elem *stack_to_array(stack s){
    stack_elem * array = NULL;
    if (stack_is_empty(s))
    {
        return NULL;
    }
    array = calloc(stack_size(s),sizeof(stack_elem));
    struct node * p = NULL;
    p = s->stack;
    for (unsigned int i = 0; i < stack_size(s); i++)
    {
        array[(stack_size(s)-1)-i] = p->elem;
        p = p->next;
    }
    return array;
}


stack stack_destroy(stack s){
    struct node* p = NULL;
    p = s->stack;
    while (s->stack != NULL)
    {
        s->stack = s->stack->next;
        p->next = NULL;
        free(p);
        p = s->stack;
    }
    free(s);
    return s;
}

//NO MEAMLEAKS