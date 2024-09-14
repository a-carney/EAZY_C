#include "easyc.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>

typedef struct {
    int value;
    char name[20];
} TestStruct;

void test_new() {
    TestStruct* ts = new(TestStruct);
    ts->value = 100;
    strcpy(ts->name, "Test");

    assert(ts->value == 100);
    assert(strcmp(ts->name, "Test") == 0);
    printf("test_new passed.\n");
}

int main() {
    gc_init();
    test_new();
    gc_collect();
    return 0;
}
