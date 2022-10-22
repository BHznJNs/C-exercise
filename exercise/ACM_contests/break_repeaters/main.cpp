#include <iostream>
#include <cstring>

using namespace std;

bool check(char str[]) {
    char prev;
    for (int i=0; i<1001; i++) {
        char current = str[i];
        if (!i) {
            prev = current;
            continue;
        }
        if (!current) {
            break;
        }
        if (prev == current) {
            return true;
        }
        prev = current;
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    char strArr[n][1001];
    for (int i=0; i<n; i++) {
        cin >> strArr[i];
    }
    for (int i=0; i<n; i++) {
        char* string = strArr[i];
        bool isRepeated = check(string);
        if (isRepeated) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}