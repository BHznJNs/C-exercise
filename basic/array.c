#include <stdio.h>

void array_printer(int array[], int array_size) {
	int i; 
    for (i = 0;i < array_size; i++) {
        printf("array[%d]: %d\n", i, array[i]);
    }

    return;
}

int main() {
    // 定义数组
    // array_element_type array_name[ array_size ]
    // int array1[10];
    // array1[0] = 1;

    int array[] = {0000, 1, 2, 3, 4, 5};
    const int ARRAY_SIZE = sizeof(array) / sizeof(array[0]);
    array_printer(array, ARRAY_SIZE);

    return 0;
}
