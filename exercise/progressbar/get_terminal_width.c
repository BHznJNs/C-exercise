#include <sys/ioctl.h>

int get_terminal_width() {
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);
    const int SCREEN_WIDTH = w.ws_col;
    return SCREEN_WIDTH;
}