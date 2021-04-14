#include "leetcode.h"
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;
        int t = 0;
        while (t < x) {
            t *= 10;
            t += x % 10;
            x /= 10;
        }
        return t == x || t / 10 == x;
    }
};