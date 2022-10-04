#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int smoked = 0; // 吸烟数
    int snipe = 0;  // 烟蒂数

    for (int i=0; i<n; i++) {
        smoked += 1;
        snipe += 1;

        if (snipe == k) {
            snipe = 0;
            n += 1;
        }
    }
    printf("%d\n", smoked);
    return 0;
}