#include "leetcode.h"

class Solution {
  public:
    int longestSubsequence(vector<int> &arr, int difference) {
        int n = arr.size();
        int stdd = 1e5;
        unordered_map<int, int> m;

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int a = arr[i] - difference, b = arr[i];
            if (m.find(a) == m.end()) {
                m[b] = 1;
            } else {
                if (m.find(b) == m.end()) {
                    m[b] = m[a] + 1;
                } else {
                    m[b] = max(m[b], m[a] + 1);
                }
            }
            ans = max(ans, m[b]);
        }
        return ans;
    }
};
