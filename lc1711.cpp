#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static constexpr int MOD = 1000000007;

    int countPairs(vector<int>& deliciousness) {
        int maxv = *max_element(deliciousness.begin(), deliciousness.end());
        int maxs = maxv * 2;
        int pairs = 0;
        unordered_map<int, int> mp;
        for (auto d: deliciousness) {
            for (int s = 1; s <= maxs; s <<= 1) {
                int before = s - d;
                pairs += mp.count(before) ? mp[before] : 0;
            }
            mp[d]++;
        }
        return pairs;
    }
};
