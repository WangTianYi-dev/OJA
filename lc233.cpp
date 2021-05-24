#include "leetcode.h"

class Solution {
  public:
    int countDigitOne(int n) {
        int res = 0;
        int cur = n % 10, high = n / 10, weight = 1, low = 0;
        while (cur != 0 || high != 0) {
            if (cur == 0) {
                res += high * weight;
            } else if (cur == 1) {
                res += high * weight + low + 1;
            } else {
                res += (high + 1) * weight;
            }
            low += cur * weight;
            cur = high % 10, high /= 10, weight *= 10;
        }
        return res;
    }
};

int main() {
    Solution s;
    int i;
    while (1) {
        cin >> i;
        cout << s.countDigitOne(i) << endl;
    }
    return 0;
}