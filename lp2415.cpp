#include <iostream>
#include <cmath>
#include <cctype>
using namespace std;
int num;
int a[1010];
int64_t sum;
int main()
{
    while (cin >> a[num++]);
    for (int i = 0; i < num - 1; i++) {
        sum += a[i];
    }
    // cout << num << endl;
    sum *= pow(2, num - 2);
    cout << sum << endl;
    return 0;
}