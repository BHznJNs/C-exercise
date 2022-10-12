#include <iostream>
#include <vector>

using namespace std;

void printer(vector<vector<int>> vec) {
    int outerSize = vec.size();
    cout << "[";
    for (int i=0; i<outerSize; i++) {
        cout << "[";
        // vector<int> innerVec = vec[i];
        int innerSize = vec[i].size();
        for (int j=0; j<innerSize; j++) {
            cout << vec[i][j];
            if (j != innerSize - 1) {
                cout << ",";
            }
        }
        cout << "]";
    }
    cout << "]";
}

vector<int> dp(vector<int> &vec) {
    vector<int> result;
    int size = vec.size() + 1;

    for (int i=0; i<size; i++) {
        if (i == 0 || i == (size-1)) {
            result.push_back(1);
        } else {
            result.push_back(vec[i-1] + vec[i]);
        }
    }
    return result;
}

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;

        vector<int> current({1});
        result.push_back(current);
        for (int i=0; i<numRows-1; i++) {
            current = dp(current);
            result.push_back(current);
        }

        return result;
    }
};

int main() {
    Solution solu;
    printer(solu.generate(3));
    return 0;
}