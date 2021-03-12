// ====================================
//   author: M_sea
//   website: https://m-sea-blog.com/
// ====================================
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100000 + 10, M = 200000 + 10;

int n, m, s, t;
struct edge {
    int v, w, nxt;
} e[M];
int head[N];

void addEdge(int u, int v, int w)
{
    static int cnt = 0;
    e[++cnt] = (edge) { v, w, head[u] }, head[u] = cnt;
}

// 这是一个以 dis 为第一关键字的小根堆
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
int dis[N];
void dijkstra(int s)
{
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0, Q.push(make_pair(0, s));
    while (!Q.empty()) {
        int u = Q.top().second, d = Q.top().first;
        Q.pop();
        if (d != dis[u])
            continue;
        for (int i = head[u]; i; i = e[i].nxt) {
            int v = e[i].v, w = e[i].w;
            if (dis[u] + w < dis[v])
                dis[v] = dis[u] + w, Q.push(make_pair(dis[v], v));
        }
    }
}

int main()
{
    cin >> n >> m >> s;
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(u, v, w);
    }
    dijkstra(s);
    for (int i = 1; i <= n; ++i)
        printf("%d%c", dis[i], " \n"[i == n]);
    return 0;
}