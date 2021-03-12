#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
int n, a, b;
const int maxn = 210;
int k[maxn] = {}, p[maxn] = {};

typedef struct {
    int f, step;
} Node;

bool valid(int f)
{
    return f <= n && 1 <= f;
}

int solve()
{
    queue<Node> q;
    Node n = { a, 0 };
    q.push(n);
    p[a] = 1;
    while (!q.empty()) {
        n = q.front();
        q.pop();
        int f = n.f;
        int d = k[n.f];
        int s = n.step;
        if (f == b) {
            return n.step;
        }
        if (valid(f + d) && !p[f + d]) {
            Node o = { f + d, s + 1 };
            q.push(o);
            p[f + d] = 1;
        }
        if (valid(f - d) && !p[f - d]) {
            Node o = { f - d, s + 1 };
            q.push(o);
            p[f - d] = 1;
        }
    }
    return -1;
}

int main()
{
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
    }
    cout << solve() << endl;
    return 0;
}
