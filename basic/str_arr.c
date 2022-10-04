#include <stdio.h>

#define LENGTH 4

int main() {
    char* str_arr[LENGTH];
    for (int i=0; i<LENGTH; i++) {
        gets(str_arr[i]);
        // scanf("%s", str_arr[i]);
        // printf("%s\n", str_arr[i]);
    }
    // str_arr[0] = "123";
    // str_arr[1] = "456";

    for (int i=0; i<LENGTH; i++) {
        printf("%s\n", str_arr[i]);
    }
    return 0;
}