#include <stdio.h>

int converter(char arr1[], int arr2[], int length) {
    int is_all_zero = 1;
    for (int i=0; i<length; i++) {
        if (arr1[i] == '1') {
            arr2[i] = 1;
            is_all_zero = 0;
        } else {
            arr2[i] = 0;
        }
    }
    return is_all_zero;
}

int calculate(int worthes[], int initial_states[], int length) {
    for (int i=1; i<length; i++) {
        if (worthes[i] < worthes[i-1]) {
            if (initial_states[i] == 1 && initial_states[i-1] == 0) {
                initial_states[i] = 0;
                initial_states[i-1] = 1;
            }
        }
    }
    int sum = 0;
    for (int i=0; i<length; i++) {
        if (initial_states[i]) {
            sum += worthes[i];
        }
    }
    return sum;
}

int main() {
    int t;
    scanf("%d", &t);

    int result_arr[t];
    for (int i=0; i<t; i++) {
        int length;
        scanf("%d", &length);

        char initial_states_char[length];
        scanf("%s", initial_states_char);
        int initial_states[length];
        int is_all_zero = converter(initial_states_char, initial_states, length);
        if (is_all_zero) {
            result_arr[i] = 0;
            continue;
        }

        int worthes[length];
        for (int j=0; j<length; j++) {
            scanf("%d", &worthes[j]);
        }
        result_arr[i] = calculate(worthes, initial_states, length);
    }

    for (int i=0; i<t; i++) {
        printf("%d\n", result_arr[i]);
    }
    return 0;
}