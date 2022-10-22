#include <stdio.h>
#include <stdlib.h>

int _m, _n;
int map[101][101];

int dp(int arr[][_n], int x, int y) {
    int value = arr[x][y];

    if (value) {
        return value;
    }

    int map_value = map[x][y];
    if (map_value) {
        return map_value;
    }

    int result;
    if (x == 0 && y == 0) {
        result = 0;
    } else if (x == 0) {
        result = dp(arr, x, y-1);
    } else if (y == 0) {
        result = dp(arr, x-1, y);
    } else {
        result = dp(arr, x-1, y) + dp(arr, x, y-1);
    }
    map[x][y] = result;
    return result;
}

int uniquePaths(int m, int n){
    if (m == 1 || n == 1) {
        return 1;
    }
    _m = m; _n = n;
    int arr[m][n];
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            arr[i][j] = 0;
        }
    }
    arr[0][1] = 1;
    arr[1][0] = 1;

    // int result = dp(arr, m-1, n-1);
    return dp(arr, m-1, n-1);
}

int main() {
    int m = 3;
    int n = 7;
    int result = uniquePaths(m, n);
    printf("%d", result);
    return 0;
}