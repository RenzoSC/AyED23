#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static void insert(int a[], unsigned int i) {
    /* needs implementation */
    unsigned int j = i;
    while (j >0 && goes_before(a[j], a[j-1]))
    {
        swap(a, j-1, j);
        j--;
    }   
    
}

void insertion_sort(int a[], unsigned int length) {
    for (unsigned int i = 1u; i < length; ++i) {
        assert(array_is_sorted(a, i-1));
        /* needs implementation */
        insert(a, i);
    }
    assert(array_is_sorted(a, length));
}
