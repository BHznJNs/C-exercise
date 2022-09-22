#include <stdio.h>

int get_factorial(int num) {
    int current = num;
    int result = num;
    while (current > 1) {
        current--;
        result *= current;
    }
    return result;
}

int main() {
    int input;
    scanf("%d", &input);

    unsigned long sum;
    while (input >= 1) {
        sum += get_factorial(input);
        input--;
    }
    printf("%llu", sum);

    return 0;
}