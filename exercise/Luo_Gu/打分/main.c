#include <stdio.h>

int main() {
    int n, map[11] = { 0 };
    scanf("%d", &n);

    for (int i=0; i<n; i++) {
        int num;
        scanf("%d", &num);
        map[num] += 1;
    }
    for (int i=0; i<11; i++) {
        if (map[i]) {
            map[i] -= 1;
            break;
        }
    }
    for (int i=10; i>=0; i--) {
        if (map[i]) {
            map[i] -= 1;
            break;
        }
    }

    int sum = 0;
    for (int i=0; i<11; i++) {
        sum += i * map[i];
    }
    float average = (float)sum / (float)(n - 2);
    printf("%.2f", average);
    return 0;
}