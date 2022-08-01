#include <stdio.h>

/* return_type function_name (param) {
    // function body
} */
void print_helloworld() {
    printf("helloworld\n");
    
    return;
}

int max(int num1, int num2) {
    int result;

    if (num1 >= num2) {
        result = num1;
    } else {
        result = num2;
    }

    return result;
}

int main() {
    print_helloworld();

    int max_num = max(1, 2);
    printf("max_num: %d", max_num);
    return 0;
}
