#include <stdio.h>

void test0(int* arr) {
    printf("value: %d\n", arr[0]);
}

void test1(int arr[]) {
    printf("value: %d\n", arr[0]);
}

int main() {
    int arr[] = {1, 2, 3, 4};
    test0(arr);
    test1(arr);
    return 0;
}