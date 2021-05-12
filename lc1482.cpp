#include "leetcode.h"

class Solution {
  public:
    int minDays(vector<int> &bloomDay, int m, int k) {
        if (bloomDay.size() < m * k) {
            return -1;
        }
        auto canMake = [&k, &m, &bloomDay](int day) {
            int l = bloomDay.size();
            int bonquets = 0, flowers = 0;
            for (int i = 0; i < l; i++) {
                if (bloomDay[i] <= day) {
                    flowers++;
                    if (flowers >= k) {
                        flowers = 0;
                        bonquets++;
                    }
                } else {
                    flowers = 0;
                }
            }
            return bonquets >= m;
        };
        int low = 0, high = 0;
        for (auto &i : bloomDay) {
            high = max(high, i);
        }
        while (low < high) {
            int mid = (low + high) / 2;
            if (canMake(mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};