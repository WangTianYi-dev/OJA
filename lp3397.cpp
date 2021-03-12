#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1010;
ll grid[maxn][maxn] = {{}}, n, m;
int main()
{
    cin >> n >> m;
    ll x1, y1, x2, y2;
    while (cin >> x1 >> y1 >> x2 >> y2) {
        for (ll i = x1; i <= x2; i++) {
            for (ll j = y1; j <= y2; j++) {
                grid[i][j]++;
            }
        }
    }
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++) {
            cout << grid[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
} 
