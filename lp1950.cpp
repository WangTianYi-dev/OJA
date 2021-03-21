#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int n, m, h[maxn], l[maxn], r[maxn];
char a[maxn][maxn];
stack<int> s;

// void printl(int* a, int l)
// {
//     for (int i = 1; i <= l; i++) {
//         cout << a[i] << ' ';
//     }
//     cout << '\n';
// }

long long routine()
{
    // cout << "h ";
    // printl(h, m);
    s = stack<int>();
    for (int i = 1; i <= m; i++) {
        while (!s.empty() && h[i] <= h[s.top()]) {
            s.pop();
        }
        l[i] = s.empty() ? 0 : s.top();
        s.push(i);
    }
    // cout << "l ";
    // printl(l, m);
    s = stack<int>();
    for (int i = m; i >= 1; i--) {
        while (!s.empty() && h[i] < h[s.top()]) {
            s.pop();
        }
        r[i] = s.empty() ? m + 1 : s.top();
        s.push(i);
    }
    // cout << "r ";
    // printl(r, m);
    long long res = 0;
    for (int i = 1; i <= m; i++) {
        res += (r[i] - l[i] - 1) * h[i];
    }
    return res;
}

int main()
{
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    long long ans = 0;
    char c;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            h[j]++;
            cin >> c;
            if (c == '*') {
                h[j] = 0;
            }
        }
        ans += routine();
    }
    cout << ans << endl;
    return 0;
}
