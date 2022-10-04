#include <stdio.h>
#include <stdlib.h>

int n;
#define MAX_INPUT 80001

//        目标字符串数组                     插入数量  插入的字符，1 || 0
void push(char string[], int* str_length, int num, char insert_char) {
    for (int i=0; i<num; i++) {
        string[*str_length] = insert_char;
        *str_length += 1;

        if ((*str_length + 1) % (n + 1) == 0) {
            string[*str_length] = '\n';
            *str_length += 1;
        }
    }
}

int main() {
    // int n = 7; // 行 / 列 字符个数
    // int data[] = {3, 1, 6, 1, 6, 4, 3, 1, 6, 1, 6, 1, 3, 7};
    // int data_length = 14;

    char input[MAX_INPUT];
    gets(input);
    
    int* data = (int *)calloc(40000, sizeof(int));
    // int data[40000];
    int data_length = 0;

    for (int i=0; i<MAX_INPUT; i++) {
        char element = input[i];
        if (!element) {
            break;
        }
        if (element != ' ') {
            int num = element-'0';
            if (i == 0) {
                // 首个数字
                n = num;
            } else {
                data[data_length] = num;
                data_length += 1;
            }
        }
    }

    char result[n * n + n];
    int result_length = 0;

    for (int i=0; i<data_length; i++) {
        int num = data[i];
        if (i % 2) {
            // 奇数
            push(result, &result_length, num, '1');
        } else {
            // 偶数
            push(result, &result_length, num, '0');
        }
    }
    push(result, &result_length, 1, '\0');

    printf("%s", result);

    free(data);
    return 0;
}