#include <iostream>

using namespace std;

/*
    0 1 2

    1 3 4
    1 2 3 4

    1 4 5
    1 2 3 4 5
*/

int calculate(int arr[], int length) {
    int sum = 0;
    int index = 1;

    cout << sum << " " << index << endl;
    for (int i=0; i<length; i++) {
        int current = arr[i];
        if (current < i+1) {
            index += 1;
            continue;
        }
        int diff = current - index;
        if (!diff) {
            // diff == 0
            index += 1;
        } else {
            sum += diff;
            index = current + 1;
        }
        cout << sum << " " << index << endl;
    }

    return sum;
}

int main() {
    int t; cin >> t;
    int sum[t];

    for (int i=0; i<t; i++) {
        int n; cin >> n;

        int arr[n];
        for (int j=0; j<n; j++) {
            cin >> arr[j];
        }
        sum[i] = calculate(arr, n);
    }

    for (int i=0; i<t; i++) {
        cout << sum[i] << endl;
    }
    return 0;
}