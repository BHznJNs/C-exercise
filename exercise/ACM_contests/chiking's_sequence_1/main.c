#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    int operate_times[t];

    int length_arr[t];
    int sequence_arr[t][100];
    for (int i=0; i<t; i++) {
        operate_times[i] = 0;

        int length;
        scanf("%d", &length);
        length_arr[i] = length;

        int* sequence = sequence_arr[i];
        for (int j=0; j<length; j++) {
            scanf("%d", &sequence[j]);
        }
    }

    for (int i=0; i<t; i++) {
        int* sequence = sequence_arr[i];
        int length = length_arr[i];

        for (int j=1; j<length+1; j++) {
            int value = sequence[j - 1];
            if (value > j) {
                int diff = value - j;
                operate_times[i] += diff - operate_times[i];
            }
        }
    }

    for (int i=0; i<t; i++) {
        printf("%d\n", operate_times[i]);
    }

    return 0;
}