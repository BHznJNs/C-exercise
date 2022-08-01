#include <stdio.h>
#include <unistd.h>
#include "./get_terminal_width.c"
#include "./get_percent.c"
#include "./print_percent.c"
#include "./clear_percent.c"

int main() {
    int progress = 0; // min -> 0 ; max -> 100

    const int SCREEN_WIDTH = get_terminal_width() - 5;
    for (;progress<101; progress++) {
        const int percent = get_percent(progress, SCREEN_WIDTH);
        print_percent(percent, progress, SCREEN_WIDTH);
        fflush(stdout);
        sleep(1);
        if (progress != 100) {
            clear_percent(SCREEN_WIDTH + 5);
            fflush(stdout);
        }
    };
    return 0;
}