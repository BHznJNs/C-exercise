#include <stdio.h>
// define a constant
#define DEFINED_NUM 5

int main() {
    printf("DEFINED_NUM: %d\n", DEFINED_NUM);

    // define a constant by `const`
    const int CONST_NUM = 10;
    printf("CONST_NUM: %d", CONST_NUM);
    return 0;
}