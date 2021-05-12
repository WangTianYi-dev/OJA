#include <algorithm>
#include <iostream>
using namespace std;

int n;
int temp[(int)1e6 + 7], size;

void insert(int x) {
    temp[++size] = x;
    int i = size;
    for (int j = size / 2; j >= 1; j /= 2) {
        if (temp[i] > temp[j]) {
            break;
        }
        swap(temp[i], temp[j]);
        i = j;
    }
}

int get() {
    return temp[1];
}

void del() {
    temp[1] = temp[size--];
    int i = 1;
    for (int j = i * 2; j <= size; j *= 2) {
        if (j + 1 <= size && temp[j + 1] < temp[j]) {
            j = j + 1;
        }
        if (temp[i] < temp[j]) {
            break;
        }
        swap(temp[i], temp[j]);
        i = j;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int x, op;
    while (n--) {
        cin >> op;
        switch (op) {
        case 1:
            cin >> x;
            insert(x);
            break;
        case 2:
            cout << get() << '\n';
            break;
        case 3:
            del();
            break;
        }
    }
    return 0;
}
