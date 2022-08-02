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
    int len = 12;
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    array_printer(array, len);
    /*
    [
     1, 2, 3, 4, 5, 
     6, 7, 8, 9, 10, 
     11, 12, 
    ]
    */

    return 0;
}