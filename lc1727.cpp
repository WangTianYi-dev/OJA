#include "leetcode.h"
class Solution {
  public:
    int largestSubmatrix(vector<vector<int>> matrix) {
        int res = 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> heights(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                //用来记录当前行以及以上行的每列连续1的个数
                heights[j] = matrix[i][j] == 0 ? 0 : heights[j] + 1;
            }
            //防止对heights数组污染
            vector<int> temp = heights;
            sort(temp.begin(), temp.end());
            //枚举每个高度的矩形并取最大值
            for (int j = 0; j < n; j++)
                res = max(res, temp[j] * (n - j));
        }
        return res;
    }
};
