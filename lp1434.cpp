#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
int r, c;
const int maxn = 110;
int a[maxn][maxn] = {}, len[maxn][maxn] = {};
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

bool valid(int x, int y)
{
    return 0 < x && x <= r && 0 < y && y <= c;
}

int dfs(int x, int y)
{
    if (len[x][y]) {
        return len[x][y];
    }
    len[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        // printf("(%d, %d)\n", nx, ny);
        if (valid(nx, ny) && a[nx][ny] < a[x][y]) {
#ifdef DEBUG
            printf("(%d, %d) is %d\n", nx, ny, dfs(nx, ny));
#else
            dfs(nx, ny);
#endif
            len[x][y] = max(len[x][y], len[nx][ny] + 1);
        }
    }
    return len[x][y];
}

int main()
{
    cin >> r >> c;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> a[i][j];
        }
    }
    dfs(1, 1);
    int ans = 0;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
#ifdef DEBUG
            cout << len[i][j] << " ";
#endif
            ans = max(ans, dfs(i, j));
        }
#ifdef DEBUG
        cout << endl;
#endif
    }
    cout << ans << endl;
    return 0;
}
