#include "leetcode.h"
class Solution {
  public:
    string largestNumber(vector<int> &cost, int target) {
        vector<int> lens(target + 1, INT_MIN);
        lens[0] = 0;
        for (auto c : cost) {
            for (int j = c; j <= target; j++) {
                lens[j] = max(lens[j], lens[j - c] + 1);
            }
        }
        if (lens[target] < 0) {
            return "0";
        }
        string res;
        for (int i = 9, j = target; i >= 1; i--) {
            // lens[j - c] + 1 == lens[j] means success
            for (int c = cost[i - 1]; j >= c && lens[j - c] + 1 == lens[j]; j -= c) {
                res += '0' + i;
            }
        }
        return res;
    }
};
