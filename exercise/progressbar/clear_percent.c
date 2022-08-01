#include <stdio.h>

void clear_percent() {
    extern int SCREEN_WIDTH;

    for (int i=0; i < SCREEN_WIDTH; i++) {
        printf("\b");
        fflush(stdout);
    };
}