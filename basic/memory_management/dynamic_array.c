#include <stdio.h>
#include <stdlib.h>

struct {
    int* pr;
    int length;
} dynamic_array;

void init() {
    dynamic_array.pr = (int *)calloc(0, sizeof(int));
    dynamic_array.length = 0;
}

void push(int value) {
    const int length = dynamic_array.length;
    int* pr = dynamic_array.pr;
    pr = (int *)realloc(pr, (length+1)*sizeof(int));
    pr[length] = value;
    dynamic_array.length += 1;
}

int main() {
    init();
    push(1);
    push(2);
    for (int i=0; i<dynamic_array.length; i++) {
        printf("%d\n", dynamic_array.pr[i]);
    }
    return 0;
}