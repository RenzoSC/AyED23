#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "pstack.h"

struct s_pstack {
    priority_t max_priority;
    unsigned int size;
    struct s_node  * *priorities; 
};

struct s_node {
    pstack_elem elem;
    struct s_node *next;
};

static struct s_node * create_node(pstack_elem e) {
    struct s_node *new_node = malloc(sizeof(struct s_node));
    assert(new_node!=NULL);
    new_node->elem = e;
    new_node->next = NULL;
    return new_node;
}

static struct s_node * destroy_node(struct s_node *node) {
    assert(node != NULL);
    free(node);
    node = NULL;
    assert(node == NULL);
    return node;
}


static bool invrep(pstack s) {
    return s!=NULL;
}

pstack pstack_empty(priority_t max_priority) {
    pstack s=NULL;
    s = malloc(sizeof(struct s_pstack));
    s->max_priority = max_priority;
    s->size = 0;
    s->priorities = NULL;
    assert(invrep(s) && pstack_is_empty(s));
    return s;
}

pstack pstack_push(pstack s, pstack_elem e, priority_t priority) {
    assert(invrep(s));
    if (s->priorities == NULL)
    {
        s->priorities = calloc(s->max_priority+1, sizeof(struct s_node *));
        for (size_t i = 0; i <= s->max_priority; i++)
        {
            s->priorities[i] = NULL;
        }
        
    }
    
    struct s_node *new_node = create_node(e);
    new_node->next = s->priorities[priority];
    s->priorities[priority] = new_node;
    s->size++;
    assert(invrep(s) && !pstack_is_empty(s));
    return s;
}

bool pstack_is_empty(pstack s) {
    assert(invrep(s));
    return s->size == 0;
}

pstack_elem pstack_top(pstack s) {
    assert(invrep(s) && !pstack_is_empty(s));
    priority_t counter = s->max_priority;
    while (s->priorities[counter] == NULL)
    {
        counter--;
    }
    assert(invrep(s));
    return s->priorities[counter]->elem;
}

priority_t pstack_top_priority(pstack s) {
    assert(invrep(s) && !pstack_is_empty(s));
    priority_t prior = s->max_priority;
    while (s->priorities[prior] == NULL)
    {
        prior--;
    }
    assert(invrep(s));
    return prior;
}

size_t pstack_size(pstack s) {
    assert(invrep(s));
    return s->size;
}

pstack pstack_pop(pstack s) {
    assert(invrep(s) && !pstack_is_empty(s));
    priority_t prior = pstack_top_priority(s);
    struct s_node *killme = s->priorities[prior];
    s->priorities[prior] = killme->next;
    killme = destroy_node(killme);
    s->size --;
    assert(invrep(s));
    return s;
}

pstack pstack_destroy(pstack s) {
    assert(invrep(s));
    while (!pstack_is_empty(s))
    {
        s= pstack_pop(s);
    }
    free(s->priorities);
    free(s);
    s = NULL;
    assert(s==NULL);
    return s;
}