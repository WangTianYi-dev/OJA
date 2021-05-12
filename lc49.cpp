#include "leetcode.h"

class Solution {
  public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> m;
        vector<vector<string>> res;
        for (auto &i : strs) {
            string str = i;
            sort(str.begin(), str.end());
            m[str].emplace_back(i);
        }
        for (auto i : m) {
            res.emplace_back(i.second);
        }
        return res;
    }
};