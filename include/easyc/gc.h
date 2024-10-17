#ifndef GC_H
#define GC_H

#include <stddef.h>

void gc_init();
void* gc_alloc(size_t size);
void gc_collect();

#endif