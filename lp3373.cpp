#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 1e5 + 7;
typedef long long ll;
int n, m, mod;
int a[maxn];
struct segment_tree {
    ll sum, add, mul;
    int l, r;
} t[maxn * 4];

void update_sum(int p) {
    t[p].sum = t[p * 2].sum + t[p * 2 + 1].sum;
    t[p].sum %= mod;
};

void push_down(int p) {
    t[p * 2].sum =
        (t[p * 2].sum * t[p].mul + t[p].add * (t[p * 2].r - t[p * 2].l + 1)) %
        mod;
    t[p * 2 + 1].sum = (t[p * 2 + 1].sum * t[p].mul +
                        t[p].add * (t[p * 2 + 1].r - t[p * 2 + 1].l + 1)) %
                       mod;

    t[p * 2].add = (t[p].add + t[p * 2].add * t[p].mul) % mod;
    t[p * 2 + 1].add = (t[p].add + t[p * 2 + 1].add * t[p].mul) % mod;
    t[p * 2].mul = (t[p * 2].mul * t[p].mul) % mod;
    t[p * 2 + 1].mul = (t[p * 2 + 1].mul * t[p].mul) % mod;
    t[p].add = 0;
    t[p].mul = 1;
};

void build_tree(int p, int l, int r) {
    t[p].l = l;
    t[p].r = r;
    t[p].mul = 1;
    if (l == r) {
        t[p].sum = a[l] % mod;
        return;
    }
    int m = (l + r) / 2;
    build_tree(p * 2, l, m);
    build_tree(p * 2 + 1, m + 1, r);
    update_sum(p);
}

void range_mul(int p, int x, int y, int k) {
    if (x <= t[p].l && t[p].r <= y) {
        t[p].add = (t[p].add * k) % mod;
        t[p].mul = (t[p].mul * k) % mod;
        t[p].sum = (t[p].sum * k) % mod;
        return;
    }
    push_down(p);
    int m = (t[p].l + t[p].r) / 2;
    if (x <= m) {
        range_mul(p * 2, x, y, k);
    }
    if (m < y) {
        range_mul(p * 2 + 1, x, y, k);
    }
    update_sum(p);
}

void range_add(int p, int x, int y, int k) {
    if (x <= t[p].l && t[p].r <= y) {
        t[p].add = (t[p].add + k) % mod;
        t[p].sum = (t[p].sum + k * (t[p].r - t[p].l + 1)) % mod;
        return;
    }
    push_down(p);
    int m = (t[p].l + t[p].r) / 2;
    if (x <= m) {
        range_add(p * 2, x, y, k);
    }
    if (m < y) {
        range_add(p * 2 + 1, x, y, k);
    }
    update_sum(p);
}

ll range_query(int p, int x, int y) {
    if (x <= t[p].l && t[p].r <= y) {
        return t[p].sum;
    }
    push_down(p);
    int m = (t[p].l + t[p].r) / 2;
    ll ans = 0;
    if (x <= m) {
        ans += range_query(p * 2, x, y);
    }
    if (m < y) {
        ans += range_query(p * 2 + 1, x, y);
    }
    return ans % mod;
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> m >> mod;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build_tree(1, 1, n);
    int op, x, y, k;
    for (int i = 0; i < m; i++) {
        cin >> op >> x >> y;
        if (op == 3) {
            cout << range_query(1, x, y) << '\n';
        } else if (op == 2) {
            cin >> k;
            range_add(1, x, y, k);
        } else if (op == 1) {
            cin >> k;
            range_mul(1, x, y, k);
        }
    }
    return 0;
}
