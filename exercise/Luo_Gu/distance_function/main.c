#include <stdio.h>
#include <math.h>

double distance_cal(double pos1[], double pos2[]) {
    double x1, x2, y1, y2;
    x1 = pos1[0]; y1 = pos1[1];
    x2 = pos2[0]; y2 = pos2[1];

    double xdiff_square = pow((x1 - x2), 2);
    double ydiff_square = pow((y1 - y2), 2);

    double distance = sqrt(xdiff_square + ydiff_square);
    return distance;
}

int main() {
    double pos1[2], pos2[2], pos3[2], distance[3];
    double sum = 0;
    int distance_length = 3;

    scanf("%lf %lf", &pos1[0], &pos1[1]);
    scanf("%lf %lf", &pos2[0], &pos2[1]);
    scanf("%lf %lf", &pos3[0], &pos3[1]);

    distance[0] = distance_cal(pos1, pos2);
    distance[1] = distance_cal(pos2, pos3);
    distance[2] = distance_cal(pos3, pos1);

    for (int i=0; i<distance_length; i++) {
        sum += distance[i];
    }
    printf("%0.2lf", sum);

    return 0;
}