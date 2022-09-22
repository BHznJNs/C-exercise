#include <stdio.h>

int main() {
    char input;
    scanf("%c", &input);

    char target = input - 32;
    printf("%c", target);
    return 0;
}