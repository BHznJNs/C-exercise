#include <stdio.h>

int calc_c(int upper, int base) {
    int result = 1;
    for (int i=base-upper+1; i<base+1; i++) {
        result *= i;
    }
    int div = 1;
    for (int i=1; i<upper+1; i++) {
        div *= i;
    }
    return result / div;
}

int calculate(int arr[], int length) {
    int map[10] = { 0 };
    for (int i=0; i<length; i++) {
        map[arr[i]] = 1;
    }

    int lost_num = 0;
    for (int i=0; i<10; i++) {
        if (!map[i]) {
            lost_num += 1;
        }
    }
    return calc_c(2, lost_num) * 6;
}

int main() {
    int t;
    scanf("%d", &t);

    int results[t];
    for (int i=0; i<t; i++) {
        int n;
        scanf("%d", &n);

        int arr[n];
        for (int j=0; j<n; j++) {
            scanf("%d", &arr[j]);
        }
        results[i] = calculate(arr, n);
    }
    for (int i=0; i<t; i++) {
        printf("%d\n", results[i]);
    }
    return 0;
}