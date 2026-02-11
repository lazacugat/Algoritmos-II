#include <stdio.h>
#include "pair.h"
#include <stdlib.h>

struct s_pair_t {
    elem fst;
    elem snd;
};

pair_t pair_new(elem x, elem y){
    pair_t p = malloc(sizeof(pair_t));
    p->fst = x;
    p->snd = y;
    return p;
}

elem pair_first(pair_t p){
    elem first = p->fst;
    return first;
}

elem pair_second(pair_t p){
    elem second = p->snd;
    return second;
}

pair_t pair_swapped(pair_t p){
    pair_t q;
    q = pair_new(p->snd,p->fst);
    return q;
}

pair_t pair_destroy(pair_t p){
    free(p);
    return p;
}