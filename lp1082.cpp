#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long ll;

ll euclid(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return euclid(b, a % b);
}

ll e_euclid(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll ans = e_euclid(b, a%b, x, y);
    ll t = x;
    x = y;
    y = t - (a / b) * y;
    return ans;
}
ll x, y;

int main()
{
	long long a, b;
	cin >> a >> b;
	e_euclid(a, b, x, y);
	x = (x % b + b) % b;
	printf("%lld\n", x);
	return 0;
}
