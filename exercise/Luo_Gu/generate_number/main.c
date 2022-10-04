#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int rules[2][k];
    for (int i=0; i<k; i++) {
        scanf("%d %d", &rules[0][i], &rules[1][i]);
    }
    return 0;
}