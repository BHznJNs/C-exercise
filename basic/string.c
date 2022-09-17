#include <stdio.h>

int main() {
    char a = 'a';
    char b = 'b';
    char string[] = { a, b, '\0' };
    string[0] = 'c';
    printf("string: %s", string);

    return 0;
}