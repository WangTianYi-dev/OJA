#include "leetcode.h"

class Solution {
  public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int dr[] = {0, 1, 0, -1}, dc[] = {1, 0, -1, 0};
        int step = 1, passed = 0;
        vector<vector<int>> res(rows * cols);
        int curR = rStart, curC = cStart;
        auto inGrid = [&](int row, int col) {
            return row >= 0 && col >= 0 && row < rows && col < cols;
        };
        int dir = 0;
        int i = 0;
        while (passed < rows * cols) {
            printf("%d, %d\n", curR, curC);
            if (inGrid(curR, curC)) {
                passed++;
                res.push_back(vector<int>{curR, curC});
            }
            curR += dr[dir], curC += dc[dir];
            i++;
            if (i == step) {
                i = 0;
                dir = (dir + 1) % 4;
                if (dir % 2 == 0) {
                    step++;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    s.spiralMatrixIII(1, 4, 0, 0);
    return 0;
}