#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int current = 0;
    for (int i=n; i>0; i--) {
        for (int j=1; j<i+1; j++) {
            current += 1;
            if (current < 10) {
                printf("0%d", current);
            } else {
                printf("%d", current);
            }
        }
        printf("\n");
    }
    return 0;
}