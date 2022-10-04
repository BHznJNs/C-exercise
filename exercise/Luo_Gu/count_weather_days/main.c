#include <stdio.h>
#include <stdlib.h>

void push(int* arr, int* arr_length, int value) {
    arr = (int *)realloc(arr, sizeof(int));
    arr[*arr_length] = value;
    *arr_length += 1;
}

int main() {
    int n = 10;
    int input_arr[] = {1, 2, 3, 2, 4, 5, 6, 8, 5, 9};
    // int input_arr[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    int last_value = -1;
    int max_continuous_day = 1;
    int max_continuous_days_length = 0;
    int* max_continuous_days = (int *)calloc(0, sizeof(int));

    for (int i=0; i<n; i++) {
        int current = input_arr[i];
        if (last_value >= -1) {
            // 存在 last 值
            if (current > last_value) {
                max_continuous_day += 1;
            } else {
                push(max_continuous_days, &max_continuous_days_length, max_continuous_day);
                max_continuous_day = 1;
            }
            if (i == n - 1) {
                push(max_continuous_days, &max_continuous_days_length, max_continuous_day);
            }
        }
        last_value = current;
    }

    int max_times = 0;
    for (int i=0; i<max_continuous_days_length; i++) {
        int value = max_continuous_days[i];
        if (!max_times || value > max_times){
            max_times = value;
        }
    }
    printf("%d", max_times);
    return 0;
}