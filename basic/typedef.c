#include <stdio.h>
#include <string.h>

int main() {
    typedef struct {
        char name[20];
        int age;
    } Person;

    Person man;
    strcpy(man.name, "Jack");
    man.age = 18;

    printf("man's name: %s\n", man.name);
    printf("man's age: %d\n", man.age);

    return 0;
}