#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int majorityElement(vector<int> &nums) {
        int candidate = -1, count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (count == 0) {
                candidate = nums[i];
                count++;
            } else {
                if (nums[i] == candidate) {
                    count++;
                } else {
                    count--;
                }
            }
        }
        int t = 0;
        for (int i = 0; i < n; i++) {
            if (candidate == nums[i]) {
                t++;
            }
        }
        return t * 2 > n ? candidate : -1;
    }
};