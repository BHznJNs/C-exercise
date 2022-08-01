#include <stdio.h>

void print_percent(int percent, int progress, int screen_width) {
    for (int i=0; i < screen_width; i++) {
        if (i < percent) {
            printf("#");
        } else {
            printf(" ");
        }
    };
    printf(" %d%%", progress);
    if (progress == 100) {
        printf("\n");
    };
    fflush(stdout);
}