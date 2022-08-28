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
    int current;

    for (int i=1; i<LEN; i++) {
        current = i;
        while (current != 0 && array[current] < array[current-1]) {
            // 互换位置
            const int TEMP = array[current];
            array[current] = array[current-1];
            array[current-1] = TEMP;

            current--;
        }
    }

    array_printer(array, LEN);

    return 0;
}