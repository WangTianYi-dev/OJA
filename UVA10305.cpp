#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int m, n;
vector<vector<int>> graph;
vector<int> in;

int main()
{
    while (cin >> n >> m) {
        if (n == 0 && m == 0) {
            break;
        }
        graph = vector<vector<int>>(n + 1);
        in = vector<int>(n + 1);
        int a, b;
        for (int i = 1; i <= m; i++) {
            cin >> a >> b;
            graph[a].push_back(b);
            in[b]++;
        }
        queue<int> q;
        vector<int> ans;
        for (int i = 1; i <= n; i++) {
            if (in[i] == 0) {
                q.push(i);
                ans.push_back(i);
            }
        }
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            for (auto i : graph[t]) {
                in[i]--;
                if (in[i] == 0) {
                    ans.push_back(i);
                    q.push(i);
                }
            }
        }
        for (auto i : ans) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}