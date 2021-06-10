#include "leetcode.h"

class Solution {
  public:
    int change(int amount, vector<int> &coins) {
        vector<int> temp(amount + 1, 0);
        temp[0] = 1;
        for (int c : coins) {
            for (int i = c; i <= amount; i++) {
                temp[i] += temp[i - c];
            }
        }
        return temp[amount];
    }
};
