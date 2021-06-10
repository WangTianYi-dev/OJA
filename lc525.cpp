#include "leetcode.h"

class Solution {
  public:
    int findMaxLength(vector<int> &nums) {
        unordered_map<int, int> preMap;
        int counter = 0;
        int res = 0;
        preMap[counter] = -1;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                counter++;
            } else {
                counter--;
            }
            if (preMap.count(counter)) {
                int preI = preMap[counter];
                res = max(res, i - preI);
            } else {
                preMap[counter] = i;
            }
        }
        return res;
    }
};