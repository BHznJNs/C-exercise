#include <stdio.h>

typedef short BOOL;
#define TRUE  1;
#define FALSE 0;

BOOL is_covered(int carpet[], int target[]) {
    const int target_x = target[0];
    const int target_y = target[1];

    const int carpet_x = carpet[0];
    const int carpet_y = carpet[1];
    const int carpet_max_x = carpet_x + carpet[2];
    const int carpet_max_y = carpet_y + carpet[3];

    if (target_x >= carpet_x && target_x <= carpet_max_x) {
        if (target_y >= carpet_y && target_y <= carpet_max_y) {
            return TRUE;
        }
    }
    return FALSE;
}

int main() {
    int n;
    scanf("%d", &n);
    int carpets[n][4];
    for (int i=0; i<n; i++) {
        scanf("%d %d %d %d",
            &carpets[i][0], &carpets[i][1],
            &carpets[i][2], &carpets[i][3]
        );
    }
    int target[2];
    scanf("%d %d", &target[0], &target[1]);

    int max_carpet_level = -1;
    for (int i=0; i<n; i++) {
        BOOL is_covered_ = is_covered(carpets[i], target);
        if (is_covered_) {
            max_carpet_level = i + 1;
        }
    }
    printf("%d", max_carpet_level);
    return 0;
}