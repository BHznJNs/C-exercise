#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a + b < c) c = a + b;
    if (a > c) a = c;
    if (b > c) b = c;

    int group_num = 0;
    for (int x=0; x<a+1; x++) {
        for (int y=0; y<b+1; y++) {            
            int sum = x + y;
            if (sum >= 0 && sum <= c) {
                group_num++;
            } else {
                break;
            }
        }
    }
    printf("%d", group_num);
    return 0;
}