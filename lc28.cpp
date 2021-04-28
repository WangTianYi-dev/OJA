#include "leetcode.h"
class Solution {
public:
    int strStr(string haystack, string needle)
    {
        if (needle.empty()) {
            return 0;
        }
        int fr = 0, ls = needle.size(), le = needle.size();
        int ln = haystack.size();
        while (ls < ln) {
            if (haystack.substr(fr, le) == needle) {
                return fr;
            }
            fr++, le++;
        }
        return 0;
    }
};