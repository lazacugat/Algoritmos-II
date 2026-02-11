#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static void insert(int a[], unsigned int i) {
    unsigned int counter = i;
    while (counter > 0 && !goes_before(a[counter-1u],a[counter]))
    {
        swap(a,counter-1u,counter);
        counter--;
    }
}

void insertion_sort(int a[], unsigned int length) {
    for (unsigned int i = 1u; i < length; ++i) {
        assert(array_is_sorted(a,i-1u));
        insert(a,i);
    }
}

