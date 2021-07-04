#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> findErrorNums(vector<int> &nums) {
        vector<int> res(2, 0);
        unordered_map<int, int> mp;
        int l = nums.size();
        for (int i = 0; i < l; i++) {
            mp[nums[i]]++;
        }
        for (int i = 1; i <= l; i++) {
            int count = mp[i];
            if (count == 0) {
                res[1] = i;
            } else if (count == 2) {
                res[0] = i;
            }
        }
        return res;
    }
};