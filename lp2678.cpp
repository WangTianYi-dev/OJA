#include <iostream>
#include <vector>
using namespace std;
int a[50005], l, n, m;

// 模拟跳石头
bool check(int min)
{
    
    int curpos = 0, tot = 0;
    for (int i = 1; i <= n + 1; i++) {
        if (a[i] - a[curpos] < min) {
            tot++;
            // printf("%d moved\n", i);
        } else {
            curpos = i;
        }
    }
    if (tot <= m)
        return true;
    else
        return false;
}

int main()
{
    cin >> l >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a[n + 1] = l;
    int lo = 0, hi = l, mi, ans;
    while (lo <= hi) {
        mi = (lo + hi) >> 1;
        if (check(mi)) {
            ans = mi;
            lo = mi + 1;
        } else {
            hi = mi - 1;
        }
        // cout << "Ans:" << ans << endl;
    }
    cout << ans << endl;
    return 0;
}