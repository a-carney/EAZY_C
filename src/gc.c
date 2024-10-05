#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "gc.h"


typedef struct {
    void* ptr;
    size_t size;
    int marked;
} GCEntry;

#define MAX_GC_ENTRIES 1024


static GCEntry gc_entries[MAX_GC_ENTRIES];
static size_t gc_count = 0;


void gc_init() {
    gc_count = 0;
    memset(gc_entries, 0, sizeof(gc_entries));
}

#define PRINT_ERR(err)  fprintf(stderr, err)

#define E_GCLIMIT "gc_alloc: GC entries limit reached.\n"
#define E_GCMEMFAIL "gc_alloc: memory allocation failure\n"


void* gc_alloc(size_t size) {
    if (gc_count >= MAX_GC_ENTRIES) { PRINT_ERR(E_GCLIMIT); exit(EXIT_FAILURE); }

    void* ptr = malloc(size);
    if (ptr == NULL) { PRINT_ERR(E_GCMEMFAIL); exit(EXIT_FAILURE); }

    gc_entries[gc_count].ptr = ptr;
    gc_entries[gc_count].size = size;
    gc_entries[gc_count].marked = 0;
    gc_count++;

    return ptr;
}

void gc_collect() {
    for (size_t i = 0; i < gc_count; i++)
    {
        if (gc_entries[i].ptr != NULL) {
            free(gc_entries[i].ptr);
            gc_entries[i].ptr = NULL;
        }
        gc_count = 0;
    }
}
