#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    int max_length = 0;
    int current_length = 1;
    int last_num = 0;
    for (int i=0; i<n; i++) {
        int current_num = arr[i];
        if (last_num) {
            if ((current_num - last_num) == 1) {
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
    if (current_length > max_length) {
        max_length = current_length;
    }
    printf("%d", max_length);
    return 0;
}