#include <cstdio>
#include <iostream>
using namespace std;

const int maxn = 11;
char a[maxn][maxn], b[maxn][maxn], c[maxn][maxn], d[maxn][maxn];
int n;

void print(char c[][maxn])
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << c[i][j];
        }
        cout << endl;
    }
}

bool equal(char b[][maxn], char c[][maxn])
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (b[i][j] != c[i][j]) {
                return false;
            }
        }
    }
    return true;
}

#define tran(c, a, p, q)            \
    for (int i = 0; i < n; i++)     \
        for (int j = 0; j < n; j++) \
            c[p][q] = a[i][j];

int getAns()
{
    for (int i = 1; i < 7; i++) {
        if (i == 5) {
            tran(c, a, i, n - j - 1);
            tran(d, c, n - j - 1, i);
#ifdef DEBUG
            cout << "5: " << endl;
            print(d);
            cout << endl;
#endif
            if (equal(d, b))
                return i;
            tran(d, c, n - i - 1, n - j - 1);
#ifdef DEBUG
            print(d);
            cout << endl;
#endif
            if (equal(d, b))
                return i;
            tran(d, c, j, n - i - 1);
#ifdef DEBUG
            print(d);
            cout << endl;
#endif
            if (equal(d, b))
                return i;
        } else {
            switch (i) {
            case 1:
                tran(c, a, j, n - i - 1);

                break;
            case 2:
                tran(c, a, n - i - 1, n - j - 1);
                break;
            case 3:
                tran(c, a, n - j - 1, i);
                break;
            case 4:
                tran(c, a, i, n - j - 1);
                break;
            case 6:
                tran(c, a, i, j);
                break;
            }
#ifdef DEBUG
            cout << i << ": " << endl;
            print(c);
#endif
            if (equal(b, c)) {
                return i;
            }
        }
    }

    return 7;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> b[i][j];
        }
    }
    cout << getAns() << endl;
    return 0;
}
