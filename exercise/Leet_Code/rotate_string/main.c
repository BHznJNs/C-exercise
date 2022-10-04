#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 旋转字符串
char * rotate(char * s, int length) {
    char* result = (char *)calloc(length + 1, sizeof(char));

    for (int i=0; i<length; i++) {
        if (i < length - 1) {
            result[i] = s[i + 1];
        } else {
            result[i] = s[0];
        }
    }
    return result;
}

// 判断
bool rotate_string(char * s, char * goal) {
    int s_length = strlen(s);
    char* rotated = NULL;
    for (int i=0; i<s_length; i++) {
        if (!rotated) {
            rotated = rotate(s, s_length);
        } else {
            rotated = rotate(rotated, s_length);
        }
        // printf("%s\n", rotated);

        if (!strcmp(rotated, goal)) {
            return true;
        }
    }
    return false;
}

int main() {
    char s[] = "abcde";
    char goal[] = "abced";

    printf("%d", rotate_string(s, goal));
    return 0;
}