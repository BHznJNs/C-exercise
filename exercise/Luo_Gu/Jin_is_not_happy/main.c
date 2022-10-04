#include <stdio.h>

#define MAX 8

int main() {
    int week[7][2];
    for (int i=0; i<7; i++) {
        scanf("%d %d", &week[i][0], &week[i][1]);
    }

    int most_unhappy = 0;
    int most_unhappy_extent = 0;
    for (int i=0; i<7; i++) {
        int* day = week[i];
        int sum = day[0] + day[1];

        if (sum > MAX && sum > most_unhappy_extent) {
            most_unhappy = i + 1;
            most_unhappy_extent = sum;
        } else if (sum > MAX && sum <= most_unhappy_extent) {
            // 
        } else {
            // 
        }
    }
    printf("%d", most_unhappy);

    return 0;
}