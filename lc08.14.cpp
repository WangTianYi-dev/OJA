#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countEval(string s, int result) {
        int len = s.size();
        //定义动态规划数组：dp[i][j][0]:表示s中区间[i,j]间结果为0的组合情况。
        //                 dp[i][j][1]:表示s中区间[i,j]间结果为1的组合情况
        vector<vector<vector<int>>> dp(len, vector<vector<int>>(len, vector<int>(2, 0)));
        //初始化dp数组
        for (int i = 0; i < len; i += 2) {
            int temp = 0;
            if (s[i] == '1') {
                temp = 1;
            }
            dp[i][i][0] = 1 - temp;
            dp[i][i][1] = temp;
        }
        //动态规划转移方程，由前往后遍历
        for (int gap = 0; gap < len; gap += 2) {
            for (int i = 0; i + gap < len; i += 2) {
                for (int j = i + 1; j < i + gap; j += 2) {
                    int l0 = dp[i][j - 1][0];
                    int l1 = dp[i][j - 1][1];
                    int r0 = dp[j + 1][i + gap][0];
                    int r1 = dp[j + 1][i + gap][1];
                    if (s[j] == '&') {
                        dp[i][i + gap][0] += l0 * (r0 + r1) + l1 * r0;
                        dp[i][i + gap][1] += l1 * r1;
                    }
                    if (s[j] == '|') {
                        dp[i][i + gap][0] += l0 * r0;
                        dp[i][i + gap][1] += l1 * (r0 + r1) + l0 * r1;
                    }
                    if (s[j] == '^') {
                        dp[i][i + gap][0] += l0 * r0 + l1 * r1;
                        dp[i][i + gap][1] += l0 * r1 + l1 * r0;
                    }
                }
            }
        }
        //返回最终的结果
        return dp[0][len - 1][result];
    }
};