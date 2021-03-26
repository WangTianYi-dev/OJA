#include "leetcode.h"

class Solution {
public:
    pair<int, int> expand(const string& s, int l, int r)
    {
        int n = s.size();
        while (l >= 0 && r < n && s[l] == s[r]) {
            l--;
            r++;
        }
        return { l + 1, r - 1 };
    }
    string longestPalindrome(string s)
    {
        int n = s.size();
        int l = 0, r = 0;
        for (int i = 0; i < n; i++) {
            auto [left1, right1] = expand(s, i, i);
            auto [left2, right2] = expand(s, i, i + 1);
            if (right1 - left1 > r - l) {
                r = right1;
                l = left1;
            }
            if (right2 - left2 > r - l) {
                r = right2;
                l = left2;
            }
        }
        return s.substr(l, l - r + 1);
    }
};

int main()
{
    Solution s;
    string str = "babad";
    cout << s.longestPalindrome(str) << endl;
    return 0;
}