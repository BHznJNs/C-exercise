#include <stdio.h>

int main() {
    int num1 = 1;
    // ternary operator || 三元运算符
    int num2 = (num1 == 1) ? 10 : 20;
    printf("%d\n", num2); // 10

    // if ... else if ... else ...
    num1 = 2;
    int num3;
    if (num1 == 1) {
        num3 = 10;
    } else if (num1 == 2) {
        num3 = 15;
    } else {
        num3 = 20;
    }
    printf("%d\n", num3); // 15

    // switch
    num1 = 3;
    int num4;
    switch (num1) {
        case 1:
            num4 = 10;
            break;
        case 2:
            num4 = 15;
            break;
        case 3:
            num4 = 20;
            break;
    }
    printf("%d", num4); // 20

    return 0;
}