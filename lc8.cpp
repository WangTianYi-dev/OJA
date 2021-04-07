#include "leetcode.h"
class Solution {
public:
    int myAtoi(string s) {
        int i = 0, l = s.length(), sgn = 1;
        while (i < l && s[i] == ' ') {
            i++;
        }
        if (s[i] == '-') {
            sgn = -1;
            i++;
        } else if (s[i] == '+') {
            i++;
        }
        int64_t res = 0;
        int64_t limit = (sgn == 1) ? abs(INT_MAX) : abs((int64_t)INT_MIN);
        bool exceed = false;
        while (i < l && isdigit(s[i]) && !exceed) {
            int t = s[i] - '0';
            res *= 10;
            res += t;
            if (res > limit) {
                exceed = true;
            }
            i++;
        }
        if (exceed) {
            return sgn == 1 ? INT_MAX : INT_MIN;
        }
        return sgn * res;
    }
};


int main()
{
    string s = "42";
    Solution sol;
    cout << sol.myAtoi(s) << endl;
}