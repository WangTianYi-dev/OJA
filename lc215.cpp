#include "leetcode.h"
// using namespace std;

class Solution {
  public:
    int quick_select(vector<int> &a, int lo, int tar, int hi) {
        int i = hi, j = hi, p = rand() % (hi - lo + 1) + lo;
        swap(a[lo], a[p]);
        while (lo < j) {
            if (a[lo] < a[j]) {
                swap(a[i--], a[j]);
            }
            j--;
        }
        swap(a[i], a[lo]);
        if (i == tar) {
            return a[i];
        } else if (i < tar) {
            return quick_select(a, i + 1, tar, hi);
        } else
            return quick_select(a, lo, tar, i - 1);
    }

    int findKthLargest(vector<int> &nums, int k) {
        // srand(time(NULL));
        int l = nums.size();
        return quick_select(nums, 0, l - k, l - 1);
    }
};