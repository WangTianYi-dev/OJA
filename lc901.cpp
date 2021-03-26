#include "leetcode.h"
class StockSpanner {
public:
    stack<int> st;
    vector<int> v;
    // vector<bool> b;
    StockSpanner() {
        st = stack<int>();
        v = vector<int>();
    }
    
    int next(int price) {
        v.push_back(price);
        int i = v.size() - 1;
        while (!st.empty() && v[i] >= v[st.top()]) {
            st.pop();
        }
        int p = st.empty() ? -1 : st.top();
        st.push(i);
        return i - p;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */