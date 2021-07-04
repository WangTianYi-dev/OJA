#include "leetcode.h"

class Solution {
  public:
    int peakIndexInMountainArray(vector<int> &arr) {
        int n = arr.size();
        int low = 1, high = n - 2;
        int res = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] < arr[mid+1]) {
                low = mid + 1;
            } else {
                res = mid;
                high = mid - 1;
            }
        }
        return res;
    }
};