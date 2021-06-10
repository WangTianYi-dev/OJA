#include "leetcode.h"

class Solution {
  public:
    int R, C;
    set<int> contain{};
    vector<set<int>> regions{};
    vector<set<int>> threats{};
    vector<int> blocks{};

    const int dr[4] = {0, 0, 1, -1}, dc[4] = {1, -1, 0, 0};

    int containVirus(vector<vector<int>> &grid) {
        // this->grid = grid;
        R = grid.size(), C = grid[0].size();
        int ans = 0;
        for (;;) {
            contain.clear();
            regions.clear();
            threats.clear();
            blocks.clear();

            // cout << R << ' ' << C << endl;
            // for (int i = 0; i < R; i++) {
            //     for (int j = 0; j < C; j++) {
            //         printf("%3d ", grid[i][j]);
            //     }
            //     cout << endl;
            // }

            int cs = 0;
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    if (contain.find(i * C + j) == contain.end() && grid[i][j] == 1) {
                        blocks.push_back(0);
                        threats.push_back(set<int>());
                        regions.push_back(set<int>());
                        expand(i, j, grid, cs++);
                    }
                }
            }
            if (regions.empty()) {
                break;
            }
            int maxi = 0;
            for (int i = 0; i < threats.size(); i++) {
                if (threats[i].size() > threats[maxi].size()) {
                    maxi = i;
                }
            }
            ans += blocks[maxi];
            for (int i = 0; i < regions.size(); i++) {
                if (maxi == i) {
                    for (auto p : regions[i]) {
                        // cout << p << endl;
                        grid[p / C][p % C] = -1;
                    }
                } else {
                    for (auto p : regions[i]) {
                        int r = p / C, c = p % C;
                        for (int k = 0; k < 4; k++) {
                            int nr = r + dr[k], nc = c + dc[k];
                            if (nr >= 0 && nr < R && nc >= 0 && nc < C && grid[nr][nc] == 0)
                                grid[nr][nc] = 1;
                        }
                    }
                }
            }
        }
        return ans;
    }

    void expand(int r, int c, const vector<vector<int>> &grid, int n) {
        if (contain.find(r * C + c) == contain.end()) {
            contain.insert(r * C + c);
            threats[n].insert(r * C + c);
            regions[n].insert(r * C + c);
            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k], nc = c + dc[k];
                if (nr >= 0 && nr < R && nc >= 0 && nc < C) {
                    if (grid[nr][nc] == 1) {
                        expand(nr, nc, grid, n);
                    } else if (grid[nr][nc] == 0) {
                        threats[n].insert(nr * C + nc);
                        blocks[n]++;
                    }
                }
            }
        }
    }
};

int main() {
    vector<vector<int>> v = {{0, 1, 0, 0, 0, 0, 0, 1}, {0, 1, 0, 0, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 0, 0, 0}};
    Solution s;
    s.containVirus(v);
}
