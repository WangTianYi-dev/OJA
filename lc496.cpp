#include "leetcode.h"
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)   {
        stack<int> s;
        unordered_map<int, int> m;
        vector<int> ans;
        for (auto i : nums2) {
            while (!s.empty() && i > s.top()) {
                m[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        for (auto i : nums1) {
            if (m.find(i) == m.end()) {
                ans.push_back(-1);
            } else {
                ans.push_back(m[i]);
            }
        }
        return ans;
    }
};