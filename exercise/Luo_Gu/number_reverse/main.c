#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef short BOOL;
#define TRUE 1
#define FALSE 0

int abs(int num) {
    if (num >= 0) {
        return num;
    } else {
        return -num;
    }
}

char* reverse(char string[], BOOL is_negative) {
    int str_length = 0;
    for (int i=0; i<10; i++) {
        if (string[i]) {
            str_length += 1;
        } else {
            break;
        }
    }
    // char* new_str = (char *)calloc(str_length, sizeof(char));
    char* result_str = (char *)calloc(10, sizeof(char));
    int size = 0;
    if (is_negative) {
        result_str[0] = '-';
        size += 1;
    }

    for (int i=(str_length-1); i > -1; i--) {
        char current = string[i];

        if (current) {
            if (current != '0') {
                result_str[size] = current;
                size += 1;
            }
        } else {
            break;
        }
    }
    return result_str;
}

int main() {
    int test;
    scanf("%d", &test);
    // int test = -123;
    BOOL is_negative = FALSE;
    if (test < 0) {
        is_negative = TRUE;
        test = abs(test);
    }

    char string[10] = { '\0' };
    snprintf(string, 10, "%d", test);
    // printf("%s\n", string);
    // itoa(test, string, 10);
    char* new_str = reverse(string, is_negative);
    printf("%s", new_str);

    return 0;
}