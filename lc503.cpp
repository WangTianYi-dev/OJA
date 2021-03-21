#include "leetcode.h"
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> loop = nums;
        int n = nums.size();
        stack<int> s;
        loop.insert(loop.end(), nums.begin(), nums.end() - 1);
        vector<int> v(nums.size(), -1);
        for (int i = 0; i < loop.size(); i++) {
            while (!s.empty() && loop[s.top()] < loop[i]) {
                v[s.top() % n] = i;
                s.pop();
            }
            s.push(i);
        }
        return v;
    }
};