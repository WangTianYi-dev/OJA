#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int a[(int)1e5+10];

bool check(int min)
{
    int numPart = 0;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        if (cur + a[i] > min) {
            cur = a[i];
            numPart++;
        } else {
            cur += a[i];
        }
    }
    numPart++;
    return numPart > m ? false : true;
}


int main()
{
    cin >> n >> m;
    int lo = 0, hi = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        lo = max(a[i], lo);
        hi += a[i];
    }
    int mi, ans;
    // cout << "Lo: " << lo << " Hi: " << hi << endl;
    while (lo <= hi) {
        mi = (lo + hi) >> 1;
        if (check(mi)) {
            ans = mi;
            // cout << "ANS: " << ans << endl;
            hi = mi - 1;
        } else {
            lo = mi + 1;
        }
    }
    cout << ans << endl;
    return 0;
}
