#include <iostream>
#include <cstdlib>
using namespace std;

int n;
const int maxn = 2e5 + 10;
int a[maxn], tolSum[maxn], minv = 0, maxv = -(1 << 20);
int maxSum[maxn];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        tolSum[i] = tolSum[i-1] + a[i];
    }
    for (int i = 1; i <= n; i++) {
        maxSum[i] = tolSum[i] - minv;
        minv = min(minv, tolSum[i]);
    }
    for (int i = 1; i <= n; i++) {
        maxv = max(maxSum[i], maxv);
    }
    cout << maxv << endl;
    return 0;
}
    