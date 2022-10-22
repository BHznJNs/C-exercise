#include <stdio.h>
#include <stdlib.h>

int max_index;

int max(int a, int b) {
    if (a >= b) {
        return a;
    } else {
        return b;
    }
}

int dp(int x, int y, int* arr[], int* map[]) {
    int result;

    if (x == max_index) {
        result = arr[x][y];
    } else if (y == max_index) {
        result = arr[x][y];
    } else {
        int map_value = map[x][y];
        if (map_value) {
            result = map_value;
        } else {
            result = max(
                dp(x+1, y, arr, map),
                dp(x+1, y+1, arr, map)
            ) + arr[x][y];
            map[x][y] = result;
        }
    }
    return result;
}

int main() {
    int r;
    scanf("%d", &r);
    max_index = r - 1;

    int* arr[r];
    int* map[r];
    for (int i=0; i<r; i++) {
        int* row = (int *)calloc(i+1, sizeof(int));
        int* map_row = (int *)calloc(i+1, sizeof(int));
        for (int j=0; j<i+1; j++) {
            scanf("%d", &row[j]);
        }
        arr[i] = row;
        map[i] = map_row;
    }

    printf("%d", dp(0, 0, arr, map));
    return 0;
}