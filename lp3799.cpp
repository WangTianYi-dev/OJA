#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
ll a[maxn], nums[maxn];
ll kmod = 1e9 + 7;
ll C(ll n, ll r)
{
    return r == 1ll ? n : n * (n - 1ll) / 2ll % kmod;
}

int main()
{
    ll n;
    cin >> n;
    ll maxv = 0ll;
    for (ll i = 1ll; i <= n; i++) {
        cin >> a[i];
        nums[a[i]]++;
        maxv = max(maxv, a[i]);
    }
    ll ans = 0;
    // printf("MAXV: %lld\n", maxv);

    for (ll j = 2ll; j <= maxv; j++) { //遍历三角形中的最大边
        // printf("NUMS[%lld]: %lld\n", j, nums[j]);
        if (nums[j] < 2ll)
            continue;
        else {
            ll times = C(nums[j], 2);
            for (ll i = 1ll; i <= j / 2ll; i++) { //遍历小边的长度
            
                if (i == j - i && nums[i] >= 2ll) { // i==j/2
                    ans += times * C(nums[i], 2) % kmod;
                    // printf("CURANS: %lld\n", ans);
                }
                if (i != j - i && nums[i] >= 1 && nums[j - i] >= 1ll) {
                    ans += times * C(nums[i], 1) * C(nums[j - i], 1) % kmod;
                    // printf("CURANS: %lld\n", ans);
                }
            }
            ans %= kmod;
        }
    }
    cout << ans << endl;
    return 0;
}
