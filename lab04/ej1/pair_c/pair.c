#include <stdio.h>
#include "pair.h"
#include <stdlib.h>

struct s_pair_t {
    int fst;
    int snd;
};

pair_t pair_new(int x, int y){
    pair_t p = malloc(sizeof(pair_t));
    p->fst = x;
    p->snd = y;
    return p;
}

int pair_first(pair_t p){
    int first = p->fst;
    return first;
}

int pair_second(pair_t p){
    int second = p->snd;
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