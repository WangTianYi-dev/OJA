#include "leetcode.h"

class Solution {
  public:
    int kthLargestValue(vector<vector<int>> &matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> mt(m, vector<int>(n, 0));
        mt[0][0] = matrix[0][0];
        for (int i = 1; i < m; i++) {
            mt[i][0] = mt[i - 1][0] ^ matrix[i][0];
        }
        for (int j = 1; j < n; j++) {
            mt[0][j] = mt[0][j - 1] ^ matrix[0][j];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                mt[i][j] = mt[i][j - 1] ^ mt[i - 1][j] ^ matrix[i][j] ^ mt[i - 1][j - 1];
                // cout << mt[i][j] << ' ';
            }
            // cout << endl;
        }

        vector<int> v;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << mt[i][j] << ' ';
                v.push_back(mt[i][j]);
            }
            cout << endl;
        }
        nth_element(v.begin(), v.end() - k, v.end());
        return *(v.end() - k);
    }
};

int main() {
    vector<vector<int>> v{{10, 9, 5}, {2, 0, 4}, {1, 0, 9}, {3, 4, 8}};
    Solution s;
    cout << s.kthLargestValue(v, 10);
}