#include <stdio.h>

int double_func(int number) {
    return number * 2;
}

int main() {
    int (*p) (int) = &double_func;
    int number = p(10);
    printf("number: %d\n", number);
    return 0;
}