#include "leetcode.h"

class Solution {
public:
    
    vector<int> dailyTemperatures(vector<int>& T) {
        
        int n = T.size();
        if (!n) {
            return vector<int>();
        }
        vector<int> ans(n, 0);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && T[i] > T[st.top()]) {
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};