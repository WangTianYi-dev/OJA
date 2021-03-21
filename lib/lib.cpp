#include <bits/stdc++.h>
using namespace std;
// rank start with 1
template <class T>
void printl(string msg, T* a, int l)
{
    cout << msg << ' ';
    for (int i = 1; i <= l; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;
}