#include <stdio.h>
#include <stdlib.h>

int bx, by; // B 点坐标
int hx, hy; // 马坐标

int** map; // 棋盘

// int* control_points[9]; // 控制点数组
// int cp_length; // 控制点数组大小

void map_init() {
    int** arr = (int **)calloc(bx + 1, sizeof(int *));
    for (int i=0; i<bx+1; i++) {
        arr[i] = (int *)calloc(by + 1, sizeof(int));
    }
    map = arr;
}

int compare(int x, int y, int pos[2]) {
    if (x == pos[0] && y == pos[1]) {
        return 1;
    } else {
        return 0;
    }
}

// 计算控制点
void cp_compute() {
    int arr_x[9] = {1, 2, 2, 1, 0, -1, -2, -2, -1};
    int arr_y[9] = {-2, -1, 1, 2, 0, 2, 1, -1, -2};

    for (int i=1; i<9; i++) {
        int x = hx + arr_x[i];
        int y = hy + arr_y[i];

        if (x > bx || x < 0 || y > by || y < 0) {
            continue;
        } else {
            map[x][y] = -1;
        }
    }
}

int dp(int x, int y) {
    if (x < 0 || y < 0) {
        return 0;
    }
    
    int value = map[x][y];
    if (value == -1) {
        printf("\n");
        return 0;
    }
    printf("[%d, %d]\n", x, y);
    if (value == 0) {
        return dp(x - 1, y) + dp(x, y - 1);
    } else if (value > 0) {
        printf("\n");
        return value;
    }
}

int main() {
    bx = 6; by = 6;
    hx = 3; hy = 3;
    // bx = 4; by = 8;
    // hx = 2; hy = 4;
    // scanf("%d %d %d %d", &bx, &by, &hx, &hy);

    map_init();
    map[1][0] = 1;
    map[0][1] = 1;
    cp_compute();
    printf("%d", dp(bx, by));
    return 0;
}