/*
  @file sort.c
  @brief sort functions implementation
*/

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "helpers.h"
#include "sort.h"
#include "player.h"

bool goes_before(player_t x, player_t y){
    if (x.rank > y.rank)
    {
        return false;
    }
    return true;
}

bool array_is_sorted(player_t atp[], unsigned int length) {
    unsigned int i = 1u;
    while (i < length && goes_before(atp[i - 1u], atp[i])) {
        i++;
    }
    return (i == length);
}

void swap(player_t a[], unsigned int i, unsigned int j) {
    player_t aux;
    aux=a[i];
    a[i]=a[j];
    a[j]=aux;
}

static unsigned int partition(player_t a[], unsigned int izq, unsigned int der) {
    
    unsigned int pivot = izq;
    unsigned int izq_counter = izq + 1u;
    unsigned int der_counter = der;

    while (der_counter >= izq_counter){

        if (goes_before(a[pivot],a[der_counter])){
            der_counter --;
        }

        else if (!goes_before(a[pivot],a[izq_counter])){
            izq_counter ++;
        }

        else{
            swap(a,izq_counter,der_counter);
        }
    }
    swap(a,pivot,der_counter);
    pivot = der_counter;
    return pivot;
}

static void quick_sort_rec(player_t a[], unsigned int izq, unsigned int der) {
    
    if (izq < der){
        unsigned int pivot = partition(a,izq,der);
        quick_sort_rec(a,izq,(pivot == 0u) ? 0u : pivot - 1u);
        quick_sort_rec(a,pivot + 1u, der);
    }
}

void quicksort(player_t a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}
