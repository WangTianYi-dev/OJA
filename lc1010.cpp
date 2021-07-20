#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int numPairsDivisibleBy60(vector<int> &time) {
        vector<int> res(60, 0);
        for (int t : time) {
            res[t % 60]++;
        }
        int ans = 0;
        if (res[0] > 0)
            ans += res[0] * (res[0] - 1) / 2;
        if (res[30] > 0)
            ans += res[30] * (res[30] - 1) / 2;
        int i = 1, j = 59;
        while (i < j) {
            ans += res[i] * res[j];
            i++;
            j--;
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> v{30, 20, 150, 100, 40};
    cout << s.numPairsDivisibleBy60(v);
}