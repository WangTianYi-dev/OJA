#include "leetcode.h"

class Solution {
  public:
    vector<vector<pair<int, int>>> graph;
    vector<bool> visited;
    vector<int> dis;
    int maxl = 0;
    void find(int s) {
        dis[s] = 0;
        visited[s] = true;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        for (auto i : graph[s]) {
            q.push(i);
        }
        while (!q.empty()) {
            auto pr = q.top();
            q.pop();
            int node = pr.second;
            int curW = pr.first;
            maxl = max(maxl, curW);
            if (!visited[node]) {
                visited[node] = true;
                dis[node] = curW;
                for (auto i : graph[node]) {
                    int nxt = i.second;
                    if (!visited[nxt]) {
                        int nxtW = i.first + curW;
                        if (nxtW < dis[nxt]) {
                            dis[nxt] = nxtW;
                            q.push({dis[nxt], nxt});
                            // visited[nxt] = true;
                        }
                    }
                }
            }
        }
    }

    int networkDelayTime(vector<vector<int>> &times, int n, int k) {
        graph = vector<vector<pair<int, int>>>(n + 1, vector<pair<int, int>>());
        visited = vector<bool>(n + 1, false);
        dis = vector<int>(n + 1, 1 << 30);
        for (auto i : times) {
            int &u = i[0], &v = i[1], &w = i[2];
            graph[u].push_back({w, v});
        }
        find(k);
        // for (auto i : dis) {
        //     cout << i << ' ';
        // }
        // cout << endl;
        // int mx = *max_element(dis.begin() + 1, dis.end());
        // if (mx == 1 << 30) {
        //     return -1;
        // } else {
        //     return mx;
        // }
        return maxl;
    }

};
int main() {
    Solution s;
    vector<vector<int>> v{{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    cout << s.networkDelayTime(v, 4, 2) << endl;
}