#include <stdio.h>

int main() {
    const int NUM_ARRAY[] = {1, 3, 5, 7};
    const int LEN = 4;

    for (int i=0; i<LEN; i++) {
        const int ITEM_1 = NUM_ARRAY[i];

        for (int j=0; j<LEN; j++) {
            const int ITEM_2 = NUM_ARRAY[j];

            for (int k=0; k<LEN; k++) {
                const int ITEM_3 = NUM_ARRAY[k];

                printf("%d, %d, %d\n", ITEM_1, ITEM_2, ITEM_3);
            }
        }
    }
    /*
        1, 1, 1
        1, 1, 3
        1, 1, 5
        1, 1, 7
        1, 3, 1
        1, 3, 3
        1, 3, 5
        1, 3, 7
        1, 5, 1
        1, 5, 3
        1, 5, 5
        1, 5, 7
        1, 7, 1
        1, 7, 3
        1, 7, 5
        1, 7, 7
        3, 1, 1
        3, 1, 3
        3, 1, 5
        3, 1, 7
        3, 3, 1
        3, 3, 3
        3, 3, 5
        3, 3, 7
        3, 5, 1
        3, 5, 3
        3, 5, 5
        3, 5, 7
        3, 7, 1
        3, 7, 3
        3, 7, 5
        3, 7, 7
        5, 1, 1
        5, 1, 3
        5, 1, 5
        5, 1, 7
        5, 3, 1
        5, 3, 3
        5, 3, 5
        5, 3, 7
        5, 5, 1
        5, 5, 3
        5, 5, 5
        5, 5, 7
        5, 7, 1
        5, 7, 3
        5, 7, 5
        5, 7, 7
        7, 1, 1
        7, 1, 3
        7, 1, 5
        7, 1, 7
        7, 3, 1
        7, 3, 3
        7, 3, 5
        7, 3, 7
        7, 5, 1
        7, 5, 3
        7, 5, 5
        7, 5, 7
        7, 7, 1
        7, 7, 3
        7, 7, 5
        7, 7, 7
    */
    return 0;
}