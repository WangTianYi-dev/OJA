#include <climits>
#include <cstdio>
#include <iostream>
using namespace std;
int w, h, k;
const int maxn = 2010;
const int mod = 998244353;
// 2147483648
long long dp[maxn][maxn] = {};
long long s[maxn][maxn] = {};

void getsum(int x, int y)
{
    s[x][y] = ((s[x - 1][y] + s[x][y - 1] - s[x - 1][y - 1]) + mod) % mod;
}

void getdp(int x, int y)
{
    int x1 = max(1, x - k), y1 = max(1, y - k);
    long long r = ((s[x][y] - s[x][y1-1] - s[x1-1][y] + s[x1-1][y1-1]) + 2 * mod) % mod;
    dp[x][y] = r;
    s[x][y] = s[x][y] + dp[x][y];
}

int main()
{
    // freopen("racing.in", "r", stdin);
    // freopen("racing.out", "w", stdout);
    cin >> w >> h >> k;
    dp[1][1] = 1;
    s[1][1] = 1;
    for (int i = 1; i <= w; i++) {
        for (int j = 1; j <= h; j++) {
            if (i == 1 && j == 1)
                continue;
            getsum(i, j);
            getdp(i, j);
        }
    }
    cout << dp[w][h] << endl;
    return 0;
}

/*
1 2 3 3
2 5 9 3
*/