#include "easyc.h"
#include <stdio.h>

int main() {
    gc_init();
    printf("Hello, Easy C!\n");
    gc_collect();
    return 0;
}
