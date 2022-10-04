#include <stdio.h>

int main() {
    int n = 10;
    int arr[] = {1, 5, 6, 2, 3, 4, 5, 6, 8, 9};

    int max_length = 0;
    int current_length = 1;
    int last_num = 0;
    for (int i=0; i<n; i++) {
        int current_num = arr[i];
        if (last_num) {
            if (current_num > last_num && (current_num - last_num) == 1) {
                current_length += 1;
            } else {
                if (current_length > max_length) {
                    max_length = current_length;
                }
                current_length = 1;
            }
        }
        last_num = current_num;
    }
    printf("%d", max_length);
    return 0;
}