#include "leetcode.h"
class Solution {
public:
    int largestRectangleArea(vector<int>& heights)
    {
        stack<int> s1;
        int l = heights.size();
        vector<int> left(l), right(l);
        for (int i = 0; i < l; i++) {
            for (;;) {
                if (s1.empty()) {
                    s1.push(i);
                    left[i] = -1;
                    break;
                } else {
                    if (heights[i] <= heights[s1.top()]) {
                        s1.pop();
                    } else {
                        left[i] = s1.top();
                        s1.push(i);
                        break;
                    }
                }
            }
        }
        s1 = stack<int>();
        for (int i = l - 1; i >= 0; i--) {
            for (;;) {
                if (s1.empty()) {
                    s1.push(i);
                    right[i] = l;
                    break;
                } else {
                    if (heights[i] <= heights[s1.top()]) {
                        s1.pop();
                    } else {
                        right[i] = s1.top();
                        s1.push(i);
                        break;
                    }
                }
            }
        }
        int Max = 0;
        // for (int i = 0; i < l; i++) {
        //     printf("left %d: %d, right %d: %d\n", i, left[i], i, right[i]);
        // }
        for (int i = 0; i < l; i++) {
            // cout << heights[i] * (right[i] - left[i] - 1) << ' ';
            Max = max(Max, heights[i] * (right[i] - left[i] - 1));
        }
        return Max;
    }
};

// int main()
// {
//     Solution s;
//     vector<int> v{2, 1, 5, 6, 2, 3};
//     s.largestRectangleArea(v);
// }