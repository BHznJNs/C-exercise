#include <stdio.h>

void print_percent(int percent) {
    extern int progress;
    extern int PROGRESS_WIDTH;


    for (int i=0; i < PROGRESS_WIDTH; i++) {
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