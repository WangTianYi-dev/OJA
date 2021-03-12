#include <iostream>
using namespace std;
const int MAXN = 1e5 + 10;

int a[MAXN], n, k, l;

bool check(int min)
{
    int tot = 0;
    for (int i = 1; i < n + 1; i++) {
        int t = a[i + 1] - a[i];
        if (t > min) {
            t % min == 0 ? tot += (t / min) - 1 : tot += (t / min);
        }
    }
    if (tot > k)
        return false;
    else
        return true;
}

int main()
{
    cin >> l >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a[n + 1] = l;
    int lo = 0, hi = l, ans, mi;
    while (lo <= hi) {
        mi = (lo + hi) >> 1;
        if (check(mi)) {
            ans = mi;
            hi = mi - 1;
        } else {
            lo = mi + 1;
        }
    }
    cout << ans << endl;
    return 0;
}
