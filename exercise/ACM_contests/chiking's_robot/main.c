#include <stdio.h>
#include <stdlib.h>

int n, m;

int min(int a, int b) {
    if (a <= b) {
        return a;
    } else {
        return b;
    }
}

int calc_3(int x, int y, int x1, int y1, int x2, int y2, int map[n][m], int* store[]) {
    const int store_value = store[x][y];
    const int map_value = map[x][y];

    if (store_value) {
        return store_value-1;
    }
    if (map_value) {
        return 1;
    }
    if (x == x2 && y == y2) {
        return 0;
    }
    if (x == x2) {
        int value = calc_3(x, y + 1, x1, y1, x2, y2, map, store);
        store[x][y] = value + 1;
        return value;
    }
    if (y == y2) {
        int value = calc_3(x + 1, y, x1, y1, x2, y2, map, store);
        store[x][y] = value + 1;
        return value;
    }

    int min_value = min(
        calc_3(x + 1, y, x1, y1, x2, y2, map, store),
        calc_3(x, y + 1, x1, y1, x2, y2, map, store)
    );
    store[x][y] = min_value + 1;
    return min_value;
}

int calculate(int type, int x1, int y1, int x2, int y2, int map[n][m]) {
    x1 -= 1; x2 -= 1; y1 -= 1; y2 -= 1;

    if (type == 1) {
        if (y1 == y2) {
            for (int i=x1; i<=x2; i++) {
                if (map[i][y1]) {
                    return 0;
                }
            }
            return 1;
        }
    }
    if (type == 2) {
        if (x1 == x2) {
            for (int i=y1; i<=y2; i++) {
                if (map[x1][i]) {
                    return 0;
                }
            }
            return 1;
        }
    }
    if (type == 3) {
        if (!(x1 > x2 || y1 > y2)) {
            int* store[n];
            for (int i=0; i<n; i++) {
                store[i] = (int *)calloc(m, sizeof(int));
            }
            return !calc_3(x1, y1, x1, y1, x2, y2, map, store);
        }
    }
    return 0;
}

int main() {
    scanf("%d %d", &n, &m);

    int map[n][m];
    for (int i=0; i<n; i++) {
        char str[m];
        scanf("%s", str);

        for (int j=0; j<m; j++) {
            map[i][j] = str[j] - 48;
        }
    }

    int q;
    scanf("%d", &q);
    int answer[q];
    
    for (int i=0; i<q; i++) {
        int t, x1, y1, x2, y2;
        scanf(
            "%d %d %d %d %d",
            &t, &x1, &y1, &x2, &y2
        );
        answer[i] = calculate(t, x1, y1, x2, y2, map);
    }

    for (int i=0; i<q; i++) {
        if (answer[i]) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }
    return 0;
}