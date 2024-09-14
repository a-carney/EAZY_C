#include "easyc.h"
#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
} Person;

int main() {
    gc_init();

    // Create a new Person object
    Person* person = new(Person);
    person->id = 101;
    strcpy(person->name, "John Doe");

    printf("Person ID: %d, Name: %s\n", person->id, person->name);

    gc_collect();
    return 0;
}
