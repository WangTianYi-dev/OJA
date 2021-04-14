#include "leetcode.h"
class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        int upBound = INT_MAX / 10;
        int downBound = INT_MIN / 10;
        while (x) {
            int pop = x % 10;
            x /= 10;
            if (rev > upBound || (rev == upBound && pop > 7)) {
                return 0;
            }
            if (rev < downBound || (rev == downBound && pop < -8)) {
                return 0;
            }
            rev *= 10;
            rev += pop;
        }
        return 0;
    }
};