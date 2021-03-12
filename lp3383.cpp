#include <cstdio>
#include <cstring>
using namespace std;
constexpr int maxn = 1e8 + 10;
bool isPrime[maxn];
int primes[600010], cnt = 0;
int n, q;
void sieve()
{
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            primes[++cnt] = i;
        }
        for (int j = 1; j <= cnt && i * primes[j] <= n; j++) {
            isPrime[i * primes[j]] = false;
            if (i % primes[j] == 0) {
                break;
            }
        }
    }
}

int main()
{
    scanf(" %d %d", &n, &q);
    sieve();
    int t;

    while (q--) {
        scanf("%d", &t);
        printf("%d\n", primes[t]);
    }
    return 0;
}