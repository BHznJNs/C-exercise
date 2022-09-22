#include <stdio.h>

void get_diff(int start[], int end[], int target[]) {
    int hour1, hour2;
    hour1 = start[0];
    hour2 = end[0];

    int minute1, minute2;
    minute1 = start[1];
    minute2 = end[1];

    int minute_diff = minute2 - minute1;
    if (minute_diff < 0) {
        minute_diff = 60 + minute_diff;
        hour2--;
    }

    int hour_diff = hour2 - hour1;

    target[0] = hour_diff;
    target[1] = minute_diff;
}

int main() {
    int start_time[2];
    int  end_time[2] ;
    scanf("%d %d %d %d", &start_time[0], &start_time[1], &end_time[0], &end_time[1]);
    int diff[2];

    get_diff(start_time, end_time, diff);
    printf("%d %d", diff[0], diff[1]);
    return 0;
}