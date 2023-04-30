#include "pair.h"

pair_t pair_new(int x, int y){
    pair_t pair;
    pair.fst = x;
    pair.snd = y;
}

int pair_first(pair_t p){
    return p.fst;
}