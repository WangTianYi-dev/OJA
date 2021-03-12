#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;


int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v;
    int t;
    while (n--) {
        cin >> t;
        v.push_back(t);
    }
    int q;
    while (m--) {
        cin >> q;
        printf("%d\n", v[q-1]);
    }
    return 0;
}