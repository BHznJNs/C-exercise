#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

ll sum(ll arr[], int length) {
    ll sum = 0;
    for (int i=0; i<length; i++) {
        sum += arr[i];
    }
    return sum;
}

void calculate(ll arr[], int length, ll* arr_sum, int bool, int query) {
    if (bool == 1) {
        for (int i=0; i<length; i++) {
            if (arr[i] % 2 != 0) {
                // 偶数
                arr[i] += query;
                *arr_sum += query;
            }
        }
    } else {
        for (int i=0; i<length; i++) {
            if (arr[i] % 2 == 0) {
                // 奇数
                arr[i] += query;
                *arr_sum += query;
            }
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);

    ll* result[t];
    for (int i=0; i<t; i++) {
        int length, query_num;
        scanf("%d %d", &length, &query_num);
        ll* sum_arr = (ll *)calloc(query_num+1, sizeof(ll));
        sum_arr[0] = (ll)query_num;

        ll arr[length];
        for (int j=0; j<length; j++) {
            scanf("%d", &arr[j]);
        }
        ll arr_sum = sum(arr, length);

        for (int j=0; j<query_num; j++) {
            int bool, query;
            scanf("%d %d", &bool, &query);
            calculate(arr, length, &arr_sum, bool, query);
            sum_arr[j+1] = arr_sum;
        }
        result[i] = sum_arr;
    }

    for (int i=0; i<t; i++) {
        long long* arr = result[i];
        long long length = arr[0];
        for (int j=1; j<length+1; j++) {
            printf("%lld\n", arr[j]);
        }
    }
    return 0;
}