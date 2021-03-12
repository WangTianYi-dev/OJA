#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 1010;

int T, M;
int dp[maxn][maxn], m[maxn], v[maxn];
int main()
{
    cin >> T >> M;
    for (int i = 1; i <= M; i++) {
        cin >> m[i] >> v[i];
    }
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= T; j++) {
            int pickedVal = (j >= m[i]) ? dp[i - 1][j - m[i]] + v[i] : 0;
            dp[i][j] = max(dp[i - 1][j], pickedVal);
        }
    }
#ifdef DEBUG
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= T; j++) {
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }
    printf("%d %d %d\n", T, M, dp[M][T]); 
#endif
    cout << dp[M][T] << endl;
    return 0;
}