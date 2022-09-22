#include <stdio.h>

int main() {
    int size;
    scanf("%d", &size);

    int min;
    
    for (int i=0; i<size; i++) {
        int num;
        scanf("%d", &num);
        if (i) {
            if (num < min) {
                min = num;
            }
        } else {
            min = num;
        }
    }

    printf("%d", min);
    return 0;
}