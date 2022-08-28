#include <stdio.h>

void array_printer(int array[], int size) {
    const int LN = 5; // 5 个元素一换行

    printf("[\n");
    for (int i=0; i<size; i++) {
        if (i % LN == 0) {
            printf(" ");
        };
        printf("%d, ", array[i]);
        // 行尾，判断是否为数组最后一项
        if ((i + 1) % LN == 0 && (i + 1) != size) {
            printf("\n");
        };
    }
    printf("\n]\n");
}

int main() {
    const int LEN = 10;
    int array[] = {9, 1, 4, 0, 2, 8, 6, 3, 7, 5};
    int temp;

    for (int i=0; i<LEN; i++) {
        temp = array[i];
        for (int j=0; j<LEN; j++) {
            if (array[j] > temp) {
                array[i] = array[j];
                array[j] = temp;
                temp = array[i];
            }
        }
    }

    array_printer(array, 10);
    return 0;
}