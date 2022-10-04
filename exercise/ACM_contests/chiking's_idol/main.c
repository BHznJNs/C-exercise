#include <stdio.h>

int main() {
    char name[] = "\\soup_god/";
    int name_length = 10;

    int n;
    scanf("%d", &n);

    for (int i=0; i<n; i++) {
        printf("%c", name[i % name_length]);
    }
    return 0;
}