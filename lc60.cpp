#include "leetcode.h"

// 逆康托展开
class Solution {
  public:
    string getPermutation(int n, int k) {
        static int fact[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
        bool in[10] = {false};
        int before = k - 1;
        string res = "";
        for (int step = n; step > 0; step--) {
            int quot = before / fact[step - 1];
            int resi = before % fact[step - 1];
            for (int i = 1; i < n + 1 && quot >= 0; i++) {
                if (!in[i]) {
                    if (quot == 0) {
                        in[i] = true;
                        res += i + '0';
                        break;
                    }
                    quot--;
                }
            }
            before = resi;
        }
        return res;
    }
};