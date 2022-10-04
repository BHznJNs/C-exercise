#include <stdio.h>
#include <string.h>

int check(char string[]) {
    int parentheses = 0;
    int single_parenthsis = 0;

    for (int i=0; i<100000; i++) {
        char current = string[i];
        if (!current) {
            break;
        }

        if (current == '(') {
            single_parenthsis += 1;
        } else { // current == ')'
            if (single_parenthsis) {
                single_parenthsis -= 1;
                parentheses += 1;
            } else {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int t;
    scanf("%d", &t);

    int is_match_arr[t]; // 字符串中括号是否匹配
    for (int i=0; i<t; i++) {
        char string[100000] = { '\0' };
        scanf("%s", &string);
        is_match_arr[i] = check(string);
    }
    for (int i=0; i<t; i++) {
        if (is_match_arr[i]) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}