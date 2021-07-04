#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string modifyString(string s) {
        char f, b;
        int l = s.length();
        for (int i = 0; i < l; i++) {
            if (s[i] == '?') {
                f = i == 0 ? 0 : s[i - 1];
                b = i == l - 1 ? 0 : s[i + 1];
                char c = 'a';
                while (c == f || c == b) {
                    c++;
                }
                s[i] = c;
            }
        }
        return s;
    }
};