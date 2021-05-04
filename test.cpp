#include <iostream>
#include <ctime>
using namespace std;

int main() {
    long a = 1;
    auto b = clock();
    for (long i = 0; i < ((long)1 << 30); i++) {
        a <<= 1;
    }
    auto e = clock();
    cout << a << ' ' << e - b << endl;
    a = 1;
    b = clock();
    for (long i = 0; i < ((long)1 << 30); i++) {
        a *= 2;
    }
    e = clock();
    cout << a << ' ' << e - b << endl;
    return 0;
}