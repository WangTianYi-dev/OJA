// #include "leetcode.h"
#include "leetcode.h"

class Solution {
public:
    unordered_map<int, int> s;
    vector<int> twoSum(vector<int>& nums, int target)
    {
        for (int i = 0; i < nums.size(); i++) {
            s[nums[i]] = i;
        }
        vector<int> v;
        for (int i = 0; i < nums.size(); i++) {
            if (s.find(target - nums[i]) != s.end() && s[target - nums[i]] != i) {
                v.emplace_back(i);
                v.emplace_back(s[target - nums[i]]);
                break;
            }
        }
        return v;
    }
};