#include "leetcode.h"

class Solution {
  public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        int r = matrix.size();
        if (r == 0) {
            return 0;
        }
        int c = matrix[0].size();
        vector<vector<int>> leftSize(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (matrix[i][j] == '1') {
                    leftSize[i][j] = (j == 0 ? 0 : leftSize[i][j - 1]) + 1;
                }
            }
        }

        int ret = 0;
        for (int j = 0; j < c; j++) {
            vector<int> upTo(r, 0), downTo(r, 0);
            stack<int> st;
            for (int i = 0; i < r; i++) {
                while (!st.empty() && leftSize[st.top()][j] >= leftSize[i][j]) {
                    st.pop();
                }
                upTo[i] = st.empty() ? -1 : st.top();
                st.push(i);
            }
            st = stack<int>();
            for (int i = r - 1; i >= 0; i--) {
                while (!st.empty() && leftSize[st.top()][j] >= leftSize[i][j]) {
                    st.pop();
                }
                downTo[i] = st.empty() ? r : st.top();
                st.push(i);
            }
            for (int i = 0; i < r; i++) {
                int height = downTo[i] - upTo[i] - 1;
                int width = leftSize[i][j];
                ret = max(ret, height * width);
            }
        }
        return ret;
    }
};
