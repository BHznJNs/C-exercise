#include <stdio.h>
#include <string.h>

// #define MAX_STR_LEN 100

int maxRepeating(char * sequence, char * word){
    int max_repeated_num = 0;
    int current_repeated_num = 0;

    int word_len = strlen(word);

    int step = 0;
    for (int i=0; i<100; i++) {
        char current = sequence[i];
        if (!current) { // 取到空字符
            break;
        }

        if (current == word[step]) {
            step += 1;
            if (step == word_len) {
                current_repeated_num += 1;
                step = 0;
            }
        } else { // 中断
            step = 0;
            if (current_repeated_num > max_repeated_num) {
                max_repeated_num = current_repeated_num;
                current_repeated_num = 0;
            }
        }
    }
    if (current_repeated_num > max_repeated_num) {
        max_repeated_num = current_repeated_num;
        current_repeated_num = 0;
    }

    return max_repeated_num;
}

int main() {
    char sequence[100] = "aaabaaaabaaabaaaabaaaabaaaabaaaabaaaaba";
    char word[100] = "aaaba";

    printf("%d", maxRepeating(sequence, word));

    return 0;
}