#include <climits>
#include <iostream>
#include <cstdio>
using namespace std;
int a[1000];
int main()
{
    int n;
    cin >> n;
    int maxv = 0, maxp = -1, minv = 10086, minp = -1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > maxv) {
            maxp = i;
            maxv = a[i];
        }
        if (a[i] < minv) {
            minp = i;
            minv = a[i];
        }
    }
    double res = 0.0;
    for (int i = 0; i < n; i++) {
        if (i != maxp && i != minp) {
            res = res + a[i];
        }
    }
    printf("%.2lf\n", res / (n - 2));
    return 0;
}