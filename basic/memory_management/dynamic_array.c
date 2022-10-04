#include <stdio.h>
#include <stdlib.h>

int main() {
    int* arr = (int *)calloc(0, sizeof(int));
    arr[0] = 0000;
    arr[1] = 1111;
    arr[2] = 2222;
    arr[3] = 3333;
    printf("arr[0]: %d\n", arr[0]);
    printf("arr[1]: %d\n", arr[1]);
    printf("arr[2]: %d\n", arr[2]);
    printf("arr[3]: %d\n", arr[3]);
    free(arr);
    arr = NULL;
    // printf("arr[3]: %d", arr[3]);
    return 0;
}