#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (auto &s : strs) {
            string ts = s;
            sort(ts.begin(), ts.end());
            mp[ts].emplace_back(s);
        }
        vector<vector<string>> res;
        for (auto &i : mp) {
            sort(i.second.begin(), i.second.end());
            res.emplace_back(i.second);
        }
        return res;
    }
};