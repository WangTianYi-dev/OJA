#include <iostream>
using namespace std;
const int maxn = 110;

struct node {
    int val, left, right;
} a[maxn];

int n;

int traverse(int i)
{
    if (i == 0)
        return 0;
    return a[i].val + traverse(a[i].left) + traverse(a[i].right);
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].val >> a[i].left >> a[i].right;
    }
    cout << traverse(1) << endl;
    return 0;
}
