#include <iostream>
using namespace std;
const int maxn = 1010;
int m, n;
char a[maxn][maxn];

bool valid(int x1, int x2, int y1, int y2)
{
    for (int i = x1; i < x2; i++) {
        for (int j = y1; j < y2; j++) {
            if (a[i][j] == '*') {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    int ans = 0;
    for (int x1 = 1; x1 <= m; x1++) {
        for (int x2 = x1 + 1; x2 <= m + 1; x2++) {
            for (int y1 = 1; y1 <= n; y1++) {
                for (int y2 = y1 + 1; y2 <= n + 1; y2++) {
                    if (valid(x1, x2, y1, y2)) {
                        ans++;
                    } else {
                        y1 =  y2;
                        break;
                    }
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}