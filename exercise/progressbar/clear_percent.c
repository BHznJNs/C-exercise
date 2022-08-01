#include <stdio.h>

void clear_percent(int percent) {
    for (int i=0; i < percent; i++) {
        printf("\b");
        fflush(stdout);
    };
}