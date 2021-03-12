#include <cstdio>
#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, unordered_map<int, int> > m;

int main()
{
    int n, q;
    int c, i, j, k;
    cin >> n >> q;
    while (q--) {
        cin >> c;
        if (c == 1) {
            cin >> i >> j >> k;
            m[i][j] = k;
        } else {
            cin >> i >> j;
            cout << m[i][j] << '\n';
        }
    }
    return 0;
}
