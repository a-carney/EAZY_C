#include "gc.h"
#include <assert.h>
#include <stdio.h>

void test_gc_alloc() {
    int* ptr = (int*)gc_alloc(sizeof(int));
    assert(ptr != NULL);
    *ptr = 42;
    assert(*ptr == 42);
    printf("test_gc_alloc passed.\n");
}

int main() {
    gc_init();
    test_gc_alloc();
    gc_collect();
    return 0;
}
