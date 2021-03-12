#include <cstdio>
#include <ctype.h>
#include <iostream>
using namespace std;
typedef long long ll;
ll mod = 1e7;
ll b, p;
ll MOD;
typedef long long ll;
ll qpow(ll a, ll n)
{
    if (n == 0)
        return 1 % MOD;
    else if (n % 2 == 1)
        return qpow(a, n - 1) * a % MOD;
    else {
        ll temp = qpow(a, n / 2) % MOD;
        return temp * temp % MOD;
    }
}

//非递归快速幂
ll qpow_alt(ll a, ll n)
{
    ll ans = 1;
    while (n) {
        if (n & 1) //如果n的当前末位为1
            ans *= a; //ans乘上当前的a
        a *= a; //a自乘
        n >>= 1; //n往右移一位
    }
    return ans;
}

int main()
{
    cin >> b >> p >> MOD;
    printf("%lld^%lld mod %lld=%lld\n", b, p, MOD, qpow(b, p));
    return 0;
}