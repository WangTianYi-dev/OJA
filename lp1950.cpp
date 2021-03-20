#include <iostream>
#include <algorithm>
using namespace std;


const int maxn = 1010;

char a[1010][1010] = {};
int l[maxn] = {};

int n, m;

int cnt()
{
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == '.') {
                l[j]++;
            } else {
                l[j] = 0;
            }
        }
        for (int j = 1; j <= m; j++) {
            int tl = l[j];
            for (int k = j; k <= m; k++) {
                if (!l[k]) {
                    break;
                }
                tl = min(tl, l[k]);
                ans += tl;
            }
        }
    }
    return ans;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    cout << cnt() << '\n';
}