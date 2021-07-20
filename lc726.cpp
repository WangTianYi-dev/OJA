#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string countOfAtoms(string formula) {
        int i = 0, n = formula.length();
        auto parseAtom = [&]() -> string {
            string atom;
            atom += formula[i++];
            while (i < n && islower(formula[i])) {
                atom += formula[i++];
            }
            return atom;
        };
        auto parseNum = [&]() -> int {
            if (i == n || !isdigit(formula[i])) {
                return 1;
            } else {
                int num = 0;
                while (i < n && isdigit(formula[i])) {
                    num *= 10;
                    num += formula[i++] - '0';
                }
                return num;
            }
        };
        stack<unordered_map<string, int>> stk;
        stk.push({});
        while (i < n) {
            char ch = formula[i];
            if (ch == '(') {
                i++;
                stk.push({});
            } else if (ch == ')') {
                i++;
                int num = parseNum();
                auto atomMap = stk.top();
                stk.pop();
                for (auto &p : atomMap) {
                    stk.top()[p.first] += p.second * num;
                }
            } else {
                string atom = parseAtom();
                int num = parseNum();
                stk.top()[atom] += num;
            }
        }
        auto &atomNum = stk.top();
        vector<pair<string, int>> pairs;
        for (auto &p : atomNum) {
            pairs.push_back({p.first, p.second});
        }
        sort(pairs.begin(), pairs.end());
        string ans;
        for (auto &p : pairs) {
            ans += p.first;
            if (p.second > 1) {
                ans += to_string(p.second);
            }
        }
        return ans;
    }
};