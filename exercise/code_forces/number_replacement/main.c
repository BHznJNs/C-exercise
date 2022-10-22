#include <stdio.h>

int check(int num_arr[], char char_arr[], int length) {
    char map[51] = { '\0' };

    for (int i=0; i<length; i++) {
        int current_num_value = num_arr[i];
        char current_char_value = char_arr[i];

        if (!map[current_num_value]) { // == 0
            map[current_num_value] = current_char_value;
        } else if (map[current_num_value] != current_char_value) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int t;
    scanf("%d", &t);

    int result[t];

    for (int i=0; i<t; i++) {
        int size;
        scanf("%d", &size);
        int num_arr[size];
        char char_arr[size];

        for (int j=0; j<size; j++) {
            scanf("%d", &num_arr[j]);
        }
        scanf("%s", char_arr);

        result[i] = check(num_arr, char_arr, size);
    }

    for (int i=0; i<t; i++) {
        if (result[i]) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}