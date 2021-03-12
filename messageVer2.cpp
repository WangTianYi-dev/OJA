#include<iostream>
#include<cstdio>
#include<cmath>
#define max(x, y) ((x > y) ? x : y)
using namespace std;

#define MAX_NUM 52

int map[MAX_NUM][MAX_NUM];     //好心程度 | 权值
int dp[MAX_NUM+MAX_NUM][MAX_NUM][MAX_NUM];

int maxPath(int m, int n)
{
    for (int k = 1;k <= m+n-3; k++)
    {
        for (int x1 = 0; x1 <= k; x1++)
        {
            for (int x2 = 0; x2 <= k; x2++)
            {
                if (x1 == x2)    //x1 == x2 相当于(x1 == x2 && y1 = y2)
                {
                    continue;
                }
                dp[k][x1][x2] = max(max(dp[k-1][x1][x2], dp[k-1][x1-1][x2-1]),
                                    max(dp[k-1][x1-1][x2], dp[k-1][x1][x2-1]))
                                + map[x1][k-x1] + map[x2][k-x2];
            }
        }
    }
    return dp[m+n-3][m-1][m-2];
}

int main()
{
    int x;
    scanf("%d", &x);
    while (x--) {
        int m, n;
        scanf("%d%d", &m, &n);

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                scanf("%d", &map[i][j]);

        int ans = maxPath(m, n);
        printf("%d\n", ans);
    }

    return 0;
}