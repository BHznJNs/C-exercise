#include <stdio.h>
#include <string.h>

#define LOWER 97
#define UPPER 122
#define MAX_STR_LENGTH 50

void convert(char* letter, int n) {
    int value = *letter;
    if (value + n <= UPPER) {
        *letter += n;
    } else if (n == 26) {
        *letter = value;
    } else if (value + n > UPPER) {
        *letter = (LOWER - 1) + (value + n - UPPER);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    char password[MAX_STR_LENGTH] = {'\0'};
    scanf("%s", &password);

    for (int i=0; i<MAX_STR_LENGTH; i++) {
        if (password[i]) {
            convert(&password[i], n);
        }
    }

    printf("%s", password);
    return 0;
}