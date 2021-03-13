#include <cstdio>
#include <iostream>
// #define re register
using namespace std;
const int INF = 0x7fffffff;
int cont;
struct node {
    int val, siz, cnt, ls, rs;
} tree[1000010];
int n, opt, xx;
inline void add(int x, int v)
{
    tree[x].siz++;
    if (tree[x].val == v) {
        tree[x].cnt++;
        return;
    }
    if (tree[x].val > v) {
        if (tree[x].ls != 0)
            add(tree[x].ls, v);
        else {
            cont++;
            tree[cont].val = v;
            tree[cont].siz = tree[cont].cnt = 1;
            tree[x].ls = cont;
        }
    } else {
        if (tree[x].rs != 0)
            add(tree[x].rs, v);
        else {
            cont++;
            tree[cont].val = v;
            tree[cont].siz = tree[cont].cnt = 1;
            tree[x].rs = cont;
        }
    }
}

int queryfr(int x, int val, int ans)
{
    if (tree[x].val >= val) {
        if (tree[x].ls == 0)
            return ans;
        else
            return queryfr(tree[x].ls, val, ans);
    } else {
        if (tree[x].rs == 0)
            return tree[x].val;
        return queryfr(tree[x].rs, val, tree[x].val);
    }
}

int queryne(int x, int val, int ans)
{
    if (tree[x].val <= val) {
        if (tree[x].rs == 0)
            return ans;
        else
            return queryne(tree[x].rs, val, ans);
    } else {
        if (tree[x].ls == 0)
            return tree[x].val;
        return queryne(tree[x].ls, val, tree[x].val);
    }
}

int queryrk(int x, int rk)
{
    if (x == 0)
        return INF;
    if (tree[tree[x].ls].siz >= rk)
        return queryrk(tree[x].ls, rk);
    if (tree[tree[x].ls].siz + tree[x].cnt >= rk)
        return tree[x].val;
    return queryrk(tree[x].rs, rk - tree[tree[x].ls].siz - tree[x].cnt);
}

int queryval(int x, int val)
{
    if (x == 0)
        return 0;
    if (val == tree[x].val)
        return tree[tree[x].ls].siz;
    if (val < tree[x].val)
        return queryval(tree[x].ls, val);
    return queryval(tree[x].rs, val) + tree[tree[x].ls].siz + tree[x].cnt;
}

inline int read()
{
    int r = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
        ch = getchar();
    while (ch >= '0' && ch <= '9') {
        r = (r << 3) + (r << 1) + (ch ^ 48);
        ch = getchar();
    }
    return r;
}

int main()
{
    n = read();
    while (n--) {
        opt = read();
        xx = read();
        if (opt == 1)
            printf("%d\n", queryval(1, xx) + 1);
        else if (opt == 2)
            printf("%d\n", queryrk(1, xx));
        else if (opt == 3)
            printf("%d\n", queryfr(1, xx, -INF));
        else if (opt == 4)
            printf("%d\n", queryne(1, xx, INF));
        else {
            if (cont == 0) {
                cont++;
                tree[cont].cnt = tree[cont].siz = 1;
                tree[cont].val = xx;
            } else
                add(1, xx);
        }
    }
    return 0;
}