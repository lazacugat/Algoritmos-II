#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

static unsigned int partition(int a[], unsigned int izq, unsigned int der){

    unsigned int pivot = izq;
    unsigned int izq_counter = izq + 1u;
    unsigned int der_counter = der;

    while (der_counter >= izq_counter)
    {
        if (goes_before(a[pivot],a[der_counter]))
        {
            der_counter --;
        }
        else if (!goes_before(a[pivot],a[izq_counter]))
        {
            izq_counter ++;
        }
        else
        {
            swap(a,izq_counter,der_counter);
        }
    }

    swap(a,pivot,der_counter);
    pivot = der_counter;
    return pivot;
}

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    
    if (izq >= der)
    return;
    
        unsigned int pivot = partition(a,izq,der);
        quick_sort_rec(a,izq,(pivot == 0u) ? 0u : pivot - 1u);
        quick_sort_rec(a,pivot + 1u, der);
      
}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0u, (length == 0u) ? 0u : length - 1u);
}



