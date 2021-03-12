#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int a[110][110], n, C;
int b[110][110];
int main()
{
    cin >> C;
    while (C--) {
        memset(a, 0, sizeof(a));
        memset(a, 0, sizeof(a));
        cin >> n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                cin >> a[i][j];
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                b[i][j] = a[i][j] + max(b[i - 1][j - 1], b[i - 1][j]);
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = max(ans, b[n][i]);
        }

        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= i; j++) {
        //         cout << b[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        cout << ans << endl;
    }
    return 0;
}
