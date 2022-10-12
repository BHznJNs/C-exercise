#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> gridMap;

void traversal(vector<int> vec) {
    int size = vec.size();
    for (int i=0; i<size; i++) {
        cout << vec[i] << endl;
    }
}

int main() {
    // vector<int> vec({1});
    // cout << vec.size();
    // vec.push_back(1);
    // vec.push_back(2);
    // traversal(vec);

    vector<vector<int>> vec(4, vector<int>(4, 0));
    gridMap = vec;
    gridMap[0][0] = 10;
    cout << gridMap[0][0] << endl;
    return 0;
}