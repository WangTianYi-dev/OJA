#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    unordered_map<int, int> mem;
    int dp(int k, int n) {
        if (mem.find(n * 100 + k) == mem.end()) {
            int ans;
            if (n == 1) {
                ans = 1;
            } else if (k == 1) {
                ans = n;
            } else {
                int temp = INT_MAX;
                for (int i = 1; i <= n; i++) {
                    int t = max(dp(k - 1, n - 1), dp(k, n - i));
                    temp = min(temp, t);
                }
                ans = temp + 1;
            }
            mem[n * 100 + k] = ans;
        }
        return mem[n * 100 + k];
    }

    int superEggDrop(int k, int n) {
        return dp(k, n);
    }
};
