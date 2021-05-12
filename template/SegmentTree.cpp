// luogu p4475
#include <iostream>
using namespace std;

typedef long long ll;

const int maxn = 1e5 + 7;
ll n, m;
ll a[maxn], sum[maxn << 2], add[maxn << 2];

void build(ll l, ll r, ll p) {
    if (l == r) {
        sum[p] = a[l];
        return;
    }
    ll m = (l + r) >> 1;
    build(l, m, p << 1), build(m + 1, r, p << 1 | 1);
    sum[p] = sum[p << 1 | 1] + sum[p << 1];
}

void update(ll l, ll r, ll c, ll s, ll t, ll p) {
    if (l <= s && t <= r) {
        sum[p] += (t - s + 1) * c;
        add[p] += c;
        return;
    }
    ll m = (s + t) >> 1;
    if (add[p]) {
        sum[p << 1] += add[p] * (m - s + 1);
        sum[p << 1 | 1] += add[p] * (t - m);
        add[p << 1] += add[p];
        add[p << 1 | 1] += add[p];
        add[p] = 0;
    }
    if (l <= m) {
        update(l, r, c, s, m, p << 1);
    }
    if (m < r) {
        update(l, r, c, m + 1, t, p << 1 | 1);
    }
    sum[p] = sum[p << 1] + sum[p << 1 | 1];
}

ll query(ll l, ll r, ll s, ll t, ll p) {
    if (l <= s && t <= r) {
        return sum[p];
    }
    ll m = (s + t) >> 1;
    if (add[p]) {
        sum[p << 1] += add[p] * (m - s + 1);
        sum[p << 1 | 1] += add[p] * (t - m);
        add[p << 1] += add[p];
        add[p << 1 | 1] += add[p];
        add[p] = 0;
    }
    ll ans = 0;
    if (l <= m) {
        ans += query(l, r, s, m, p << 1);
    }
    if (m < r) {
        ans += query(l, r, m + 1, t, p << 1 | 1);
    }
    return ans;
}

int main() {
    std::ios::sync_with_stdio(0);
    ll q, i1, i2, i3, i4;
    std::cin >> n >> q;
    for (ll i = 1; i <= n; i++)
        std::cin >> a[i];
    build(1, n, 1);
    while (q--) {
        std::cin >> i1 >> i2 >> i3;
        if (i1 == 2)
            std::cout << query(i2, i3, 1, n, 1) << '\n';
        else
            std::cin >> i4, update(i2, i3, i4, 1, n, 1);
    }
    return 0;
}
