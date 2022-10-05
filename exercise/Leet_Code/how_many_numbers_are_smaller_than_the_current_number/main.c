#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;

    int* result = (int *)calloc(numsSize, sizeof(int));

    for (int i=0; i<numsSize; i++) {
        // int current = nums[i];
        for (int j=0; j<numsSize; j++) {
            if (j == i) {
                continue;
            }

            if (nums[j] < nums[i]) {
                result[i] += 1;
            }
        }
    }
    return result;
}

int main() {
    int input_arr[5] = {8,1,2,2,3};
    int length = 5;
    int return_size = 0;
    int* result = smallerNumbersThanCurrent(input_arr, length, &return_size);

    for (int i=0; i<length; i++) {
        printf("%d\n", result[i]);
    }
    free(result);
    return 0;
}