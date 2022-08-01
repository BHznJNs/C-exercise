#include <stdio.h>
#include <stdlib.h>

int main() {
    enum DAY {
        MON=1, TUE, WED, THU, FRI, SAT, SUN
    } day;
    printf("day: %d", day); // 0
    printf("MON: %d", MON); // 1

    /* ---------- */

    enum COLORS {
        red=1, green, blue
    } favorite_color;

    printf("请输入你喜欢的颜色: (1. red, 2. green, 3. blue): ");
    scanf("%u", &favorite_color);
    printf("favorite_color: %d\n", favorite_color);

    switch (favorite_color) {
    case red:
        printf("Your favorite color is red.\n");
        break;
    case green:
        printf("Your favorite color is green.\n");
        break;
    case blue:
        printf("Your favorite color is blue.\n");
        break;
    };
    return 0;
}