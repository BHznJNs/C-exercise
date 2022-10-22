#include <stdio.h>

int n, m, p;

int check_relative(int family[][n+1], int a, int b) {
    for (int i=0; i<n+1; i++) {
        if (family[a][i]) {
            for (int j=0; j<n+1; j++) {
                if (family[i][j] && j == b) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main() {
    for (int i=0; i<m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        family[a][b] = 1;
    }

    int is_relative[p];
    for (int i=0; i<p; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        is_relative[i] = check_relative(family, a, b);
    }
    for (int i=0; i<p; i++) {
        if (is_relative[i]) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}