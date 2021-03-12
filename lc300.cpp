#include "leetcode.h"

class Solution {
public:
    // 贪心+二分
    int lengthOfLIS(vector<int>& nums)
    {
        int s = nums.size();
        // tail[i]项表示长度为i的上升子序列的最小尾部值
        vector<int> tail(s+1, 0);
        int i = 0, j = 1;
        tail[j] = nums[0];
        /*
        数学归纳法：设tail[n][i]为nums的前n个元素组成的序列中长度为i的上升子序列中的最小
        尾部值，那么，考虑nums[n](nums的第n+1个元素), 若nums[n] > *(tail[n][tail[n].len()]),
        即nums[n]比tail[n]中最后的元素要大，那么，对于*(tail[n].end()-1)所对应的那个上升子序列，
        将nums[n]添加到序列末尾，则可以得到长度为tail[n].len()+1的子序列。 若
        nums[n] < *(tail[n][tail[n].len()]), 则用二分查找找到nums[n]在数组里的插入位置，
        设位置为i，则有tail[n][i] < nums[n] 
        */
        for (i = 0; i < s; i++) {
            if (nums[i] > tail[j]) {
                tail[++j] = nums[i];
            } else if (nums[i] < tail[j]) {
                int n = nums[i];
                int l = 1, h = j, mi, p = 0;
                while (l <= h) {
                    mi = (l + h) >> 1;
                    if (tail[mi] < n) {
                        p = mi;
                        l = mi + 1;
                    } else {
                        h = mi - 1;
                    }
                }
                tail[p + 1] = n;
            }
        }
        return j;
    }
};

int main()
{

    return 0;
}