#include <stdio.h>

#define TRUE 1
#define FALSE 0

int search(int array[], int array_length, int value) {
    int is_exist = FALSE;

    for (int i=0; i<array_length; i++) {
        int value_in_array = array[i];
        if (value == value_in_array) {
            is_exist = TRUE;
        }
    }

    return is_exist;
}

void sort(int array[], int length) {
    for (int i=0; i<length; i++) {
        int min = array[i];
        int min_index = i;

        for (int j=i; j<length; j++) {
            int value = array[j];
            if (value < min) {
                min = value;
                min_index = j;
            }
        }
        array[min_index] = array[i];
        array[i] = min;
    }
}

int main() {
    int random_num;
    scanf("%d", &random_num);

    int random_arr[random_num];
    for (int i=0; i<random_num; i++) {
        scanf("%d", &random_arr[i]);
    }

    // remove repeat element
    int target_arr[random_num];
    target_arr[0] = random_arr[0];

    int target_arr_length = 1;
    for (int i=0; i<random_num; i++) {
        int value = random_arr[i];
        int is_exist = search(target_arr, random_num, value);
        if (!is_exist) {
            target_arr[target_arr_length] = value;
            target_arr_length++;
        }
    }
    for (int i=0; i<target_arr_length; i++) {
        printf("arr[%d]: %d\n", i, target_arr[i]);
    }
    // ----------------------

    sort(target_arr, target_arr_length);

    // printf("%d\n", target_arr_length);
    // for (int i=0; i<target_arr_length; i++) {
    //     printf("%d", target_arr[i]);
    //     if (i != (target_arr_length - 1)) {
    //         printf(" ");
    //     }
    // }

    // int arr[] = {20, 40, 321, 67, 40, 20, 89, 301, 407, 15};
    // int length = 10;
    // sort(arr, length);
    

    return 0;
}