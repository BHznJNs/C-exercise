#include <stdio.h>

int main() {
    int random_num;
    scanf("%d", &random_num);

    int random_arr[random_num];
    for (int i=0; i<random_num; i++) {
        scanf("%d", &random_arr[i]);
    }

    int hashmap[1001];
    // 初始化哈希表
    for (int i=0; i<1001; i++) {
        hashmap[i] = 0;
    }
    for (int i=0; i<random_num; i++) {
        int value = random_arr[i];
        hashmap[value] += 1;
    }

    int target_arr[random_num];
    int target_arr_length = 0;

    for (int i=0; i<1001; i++) {
        if (hashmap[i]) {
            target_arr[target_arr_length] = i;
            target_arr_length++;
        }
    }

    printf("%d\n", target_arr_length);
    for (int i=0; i<target_arr_length; i++) {
        printf("%d", target_arr[i]);
        if (i != (target_arr_length - 1)) {
            printf(" ");
        }
    }

    return 0;
}