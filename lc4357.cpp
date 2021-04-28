#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
const int N = 1000010, inf = (1 << 30);
int opt;
struct Pnt {
    int x[2];
} G[N];
inline ll sqr(int x) { return x * 1ll * x; }
inline int get(int L, int R)
{
    double ax = 0, ay = 0, bx = 0, by = 0, mod = R - L + 1;
    for (int i = L; i <= R; ++i) {
        ax += G[i].x[0];
        bx += G[i].x[1];
        ay += sqr(G[i].x[0]);
        by += sqr(G[i].x[1]);
    }
    ax = ay * mod - ax * ax;
    bx = by * mod - bx * bx;
    if (ax > bx)
        return 0;
    return 1;
}

inline bool cmp(Pnt a, Pnt b) { return a.x[opt] < b.x[opt]; }
#define max_(a, b) (a > b ? a : b)
#define min_(a, b) (a < b ? a : b)
#define lc l[x]
#define rc r[x]
priority_queue<ll> q;
struct Segment_tree {
    int maxn[N << 1][2], minn[N << 1][2], l[N << 1], r[N << 1], cnt;
    Pnt d[N << 1];
    inline void pushup(int x)
    {
        for (int i = 0; i < 2; ++i) {
            maxn[x][i] = minn[x][i] = d[x].x[i];
        }
        if (lc) {
            for (int i = 0; i < 2; ++i) {
                maxn[x][i] = max_(maxn[x][i], maxn[lc][i]);
                minn[x][i] = min_(minn[x][i], minn[lc][i]);
            }
        }
        if (rc) {
            for (int i = 0; i < 2; ++i) {
                maxn[x][i] = max_(maxn[x][i], maxn[rc][i]);
                minn[x][i] = min_(minn[x][i], minn[rc][i]);
            }
        }
    }
    inline void build(int& x, int L, int R)
    {
        if (L > R)
            return;
        x = ++cnt;
        int mid = (L + R) >> 1;
        opt = get(L, R); //或者opt=rand()%2,或者轮换维度切割也好
        nth_element(G + L, G + mid, G + R + 1, cmp);
        d[x] = G[mid];
        build(lc, L, mid - 1);
        build(rc, mid + 1, R);
        pushup(x);
    }
    inline ll f(Pnt a, Pnt b) { return sqr(a.x[0] - b.x[0]) + sqr(a.x[1] - b.x[1]); }
    inline ll g(Pnt a, int b) { return max_(sqr(a.x[0] - maxn[b][0]), sqr(a.x[0] - minn[b][0])) + max_(sqr(a.x[1] - maxn[b][1]), sqr(a.x[1] - minn[b][1])); }
    inline void query(int x, Pnt y)
    {
        ll dl = -inf, dr = -inf;
        if (lc)
            dl = g(y, lc);
        if (rc)
            dr = g(y, rc);
        ll di = f(y, d[x]);
        if (-q.top() < di) {
            q.pop();
            q.push(-di);
        }
        if (dl > dr) {
            if (-q.top() < dl)
                query(lc, y);
            if (-q.top() < dr)
                query(rc, y);
        } else {
            if (-q.top() < dr)
                query(rc, y);
            if (-q.top() < dl)
                query(lc, y);
        }
    }
} T;
int n, m;

int main()
{
    srand(time(NULL));
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &G[i].x[0], &G[i].x[1]);
    }
    for (int i = 1; i <= 2 * m; ++i)
        q.push(0);
    T.build(T.l[0], 1, n);
    for (int i = 1; i <= n; ++i)
        T.query(1, G[i]);
    printf("%lld\n", -q.top());
    return 0;
}
