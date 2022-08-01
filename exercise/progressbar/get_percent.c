#include <math.h>

int get_percent() {
    extern int progress;
    extern int PROGRESS_WIDTH;

    // 类型转换
    const float PROGRESSF = (float)progress;
    const float PROGRESS_WIDTHF = (float)PROGRESS_WIDTH;

    const float PERCENT = PROGRESSF / 100.0 * PROGRESS_WIDTHF;
    const int PERCENT_INT = (int)PERCENT;
    return PERCENT_INT;
}