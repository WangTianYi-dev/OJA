#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
const int maxn = 5e5 + 10;
typedef long long ll;
int n, m, curDim;
#define X 0
#define Y 1
struct choco {
    ll loc[2], h;
    friend bool operator<(choco c1, choco c2) {
        return c1.loc[curDim] < c2.loc[curDim];
    }
} cho[maxn];

struct D2Node {
    int l, r;
    choco c;
    ll max[2], min[2];
    ll sum;
} t[maxn];
int root;
int a, b, c;

void print(int p) {
    auto &n = t[p];
    printf("%d: l: %d, r: %d, x: %lld, y: %lld, max: (%lld, %lld), min: (%lld, %lld), sum: %lld\n", p, n.l, n.r, n.c.loc[X], n.c.loc[Y], n.max[X], n.max[Y], n.min[X], n.min[Y], n.sum);
}
void printTree() {
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int i = q.front();
        q.pop();
        print(i);
        if (t[i].l) {
            q.push(t[i].l);
        }
        if (t[i].r) {
            q.push(t[i].r);
        }
    }
}

int build_tree(int l, int r, int d) {
    curDim = d;
    int m = (l + r) / 2;
    nth_element(cho + l, cho + m, cho + r + 1);
    t[m].c = cho[m];
    if (l < m) {
        t[m].l = build_tree(l, m - 1, !d);
    }
    if (m < r) {
        t[m].r = build_tree(m + 1, r, !d);
    }
    for (int i = 0; i < 2; i++) {
        t[m].max[i] = t[m].min[i] = t[m].c.loc[i];
        if (t[m].l) {
            t[m].max[i] = max(t[m].max[i], t[t[m].l].max[i]);
            t[m].min[i] = min(t[m].min[i], t[t[m].l].min[i]);
        }
        if (t[m].r) {
            t[m].max[i] = max(t[m].max[i], t[t[m].r].max[i]);
            t[m].min[i] = min(t[m].min[i], t[t[m].r].min[i]);
        }
    }
    t[m].sum = t[t[m].l].sum + t[t[m].r].sum + t[m].c.h;
    return m;
}

ll query(int p) {
    auto in = [&](ll x, ll y) -> int {
        return a * x + b * y < c;
    };
    auto &tp = t[p];
    int tot = 0;
    tot += in(tp.max[X], tp.max[Y]);
    tot += in(tp.min[X], tp.min[Y]);
    tot += in(tp.max[X], tp.min[Y]);
    tot += in(tp.min[X], tp.max[Y]);

    // printf("tot: %d -> %d\n", p, tot);

    if (tot == 4) {
        // printf("res: %d -> %lld\n", p, tp.sum);
        return tp.sum;
    }
    if (tot == 0) {
        // printf("res: %d -> %lld\n", p, 0);
        return 0;
    }
    ll res = 0;
    if (in(tp.c.loc[X], tp.c.loc[Y])) {
        res += tp.c.h;
    }
    if (tp.l) {
        res += query(tp.l);
    }
    if (tp.r) {
        res += query(tp.r);
    }
    // printf("res: %d -> %lld\n", p, res);
    return res;
}

int main() {
    // ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> cho[i].loc[0] >> cho[i].loc[1] >> cho[i].h;
    }
    root = build_tree(1, n, X);
    // printTree();
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        cout << query(root) << '\n';
    }
    return 0;
}