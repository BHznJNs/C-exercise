#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int* pr = NULL;

    printf("要输入的元素个数：");
    scanf("%d", &n);

    pr = (int*)calloc(n, sizeof(int));
    
    printf("输入 %d 个数字：\n",n);
    for (int i=0; i<n; i++) {
        scanf("%d", &pr[i]);
    }
    printf("pr[0]: %d\npr[1] %d\n", pr[0], pr[1]);
    free(pr);

    return 0;
}