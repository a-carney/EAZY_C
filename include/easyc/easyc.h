#ifndef EASYC_H
#define EASYC_H

#include "gc.h"

#define new(type)   (type*)gc_alloc(sizeof(type));

#define new_array(type, count) (type*)gc_alloc(sizeof(type) * (count))

#endif