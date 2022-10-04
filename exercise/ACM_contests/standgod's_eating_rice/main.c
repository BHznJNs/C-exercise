#include <stdio.h>

int main() {
    // int n = 5;
    // int a = 1000000100;
    // //       n-1
    // int bowls[4] = {1000000102,1000000105,1000000101,1000000103};
    int n, a;
    scanf("%d", &n);
    scanf("%d", &a);
    int bowls[n-1];
    for (int i=0; i<n-1; i++) {
        scanf("%d", &bowls[i]);
    }

    int origin_bowls[2001] = { 0 };

    for (int i=0; i<n-1; i++) {
        int current = bowls[i];
        int index = current - a;
        origin_bowls[index] += 1;
    }

    int missing_index = -1;
    for (int i=1; i<2001; i++) {
        int current = origin_bowls[i];

        if (current == 0) {
            missing_index = i;
            break;
        }
    }

    printf("%d", missing_index);
    return 0;
}