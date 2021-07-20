#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    static constexpr int mod = 1000000007;

    int minAbsoluteSumDiff(vector<int> &nums1, vector<int> &nums2) {
        vector<int> rec(nums1);
        sort(rec.begin(), rec.end());
        int n = nums1.size();
        int sum = 0, maxdif = 0;
        for (int i = 0; i < n; i++) {
            int dif = abs(nums1[i] - nums2[i]);
            sum = (sum + dif) % mod;
            int j = upper_bound(rec.begin(), rec.end(), nums2[i]) - rec.begin();
            if (j < n) {
                maxdif = max(maxdif, dif - (rec[j] - nums2[i]));
            }
            if (j > 0) {
                maxdif = max(maxdif, dif - (nums2[i] - rec[j - 1]));
            }
        }
        return (sum - maxdif + mod) % mod;
    }
};