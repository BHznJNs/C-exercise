#include <stdio.h>

int fibonacci() {
    static int a = 1;
    static int b = 1;


    printf("a: %d\n", a);
    printf("b: %d\n", b);

    const int temp = a + b;
    a = b; b = temp;

    if (b > 10000) {
        return b;
    }
    fibonacci();
}

int main() {
    printf("last: %d\n", fibonacci());
    return 0;
}