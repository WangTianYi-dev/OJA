#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e6 + 10;

struct node {
    int left, right;
} a[maxn];

int n, ans;
void traverse(int i, int deep) {
    if (i == 0) {
        return ;
    }
    ans = max(ans, deep);
    traverse(a[i].left, deep+1);
    traverse(a[i].right, deep+1);
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].left >> a[i].right;
    }
    traverse(1, 1);
    cout << ans << endl;
}
    
