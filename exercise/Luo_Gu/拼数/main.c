#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(char* a, char* b) {
    int len_a, len_b;
    len_a = strlen(a); len_b = strlen(b);
    int size = len_a > len_b ? len_b : len_a;

    for (int i=0; i<size; i++) {
        int diff = a[i] - b[i];
        if (diff == 0) {
            continue;
        } else if (diff > 0) {
            return 1;
        } else if (diff < 0) {
            return 0;
        }
    }
    return 0;
}

void wrap(char* str_arr[], int index1, int index2) {
    char* temp = str_arr[index1];
    str_arr[index1] = str_arr[index2];
    str_arr[index2] = temp;
}

void sort(char* str_arr[], int length) {
    for (int i=0; i<length-1; i++) {
        for (int j=0; j<length-1; j++) {
            if (!compare(str_arr[j], str_arr[j+1])) {
                wrap(str_arr, j, j+1);
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    char* str_arr[n];
    for (int i=0; i<n; i++) {
        char* str = (char *)calloc(10, sizeof(char));
        scanf("%s", str);
        str_arr[i] = str;
    }

    sort(str_arr, n);

    for (int i=0; i<n; i++) {
        printf("%s", str_arr[i]);
    }
    return 0;
}