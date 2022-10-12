#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> gridMap;

int min(int a, int b) {
    if (a <= b) {
        return a;
    } else {
        return b;
    }
}

int dp(vector<vector<int>>& grid, int x, int y) {
    int value = grid[x][y];
    int mapValue = gridMap[x][y];

    if (mapValue) {
        return mapValue;
    }

    int result;
    if (x == 0 && y == 0) {
        result = grid[0][0];
    } else if (x == 0) {
        result = dp(grid, x, y-1) + value;
    } else if (y == 0) {
        result = dp(grid, x-1, y) + value;
    } else {
        result = min(dp(grid, x-1, y), dp(grid, x, y-1)) + value;
    }
    gridMap[x][y] = result;
    return result;
}

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rowNum = grid.size();
        int colNum = grid[0].size();

        vector<vector<int>> vec(rowNum, vector<int>(colNum, 0));
        gridMap = vec;
        gridMap[0][0] = grid[0][0];

        return dp(grid, rowNum-1, colNum-1);
    }
};

int main() {
    vector<vector<int>> input({{1,3,1},{1,5,1},{4,2,1}});
    Solution solu;
    solu.minPathSum(input);
    return 0;
}