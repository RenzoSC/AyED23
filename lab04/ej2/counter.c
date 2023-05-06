#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include "counter.h"

struct _counter {
    unsigned int count;
};

counter counter_init(void) {
    counter c = malloc(sizeof(struct _counter));
    c->count = 0;
    return c;
}

void counter_inc(counter c) {
    c->count +=1;
}

bool counter_is_init(counter c) {
    return c->count ==0;
}

void counter_dec(counter c) {
    assert(!counter_is_init(c));
    c->count -=1;
}

counter counter_copy(counter c) {
    counter c2 = malloc(sizeof(struct _counter));
    c2->count = c->count;
    return c2;
}

void counter_destroy(counter c) {
    free(c);
}
