#include <iostream>
using namespace std;
int n, a[200001] = { 0 }, b[200001] = { 0 }, c[200001] = { 0 }, minn = 0, mann = -99999;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        c[i] = c[i - 1] + a[i];
    }
    b[1] = a[1];
    minn = min(0, c[1]);
    for (int i = 2; i <= n; i++) {
        b[i] = c[i] - minn;
        minn = min(minn, c[i]);
    }
    for (int i = 1; i <= n; i++)
        mann = max(mann, b[i]);
    cout << mann << endl;
}