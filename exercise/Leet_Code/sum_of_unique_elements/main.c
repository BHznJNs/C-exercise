#include <stdio.h>

int sumOfUnique(int* nums, int numsSize){
    int num_map[101] = { 0 };

    for (int i=0; i<numsSize; i++) {
        int current = nums[i];
        num_map[current] += 1;
    }

    int unique_num_arr[50];
    int unique_num_len = 0;
    for (int i=0; i<101; i++) {
        int num = num_map[i];
        if (num == 1) {
            unique_num_arr[unique_num_len] = i;
            unique_num_len += 1;
        }
    }

    int sum = 0;
    for (int i=0; i<unique_num_len; i++) {
        sum += unique_num_arr[i];
    }

    return sum;
}

int main() {
    int arr[] = {1,2,3,2};
    printf("%d", sumOfUnique(arr, 4));
    return 0;
}