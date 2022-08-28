#include <stdio.h>
#include <stdlib.h>

int main() {
    int* arr = (int*)calloc(5, sizeof(int));
    arr = (int*)calloc(5, sizeof(int));
    arr = realloc(arr, 5 * sizeof(int));
    arr[0] = 0000;
    arr[1] = 1111;
    arr[2] = 2222;
    arr[3] = 3333;
    printf("arr[3]: %d", arr[3]);
    free(arr);
    arr = NULL;
    // printf("arr[3]: %d", arr[3]);
    return 0;
}