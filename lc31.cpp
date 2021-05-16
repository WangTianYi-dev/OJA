#include "leetcode.h"

void nextPermutation(vector<int> &nums) {
    int i = nums.size() - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }
    if (i >= 0) {
        int j = nums.size() - 1;
        while (j >= 0 && nums[j] <= nums[i]) {
            j--;
        }
        swap(nums[i], nums[j]);
    }
    reverse(nums.begin() + i + 1, nums.end());
}

int main() {
    vector<int> v{1, 2, 3, 4, 5};
    while (1) {
        cin.get();
        for (auto i : v) {
            cout << i << ' ';
        }
        cout << endl;
        nextPermutation(v);
    }
}