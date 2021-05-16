#include "leetcode.h"

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string> vs;
        for (int i = 1; i <= n; i++) {
            vs.emplace_back(to_string(i));
        }
        sort(vs.begin(), vs.end());
        vector<int> res;
        for (auto i: vs) {
            res.emplace_back(stoi(i));
        }
        return res;
    }
};