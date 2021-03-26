#include "leetcode.h"

int lengthOfLongestSubstring(string s)
{
    unordered_set<char> oc;
    int n = s.size();
    int ans = 0;
    int j = -1;
    for (int i = 0; i < n; i++) {
        if (i) {
            oc.erase(s[i - 1]);
        }
        int num = 0;

        while (j < n - 1 && !oc.count(s[j + 1])) {
            oc.insert(s[j + 1]);
            num++;
            j++;
        }
        ans = max(ans, num);
    }
    return ans;
}

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/solution/wu-zhong-fu-zi-fu-de-zui-chang-zi-chuan-by-leetc-2/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。