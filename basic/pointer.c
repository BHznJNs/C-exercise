#include <stdio.h>

int main() {
    int arr[] = {0, 1, 2, 3};
    int* p = arr;
    int** pr = &p;
    printf("%p", *pr);
    return 0;
}