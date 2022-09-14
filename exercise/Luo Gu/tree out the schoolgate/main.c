#include <stdio.h>
#include <string.h>

int main() {
    int road_length, area_num;
    // road_length = 500;
    // area_num = 3;
    scanf("%d %d", &road_length, &area_num);

    int tree_num = road_length + 1;

    int area_arr[area_num][2];
    for (int i=0; i<area_num; i++) {
        scanf("%d %d", &area_arr[i][0], &area_arr[i][1]);
    }
    // int area_arr[3][2] = {{150, 300}, {100, 200}, {470, 471}};

    int tree_arr[tree_num];
    memset(tree_arr, 0, sizeof(tree_arr)); // 初始化 数组
    
    for (int i=0; i<area_num; i++) {
        int* arr = area_arr[i];
        for (int j=arr[0]; j<arr[1] + 1; j++) {
            tree_arr[j] += 1;
        }
    }

    int remain_tree_num = 0;
    for (int i=0; i<tree_num; i++) {
        if (!tree_arr[i]) {
            remain_tree_num++;
        }
    }

    printf("%d", remain_tree_num);

    return 0;
}