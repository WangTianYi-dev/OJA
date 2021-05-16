#include "leetcode.h"

class Solution {
public:
    // 贪心+二分
    int lengthOfLIS(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> d(n+1);
        d[1] = nums[0];
        int l = 1;
        for (int i = 0; i < n; i++) {
            int &t = nums[i];
            if (t > d[l]) {
                d[++l] = t;
            } else {
                int hi = l, lo = 1, p = 0;
                while (lo <= hi) {
                    int mi = (lo + hi) / 2;
                    if (d[mi] < t) {
                        p = mi;
                        lo = mi + 1;
                    } else {
                        hi = mi - 1;
                    }
                }
                d[p+1] = t;
            }
        }
        return l;
    }
};

int main()
{

    return 0;
}