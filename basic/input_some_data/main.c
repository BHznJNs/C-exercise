#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

void copy_string(char* from, int from_len, char* target) {
    for (int i=0; i<from_len; i++) {
        target[i] = from[i];
    }
    target[from_len] = '\0';
}

int main() {
    char* str_arr[MAX_LENGTH];
    int str_arr_len = 0;
    int i = 0;

    while (i < MAX_LENGTH) {
        char string[1000];
        gets(string);

        if (strcmp(string, "") == 0) {
            // 若输入为空字符串
            break;
        } else {
            int str_length = strlen(string);
            char* insert_str = (char *)malloc(str_length * sizeof(char));
            copy_string(string, str_length, insert_str);

            str_arr[i] = insert_str;
            str_arr_len += 1;
            i += 1;
        }
    }
    for (int i=0; i<str_arr_len; i++) {
        puts(str_arr[i]);
        free(str_arr[i]);
    }
    return 0;
}