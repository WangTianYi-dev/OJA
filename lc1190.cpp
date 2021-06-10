#include "leetcode.h"

class Solution {
  public:
    string reverseParentheses(string s) {
        int l = s.length();
        stack<int> st;
        vector<int> jump(l);
        for (int i = 0; i < l; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                int j = st.top();
                st.pop();
                jump[i] = j;
                jump[j] = i;
            }
        }
        string ret;
        int index = 0, di = 1;
        while (index < n) {
            if (s[index] == '(' || s[index] == ')') {
                index = jump[index];
                di = -di;
            } else {
                ret += s[index];
            }
            index += di;
        }
        return ret;
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/reverse-substrings-between-each-pair-of-parentheses/solution/fan-zhuan-mei-dui-gua-hao-jian-de-zi-chu-gwpv/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。