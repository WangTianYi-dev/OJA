// main for luogu p3383
#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 1e8 + 10;
bool isPrime[maxn];
int primes[maxn], cnt = 0;

int n, q;

void sieve()
{
    // ensure every comp number is sieved by its smallest prime factor
    memset(isPrime, 1, sizeof(isPrime) * sizeof(bool));
    isPrime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            primes[++cnt] = i;
        }
        for (int j = 1; j <= cnt && i * primes[j] < n; j++) {
            isPrime[primes[j] * i] = false;
            if (i % primes[j] == 0) {
                break;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    sieve();
    int t;
    while (q--) {
        cin >> t;
        cout << primes[t] << '\n';
    }
    return 0;
}
