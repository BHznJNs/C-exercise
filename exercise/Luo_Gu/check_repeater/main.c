#include <stdio.h>

typedef short BOOL;
#define TRUE 1
#define FALSE 0

BOOL check_repeated(char arr[]) {
    char last_letter = '\0';

    for (int i=0; i<1001; i++) {
        char current = arr[i];
        if (!last_letter) {
            last_letter = current;
            continue;
        }
        if (current == last_letter) {
            return TRUE;
        } else {
            last_letter = current;
        }
    }
    return FALSE;
}

int main() {
    int n;
    scanf("%d", &n);

    BOOL is_repeated_arr[n];
    for (int i=0; i<n; i++) {
        char arr[1001] = { '\0' };
        scanf("%s", &arr);

        is_repeated_arr[i] = check_repeated(arr);
    }
    for (int i=0; i<n; i++) {
        BOOL is_repeated_el = is_repeated_arr[i];
        if (is_repeated_el) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}