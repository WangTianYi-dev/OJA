#include <iostream>
using namespace std;
#include "template/BitMap.h"
BitMap bm(3);
void printb(char t) {
    for (int i = 0; i < 8; i++) {
        char m = 1 << i;
        if (t & m) {
            cout << 1;
        } else {
            cout << 0;
        }
    }
    cout << ' ';
}

int main() {
    int i, j;
    while (1) {
        cout << "set:" << endl;
        cin >> i;
        if (i >= 0)
            bm.set(i);
        for (int i = 0; i < bm.gsize; i++) {
            printb(bm.map[i]);
        }
        cout << endl;
        cout << "get:" << endl;
        cin >> j;
        cout << bm.get(j) << endl;
    }
}
