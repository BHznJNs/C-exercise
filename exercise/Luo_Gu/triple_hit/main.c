#include <stdio.h>

int abs(int num) {
    if (num >= 0) {
        return num;
    } else {
        return -num;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int elements[1001];

    for (int i=0; i<n; i++) {
        scanf("%d", &elements[i]);
    }
    // 计算差值
    int diffs[1000];
    for (int i=0; i<n-1; i++) {
        int diff = abs(elements[i + 1] - elements[i]);
        diffs[i] = diff;
    }
    // -------

    // 初始化 target_nums
    int target_nums[1000];
    for (int i=0; i<n; i++) {target_nums[i] = 0;}
    // -----------------
    
    for (int i=0; i<n-1; i++) {
        int value = diffs[i];
        target_nums[value]++;
    }

    int is_jolly = 1;
    for (int i=1; i<n; i++) {
        if (!target_nums[i]) {
            is_jolly = 0;
        }
    }

    if (is_jolly) {
        printf("Jolly");
    } else {
        printf("Not jolly");
    }
    
    return 0;
}