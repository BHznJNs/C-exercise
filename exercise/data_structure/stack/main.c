#include <stdio.h>
#include <stdlib.h>

struct {
    int* data;

    int* top;
    int size;
} Stack;

void Stack_init() {
    Stack.data = (int *)calloc(0, sizeof(int));
    Stack.top = NULL;
    Stack.size = 0;
}

void Stack_push(int value) {
    Stack.data = (int *)realloc(Stack.data, sizeof(int));
    Stack.data[Stack.size] = value;
    Stack.top = &Stack.data[Stack.size];
    Stack.size++;
}

int Stack_pop() {
    int return_value = *Stack.top;
    Stack.data[Stack.size - 1] = 0; // 将原来的 top 初始化为 0
    Stack.size--;
    Stack.top = &Stack.data[Stack.size - 1];
    return return_value;
}

int main() {
    Stack_init();
    Stack_push(1);
    Stack_push(10);
    int value = Stack_pop();
    printf("%d\n", *(Stack.top + 1));
    return 0;
}