#include "leetcode.h"

class Solution {
  public:
    vector<int> getLeastNumbers(vector<int> &arr, int k) {
        vector<int> res;
        int l = arr.size();
        if (k >= l) {
            return arr;
        }
        priority_queue<int> q;
        for (int i = 0; i < k; i++) {
            q.push(arr[i]);
        }
        for (int i = k; i < l; i++) {
            if (q.top() < arr[i]) {
                q.pop();
                q.push(arr[i]);
            }
        }
        while (!q.empty()) {
            res.push_back(q.top());
            q.pop();
        }
        return res;
    }
};