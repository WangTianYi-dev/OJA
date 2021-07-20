#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    unordered_map<int, int> mem;

    int hash(int k, int n) {
        return n * 100 + k;
    }

    void dp(int k, int n) {
        int f = hash(k, n);
        if (mem.find(f) != mem.end()) {
            return;
        }
        if (k <= 1) {
            mem[f] = n;
            return;
        }
        if (n <= 1) {
            mem[f] = n;
            return;
        }
        int mn = INT_MAX;
        for (int i = 1; i <= n; i++) {
            dp(k - 1, i - 1);
            dp(k, n - i);
            mn = min(mn, max(mem[hash(k - 1, i - 1)], mem[hash(k, n - i)]));
        }
        mem[f] = mn + 1;
    }

    int superEggDrop(int k, int n) {
        dp(k, n);
        return mem[n * 100 + k];
    }
};