#include <stdio.h>

int map[46];

int climbStairs(int n) {
    if (n == 1) {
        return 1;
    } else if (n == 2) {
        return 2;
    } else {
        int result;
        if (!map[n]) {
            result = climbStairs(n-1) + climbStairs(n-2);
            map[n] = result;
        } else {
            result = map[n];
        }
        return result;
    }
}

int main() {
    printf("%d", numWays(7));
    return 0;
}