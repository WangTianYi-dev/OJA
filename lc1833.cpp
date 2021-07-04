#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int cnt = 0;
        for (int i = 0, l = costs.size(); i < l; i++) { 
            if (costs[i] <= coins) {
                coins -= costs[i];
                cnt++;
            } else {
                break;
            }
        }
        return cnt;
    }
};