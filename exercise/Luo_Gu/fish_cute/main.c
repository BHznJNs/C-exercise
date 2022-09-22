#include <stdio.h>
#include <stdlib.h>

int main() {
    int *pool = (int *)malloc(0); // 鱼池
    int *smaller_num_arr = (int *)malloc(0); // 比自己不可爱的数量的数组

    // 获取 鱼 的数量
    int num;
    scanf("%d", &num);

    // 将 鱼 加入 鱼池
    for (int i=0; i<num; i++) {
        int fish;
        scanf("%d", &fish);

        pool = (int *)realloc(pool, sizeof(int));
        smaller_num_arr = (int *)realloc(smaller_num_arr, sizeof(int));
        pool[i] = fish;

        int smaller_num = 0;
        for (int j=0; j<i; j++) {
            int before_fish = pool[j];
            if (before_fish < fish) {
                smaller_num++;
            }
        }
        smaller_num_arr[i] = smaller_num;
    }
    for (int i=0; i<num; i++) {
        printf("%d", smaller_num_arr[i]);
        if (i != (num - 1)) {
            printf(" ");
        }
    }

    free(pool); free(smaller_num_arr);
    return 0;
}