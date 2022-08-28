#include <stdio.h>

int main() {
    int number = 1;
    int *pointer = &number;
    int *null_poiter = NULL;

    printf("Address of pointer: %p\n", pointer);
    printf("Value of *pointer: %d\n", *pointer);
    return 0;
}