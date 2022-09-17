#include <stdio.h>

int main() {
    int *p = NULL;
    int arr[] = {1, 2, 3, 4};

    p = arr;

    printf("value[0]: %d\n", *p);
    printf("value[1]: %d\n", *(p + 1));
    printf("value[2]: %d\n", *(p + 2));
    printf("value[3]: %d\n", *(p + 3));
    return 0;
}