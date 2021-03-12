#include <iostream>
#include <algorithm>
using namespace std;
int r;
const int maxn = 1010;
int a[maxn][2*maxn+1], b[maxn][maxn];
void dp()
{
    b[1][1] = a[1][1];
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= i; j++) {
            b[i][j] = max(b[i-1][j-1], b[i-1][j]) + a[i][j];
        }
    }
}

int main()
{
    cin >> r;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> a[i][j];
        }
    }
    dp();
    int ans = 0;
    for (int i = 1; i <= 2 * r - 1; i++) {
        ans = max(ans, b[r][i]);
    }
    cout << ans << endl;
    return 0;
}
