#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int remain = n;
    int current = 1;
    int sum = 0;
    for (int i=0; i<n; i++) {
        if (remain < current) {
            sum += current * remain;
            break;
        }
        sum     += current * current;
        remain  -= current;
        current += 1;
    }
    printf("%d", sum);
    return 0;
}