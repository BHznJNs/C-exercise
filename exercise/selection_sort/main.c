#include <stdio.h>

int main() {
    const int LEN = 10;
    int ARRAY[] = {9, 1, 4, 0, 2, 8, 6, 3, 7, 5};
    int TARGET_ARRAY[10];
    int min = ARRAY[0]; // 初始为数组第一项


    for (int i=0; i<LEN; i++) {
        for (int j=0; j<LEN; j++) {
            const int ITEM = ARRAY[j];
            if (ITEM < min) {
                ARRAY[j] = min;
                min = ITEM;
            }
        }
        TARGET_ARRAY[i] = min;
    }#include <stdio.h>

void array_printer(int array[], int size) {
    const int LN = 5; // 5 个元素一换行

    printf("[\n");
    for (int i=0; i<size; i++) {
        if (i % LN == 0) {
            printf(" ");
        };
        printf("%d, ", array[i]);
        // 行尾，判断是否为数组最后一项

    for (int k=0; k<LEN; k++) {
        printf("TARGET_ARRAY[%d]: %d\n", k, TARGET_ARRAY[k]);
    }

    return 0;
}