#include "pair.h"
#include <stdlib.h>
#include <assert.h>

struct s_pair_t {
    elem fst;
    elem snd;
};

pair_t pair_new(elem x, elem y){
    pair_t p = malloc(sizeof(struct s_pair_t));
    p->fst = x;
    p->snd = y;
    return p;
}

elem pair_first(pair_t p){
    assert(p!= NULL);
    return p->fst;
}

elem pair_second(pair_t p){
    assert(p!= NULL);
    return p->snd;
}

pair_t pair_swapped(pair_t p){
    assert(p!= NULL);
    pair_t q = pair_new(p->snd, p->fst);
    return q;
}

pair_t pair_destroy(pair_t p){
    free(p);
    return NULL;
}