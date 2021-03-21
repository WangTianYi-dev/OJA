#include <cstdio>
#define N 155
using namespace std;
int min(int a, int b)
{
    return a < b ? a : b;
}
char get_a_char()
{
    char c = getchar();
    while (c != 'W' && c != 'B') {
        c = getchar();
    }
    return c;
}
int b[N][N], dp[N][N];
int s[N];
int e;
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            b[i][j] = (get_a_char() == 'W');
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < n; ++j) {
            if (b[i][j]) {
                b[i][j] += b[i + 1][j];
            }
        }
    }
    int ans = 0;
    s[0] = n;
    for (int i = 0; i < n; ++i) {
        e = 0;
        for (int j = n - 1; j >= 0; --j) {
            while (b[i][s[e]] > b[i][j]) {
                --e;
            }
            dp[i][j] = b[i][j] * (s[e] - j) + dp[i][s[e]];
            ans += dp[i][j];
            s[++e] = j;
        }
    }
    printf("%d", ans);
}