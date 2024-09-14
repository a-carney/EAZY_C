#include "easyc.h"
#include <stdio.h>

// Macro to define a 'map' operation on arrays
#define MAP(array, size, func) do { \
    for(size_t i = 0; i < size; i++) { \
        array[i] = func(array[i]); \
    } \
} while(0)

// Sample function to double an integer
int double_func(int x) {
    return x * 2;
}

int main() {
    gc_init();

    size_t size = 5;
    int* numbers = new(int[size]);
    for(size_t i = 0; i < size; i++) {
        numbers[i] = i + 1;
    }

    // Apply the double_func to each element using MAP macro
    MAP(numbers, size, double_func);

    // Print the results
    for(size_t i = 0; i < size; i++) {
        printf("numbers[%zu] = %d\n", i, numbers[i]);
    }

    gc_collect();
    return 0;
}
