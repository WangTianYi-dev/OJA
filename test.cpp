// luogu-judger-enable-o2
// luogu-judger-enable-o2
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#define ls(x) T[x].ch[0]
#define rs(x) T[x].ch[1]
#define fa(x) T[x].fa
#define root T[0].ch[1]
using namespace std;
const int MAXN = 1e5 + 10, mod = 10007, INF = 1e9 + 10;

inline char nc()
{
    static char buf[MAXN], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, MAXN, stdin)), p1 == p2 ? EOF : *p1++;
}

inline int read()
{
    char c = nc();
    int x = 0, f = 1;
    while (c < '0' || c > '9') {
        if (c == '-')
            f = -1;
        c = nc();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = nc();
    }
    return x * f;
}

struct node {
    int fa, ch[2], val, rec, sum;
} T[MAXN];

int tot = 0, pointnum = 0;
void update(int x) { T[x].sum = T[ls(x)].sum + T[rs(x)].sum + T[x].rec; }
int ident(int x) { return T[fa(x)].ch[0] == x ? 0 : 1; }

void connect(int x, int fa, int how)
{
    T[fa].ch[how] = x;
    T[x].fa = fa;
}

void rotate(int x)
{
    int Y = fa(x), R = fa(Y);
    int Yson = ident(x), Rson = ident(Y);
    connect(T[x].ch[Yson ^ 1], Y, Yson);
    connect(Y, x, Yson ^ 1);
    connect(x, R, Rson);
    update(Y);
    update(x);
}