#include <stdio.h>

int find_min(int arr[], int length) {
    int min_num, min_index;
    for (int i=0; i<length; i++) {
        int current = arr[i];
        if (!i) {
            min_num = current;
            min_index = 0;
            continue;
        }
        if (current < min_num) {
            min_num = current;
            min_index = i;
        }
    }
    arr[min_index] = 1000001;
    return min_index+1;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n], data[n], result[n];
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
        data[i] = arr[i];
    }

    for (int i=0; i<n; i++) {
        int min_index = find_min(arr, n);
        result[i] = min_index;

        printf("%d", min_index);
        if (i != n-1) {
            printf(" ");
        } else {
            printf("\n");
        }
    }

    int sum = 0;
    for (int i=0; i<n; i++) {
        if (!i) continue;

        for (int j=0; j<i; j++) {
            int index = result[j];
            sum += data[index-1];
        }
    }
    float average = (float)sum / (float)n;
    printf("%.2f", average);
    return 0;
}