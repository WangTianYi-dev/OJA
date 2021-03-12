#include <cmath>
#include <iostream>
using namespace std;

long long x, y, ans, flag;
long long gcd(long long a, long long b)
{
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main()
{
    cin >> x >> y;
    long long lim = 1ll * x * y;
    for (long long i = 1; i <= sqrt(lim); i++) {
        if (lim % i == 0 && gcd(i, lim / i) == x) {
            ans++;
            if (1ll * i * i == lim)
                flag++;
        }
    }
    cout << ans * 2 - flag << endl;
    return 0;
}