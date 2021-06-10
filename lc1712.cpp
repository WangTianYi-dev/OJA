#include "leetcode.h"

class Solution {
  public:
    vector<int> preSum;
    int lowerBound(int left, int right, int target) {
        while (left < right) {
            int mi = (left + right) / 2;
            if (preSum[mi] < target) {
                left = mi + 1;
            } else {
                right = mi;
            }
        }
        return left;
    }

    int upperBound(int left, int right, int target) {
        while (left < right) {
            int mi = (left + right) / 2;
            if (preSum[mi] <= target) {
                left = mi + 1;
            } else {
                right = mi;
            }
        }
        return left - 1;
    }

    int waysToSplit(vector<int> &nums) {
        int n = nums.size();
        int sum = 0;
        preSum.resize(n);
        preSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            preSum[i] = preSum[i - 1] + nums[i];
        }
        long res = 0;
        int t = preSum[n - 1] / 3;
        const int mod = 1000000000 + 7;
        for (int i = 0; i < n && preSum[i] <= t; i++) {
            // auto leftBorder = lower_bound(preSum.begin() + i, preSum.end(), preSum[i] * 2);
            // auto rightBorder = lower_bound(preSum.begin() + i, preSum.end(), (preSum[i] + (preSum[n] - preSum[i]) / 2) - 1);
            int leftBorder = lowerBound(i + 1, n - 1, preSum[i] * 2);
            int rightBorder = upperBound(i + 1, n - 1, preSum[i] + (preSum[n - 1] - preSum[i]) / 2);
            // printf("%d, %d\n", leftBorder, rightBorder);
            if (leftBorder <= rightBorder) {
                res += rightBorder - leftBorder + 1;
            }
        }
        return res % mod;
    }
};

int main() {
    Solution s;
    vector<int> v{1, 3, 3};
    cout << s.waysToSplit(v) << endl;
    return 0;
}