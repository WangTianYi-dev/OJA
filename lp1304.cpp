#include <cstdio>
#include <iostream>
using namespace std;

bool isPrime(int n)
{
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int getFirst(int n) {
    for (int i = 2; i < n; i++) {
        if (isPrime(i) && isPrime(n-i)) {
            return i;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 4; i <= n; i += 2) {
        int j = getFirst(i);
        printf("%d=%d+%d\n", i, j, i - j);
    }
    return 0;
}