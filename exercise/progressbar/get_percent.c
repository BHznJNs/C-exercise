#include <math.h>

int get_percent(int progress, int screen_width) {
    // 类型转换
    const float PROGRESSF = (float)progress;
    const float SCREEN_WIDTHF = (float)screen_width;

    const float PERCENT = PROGRESSF / 100.0 * SCREEN_WIDTHF;
    const int PERCENT_INT = (int)PERCENT;
    return PERCENT_INT;
}