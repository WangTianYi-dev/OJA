#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool stoneGame(vector<int> &piles) {
        int len = piles.size();
        vector<vector<int>> maxCurScore(len, vector<int>(len, 0));
        for (int i = 0; i < len; i++) {
            maxCurScore[i][i] = piles[i];
        }
        for (int i = len - 2; i >= 0; i--) {
            for (int j = i + 1; j < len; j++) {
                maxCurScore[i][j] = max(piles[i] - maxCurScore[i + 1][j], piles[j] - maxCurScore[i][j - 1]);
            }
        }
        return maxCurScore[0][len - 1] > 0;
    }
};