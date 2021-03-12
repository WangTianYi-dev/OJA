#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <climits>
using namespace std;
const int maxn = 16;
double ax[maxn], ay[maxn];
double dp[maxn][1 << maxn];
int n;

double dis(int a, int b)
{
    double x1 = ax[a], x2 = ax[b], y1 = ay[a], y2 = ay[b];
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double solve()
{
    memset(dp, 127, sizeof(dp));
    for (int s = 1; s <= (1 << n) - 1; s++) {
        for (int i = 1; i <= n; i++) {
            if ((s & (1 << (i - 1))) == 0) {
            } else if (s == (1 << (i - 1))) {
                dp[i][s] = 0;
            }
            for (int j = 1; j <= n; j++) {
                if (i == j || (s & (1 << (j - 1))) == 0) {
                } else {
                    dp[i][s] = min(dp[i][s], dp[j][s - (1 << (i - 1))] + dis(i, j));
                }
            }
        }
    }
    double ans = 1e306;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, dp[i][(1 << n) - 1] + dis(i, 0));
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= (1 << n) - 1; j++) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    return ans;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        // cout << "I:" << i << endl;
        scanf(" %lf %lf", &ax[i], &ay[i]);
    }
    printf("%.2lf\n", solve());
    return 0;
}
