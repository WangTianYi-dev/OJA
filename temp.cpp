#include <ctime>
#include <iostream>
using namespace std;

int a[10000000], b[sizeof(a)/sizeof(int)];
int main() {
    clock_t s = clock(), e;
    s = clock();
    memset(a, 0, sizeof(a));
    e = clock();
    cout << e - s << endl;
    s = clock();
    memcpy(a, b, sizeof(a));
    e = clock();
    cout << e - s << endl;
    // s = clock();
    // for (int i = 0; i < sizeof(a) / sizeof(int); i += 2) {
    //     a[i] = 2;
    // }
    // e = clock();
    // cout << e - s << endl;
    return 0;
}