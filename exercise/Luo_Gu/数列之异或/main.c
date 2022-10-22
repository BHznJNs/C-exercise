#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    long long result = 1;
    for (int i=2; i<n+1; i++) {
        result = result ^ i;
    }
    printf("%d", result);
    return 0;
}