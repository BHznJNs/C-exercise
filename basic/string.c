#include <stdio.h>

int main() {
    // char a = 'a';
    // char b = 'b';
    // char string[] = { a, b, '\0' };
    // string[0] = 'c';
    char string[5];
    gets(string);
    printf("string: %s", string);

    return 0;
}