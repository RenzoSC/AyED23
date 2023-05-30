#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "pqueue.h"

struct s_pqueue {
    unsigned int size;
    struct s_node * node;
};

struct s_node {
    struct s_node *next;
    unsigned int priority;
    pqueue_elem elem;
};

static struct s_node * create_node(pqueue_elem e, unsigned int priority) {
    struct s_node *new_node = NULL;

    new_node = malloc(sizeof(struct s_node));
    new_node->next = NULL;
    new_node->priority = priority;
    new_node->elem = e;
    assert(new_node!=NULL);

    return new_node;
}

static struct s_node * destroy_node(struct s_node *node) {
    assert(node != NULL);
    free(node);
    node = NULL;
    assert(node == NULL);
    return node;
}

bool pqueue_ord(pqueue q){
    bool is_ord = true;
    struct s_node *pointer = q->node;
    while (is_ord && pointer!=NULL && pointer->next!= NULL)
    {
        is_ord &= pointer->priority <= (pointer->next)->priority; 
        pointer = pointer->next;
    }
    return is_ord;
}

static bool invrep(pqueue q) {
    bool is_valid = q!=NULL ? pqueue_ord(q) : true;
    return is_valid;
}

pqueue pqueue_empty(void) {
    pqueue q=NULL;
    q = malloc(sizeof(struct s_pqueue));
    q->node = NULL;
    q->size = 0;
    assert(invrep(q) && pqueue_is_empty(q));
    return q;
}

pqueue pqueue_enqueue(pqueue q, pqueue_elem e, unsigned int priority) {
    assert(invrep(q));
    struct s_node *new_node = create_node(e, priority);
    q->size +=1;
    struct s_node *pointer_node = q->node;

    struct s_node *parent = NULL;
    bool flag = true;
    if (pointer_node == NULL)
    {
        q->node = new_node;
    }else{
        while (flag && priority>= pointer_node->priority)
        {
            parent = pointer_node;
            pointer_node = pointer_node->next;
            if (pointer_node == NULL)
            {
                flag = false;
            }
        }
        new_node->next = pointer_node;
        if (parent !=NULL)
        {
            //pointer_node = new_node;
            parent->next = new_node;
        }else{
            q->node = new_node;
        }
        
    }
    
    assert(invrep(q));
    return q;
}

bool pqueue_is_empty(pqueue q) {
    assert(invrep(q));
    return q->size == 0;
}

pqueue_elem pqueue_peek(pqueue q) {
    assert(invrep(q) && !pqueue_is_empty(q));
    return (q->node)->elem;
}

unsigned int pqueue_peek_priority(pqueue q) {
    assert(invrep(q) && !pqueue_is_empty(q));
    return (q->node)->priority;
}

unsigned int pqueue_size(pqueue q) {
    assert(invrep(q));
    return q->size;
}

pqueue pqueue_dequeue(pqueue q) {
    assert(invrep(q) && !pqueue_is_empty(q));
    struct s_node *killme = q->node;
    q->node = killme->next;
    killme =  destroy_node(killme);
    q->size -=1;
    assert(invrep(q));
    return q;
}

pqueue pqueue_destroy(pqueue q) {
    assert(invrep(q));
    struct s_node *killme = q->node;
    while (q->node != NULL)
    {
        q->node = killme->next;
        killme = destroy_node(killme);
        killme = q->node;
    }
    free(q);
    q = NULL;
    assert(q == NULL);
    return q;
}
