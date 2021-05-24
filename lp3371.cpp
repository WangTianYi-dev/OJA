// #include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdio>
using namespace std;

const int maxn = 1e4 + 7;
const int maxm = 5e5 + 7;
const unsigned INF = (1 << 31) - (unsigned)1;
int n, m, s;
struct edge {
    unsigned to, weight;
};

bool operator<(const edge a, const edge b) {
    return a.weight > b.weight;
}

vector<vector<edge>> graph(maxn);
vector<unsigned> dis;
vector<bool> vis;
void routine(unsigned s) {
    priority_queue<edge> q;
    vis[s] = true;
    dis[s] = 0;
    for (auto &i : graph[s]) {
        q.push({i.to, i.weight});
    }
    while (!q.empty()) {
        edge e = q.top();
        if (!vis[e.to]) {

            // printf("e: {%d, %d}\n", e.to, e.weight);

            dis[e.to] = e.weight;
            vis[e.to] = true;
        }
        q.pop();
        for (auto &i : graph[e.to]) {
            if (!vis[i.to]) {
                if (dis[i.to] > dis[e.to] + i.weight) {
                    dis[i.to] = dis[e.to] + i.weight;
                    q.push({i.to, dis[i.to]});
                }
            }
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &s);
    dis = vector<unsigned>(n + 1, INF);
    vis = vector<bool>(n + 1, false);
    unsigned u, v, w;
    for (int i = 0; i < m; i++) {
        scanf("%u%u%u", &u, &v, &w);
        graph[u].push_back({v, w});
    }
    routine(s);
    for (int i = 1; i <= n; i++) {
        printf("%d ", dis[i]);
    }
    return 0;
}
