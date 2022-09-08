#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* two_sum(int* nums, int numsSize, int target, int* returnSize){
    int *result = (int *)malloc(2 * sizeof(int));
    _Bool found = 0;

    for (int i=0; i < numsSize - 1; i++) {
        for (int j=i + 1; j < numsSize; j++) {
            printf("i: %d, j: %d\n", i, j);
            int sum = nums[i] + nums[j];
            if (sum == target) {
                printf("result: %d\n", sum);
                result[0] = i;
                result[1] = j;
                found = 1;
            }
        }
    }
    if (found) {
        *returnSize = 2;
    } else {
        *returnSize = 0;
    }
    return result;
}

int main() {
    int nums[] = {3, 3};
    int nums_size = 2;
    int target = 6;
    int return_size;

    int *arr = two_sum(nums, nums_size, target, &return_size);
    printf("arr[0]: %d\n", arr[0]);
    printf("arr[1]: %d\n", arr[1]);
    printf("return_size: %d", return_size);

    return 0;
}