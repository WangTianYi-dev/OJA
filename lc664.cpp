#include "leetcode.h"

class Solution {
  public:
    int strangePrinter(string str) {
        string s;
        int l = str.size();
        char t = -1, c = 0;
        for (int i = 0; i < l; i++) {
            c = str[i];
            if (t == c)
                continue;
            s += c;
            t = c;
        }
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = n - 1; i >= 0; i--) {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i][j - 1];
                } else {
                    int Min = INT_MAX;
                    for (int k = i; k < j; k++) {
                        Min = min(Min, dp[i][k] + dp[k + 1][j]);
                    }
                    dp[i][j] = Min;
                }
            }
        }
        return dp[0][n - 1];
    }
};
