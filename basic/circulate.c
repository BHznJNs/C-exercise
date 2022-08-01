#include <stdio.h>

int main() {
    // 循环次数
    const int max_num = 10;
    // 经典 for 循环
    for (int i = 0;i < max_num; i++) {
        printf("helloworld");
        printf("%d\n", i);
    }

    // for 无限循环
    for ( ; ; ) {
        printf("helloworld");
    }


    // while 无限循环
    while (1) {
        printf("helloworld");
    }

    do {
        // 先执行一次
        // 后续根据 while 中条件判断执行 do 中语句
        printf("helloworld");
    } while (0);

    return 0;
}