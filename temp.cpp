#include <ctime>
#include <iostream>
using namespace std;

int a[1000000000];
int main() {
    clock_t s = clock(), e;
    s = clock();
    memset(a, 0, sizeof(a));
    e = clock();
    cout << e - s << endl;
    s = clock();
    for (int i = 0; i < sizeof(a) / sizeof(int); i++) {
        a[i] = 1;
    }
    e = clock();
    cout << e - s << endl;
    s = clock();
    for (int i = 0; i < sizeof(a) / sizeof(int); i += 2) {
        a[i] = 2;
    }
    e = clock();
    cout << e - s << endl;
    return 0;
}