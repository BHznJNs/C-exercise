#include <stdio.h>

int binary_search(int arr[], int length, int target) {
    int start = 0;
    int end = length - 1;

    while (start <= end) {
        int middle_index = (start + end) / 2;
        int current = arr[middle_index];
        if (current == target) {
            return middle_index;
        }
        if (current > target) {
            end = middle_index - 1;
        } else {
            start = middle_index + 1;
        }
    }
    return -1;
}

int main() { //        2  3       1
    int arr[] = {1, 5, 8, 11, 25, 36, 38, 48, 67, 68, 90};
    int length = sizeof(arr) / sizeof(arr[0]);
    int target = 11;

    int index = binary_search(arr, length, target);
    printf("%d", index);
    return 0;
}