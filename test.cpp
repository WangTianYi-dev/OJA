#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int dp[2010][2010], t[2010][2010];
int main()
{
    int w, h, k, mod = 998244353;
    scanf("%d %d %d", &w, &h, &k);
    memset(dp, 0, sizeof(dp));
    memset(t, 0, sizeof(t));
    t[0][0] = 1;
    dp[1][1] = 1;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (i == 1 && j == 1)
                continue;
            int x = max(i - k, 1), y = max(j - k, 1); //处理一下，防止越界
            t[i][j] = t[i - 1][j] + t[i][j - 1]- t[i - 1][j - 1];
            dp[i][j] = dp[i][j] + t[i][j] + t[x - 1][y - 1] - t[i][y - 1] - t[x - 1][j];
            t[i][j] = (t[i][j] + dp[i][j] % mod) % mod; //后面还要加一下本格的数据就完美了
        }
    }
    cout << dp[h][w]; //开心地输出答案
    return 0;
}
