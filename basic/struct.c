#include <stdio.h>

int main() {
    struct Person {
        char name[10];
        char *gender;
        int age;
    };
    struct Person man = {"Jack", "男", 10};

    printf("man's name: %s\n", man.name);
    printf("man's gender: %c\n", man.gender);
    printf("man's age: %d\n", man.age);
    return 0;
}