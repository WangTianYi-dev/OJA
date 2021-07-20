#include <algorithm>
#include <limits.h>
#include <stdio.h>
#include <string.h>

using namespace std;

int N;
const int maxn = 128;
int dp[maxn][maxn], stone[maxn] = {};
int sum[maxn] = {};

int main() {
    memset(dp, 0x3f, sizeof(dp));
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &stone[i]);
        sum[i] = sum[i - 1] + stone[i];
        dp[i][i] = 0;
    }
    for (int len = 1; len <= N; len++) {
        for (int start = 1; start + len <= N + 1; start++) {
            int end = start + len - 1;
            for (int div = start; div < end; div++) {
                dp[start][end] = min(dp[start][end], dp[start][div] + dp[div + 1][end] + sum[end] - sum[start - 1]);
            }
        }
    }
    printf("%d\n", dp[1][N]);
    return 0;
}