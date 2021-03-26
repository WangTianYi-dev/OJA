#include "leetcode.h"

class Solution {
public:
int trap(vector<int>& height)
{
    int ans = 0, cur = 0;
    stack<int> st;
    while (cur < height.size()) {
        while (!st.empty() && height[st.top()] < height[cur]) {
            int pre = st.top();
            st.pop();
            if (st.empty()) {
                break;
            }
            int dis = cur - st.top() - 1;
            int h = min(height[cur], height[st.top()]) - height[pre];
            ans += dis * h;
        }
        st.push(cur++);
    }
    return ans;
}
};

// int main()
// {
//     vector<int> v { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
//     Solution s;
//     cout << s.trap(v) << endl;
//     return 0;
// }
