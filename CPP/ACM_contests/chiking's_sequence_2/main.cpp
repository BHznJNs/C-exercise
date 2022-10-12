#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    long long times = 0;

    for (int i=0; i<n; i++) {
        if (!i) {
            continue;
        }
        int prevNum = arr[i-1];

        while (prevNum == arr[i]) {
            arr[i] += 1;
            times += 1;
        }
    }

    cout << times << endl;
    return 0;
}