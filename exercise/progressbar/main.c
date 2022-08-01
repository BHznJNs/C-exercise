#include <stdio.h>
#include <unistd.h>
#include "./get_terminal_width.c"
#include "./get_percent.c"
#include "./print_percent.c"
#include "./clear_percent.c"

int progress = 0;
int SCREEN_WIDTH;
int PROGRESS_WIDTH;

int main() {
    SCREEN_WIDTH = get_terminal_width();
    PROGRESS_WIDTH = SCREEN_WIDTH - 5;

    extern int progress; // min -> 0 ; max -> 100

    for (;progress<101; progress++) {
        const int percent = get_percent();
        print_percent(percent);
        fflush(stdout);
        sleep(1);
        if (progress != 100) {
            clear_percent();
            fflush(stdout);
        }
    };
    return 0;
}