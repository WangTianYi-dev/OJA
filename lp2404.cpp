#include <climits>
#include <iostream>
using namespace std;

int a[100000] = { 1 }, n, cur;

void print(int d)
{
    for (int i = 1; i < d; i++) {
        cout << a[i] << "+";
    }
    cout << a[d] << endl;
}

void search(int d)
{
    bool flag = true;
    for (int j = a[d - 1]; j <= cur; j++) {
        a[d] = j;
        cur -= j;
        if (cur > 0) {
            search(d+1);
        } else if (d > 1) {
            print(d);
        }
        cur += j;
    }
}

int main()
{
    cin >> n;
    cur = n;
    search(1);
    return 0;
}