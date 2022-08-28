#include <stdio.h>

int main() {
    FILE *fp_write = NULL;
    FILE *fp_read = NULL;
    
    // 写入文件
    fp_write = fopen("test", "w");
    fputs("test content", fp_write);
    fclose(fp_write);

    // 读取文件
    fp_read = fopen("test", "r");
    // 读取单个字符
    char single_char = fgetc(fp_read);
    printf("single_char: %c\n", single_char);
    // 读取多个字符
    char content1[20];
    fgets(content1, 20, fp_read);
    printf("file_content1: %s\n", content1);
    // fscanf 的使用
    char str1[5], str2[5];
    fscanf(fp_read, "%s %s", str1, str2);
    printf("str1: %s\nstr2: %s\n", str1, str2);

    return 0;
}