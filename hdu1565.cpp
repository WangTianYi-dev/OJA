#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
#define clear(x) (memset(x, 0, sizeof(x)))
// const int maxn = 20;
int n;
int a[20][20];

//dp为动态规划矩阵，sum中存储了每一行每一个状态的和
int dp[20][(1 << 16) + 10], sum[20][(1 << 16) + 10];

// sta中存储了所有可行的行（列）以优化效率，cnt为可行行（列）总数
int sta[1 << 16], cnt;

void init()
{
    for (int i = 0; i < (1 << 16); i++) {
        if (!(i & (i >> 1))) {
            sta[cnt++] = i;
        }
    }
    // cout << "COUNT:" << cnt << endl;
}

int calcRow(int row, int state)
{
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if ((1 & state)) {
            ans += a[row][i];
        }
        state >>= 1;
    }
    return ans;
}

int solve()
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < cnt; j++) {
            sum[i][j] = calcRow(i, sta[j]);
        }
    }

    for (int i = 0; i < cnt; i++) {
        dp[0][i] = sum[0][i];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < cnt; j++) {
            for (int k = 0; k < cnt; k++) {
                if (!(sta[k] & sta[j])) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][k] + sum[i][j]);
                }
            }
        }
    }
    // for (int i = 0; i < cnt; i++) {
    //     cout << sta[i] << " ";
    // }
    // // cout << endl;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < cnt; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << "END" << endl;
    int ans = dp[n - 1][0];
    for (int i = 1; i < cnt; i++) {
        ans = max(ans, dp[n - 1][i]);
    }
    return ans;
}

int main()
{
    init();
    while (cin >> n) {
        clear(a);
        clear(dp);
        clear(sum);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //         cout << a[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        cout << solve() << endl;
    }
    return 0;
}
