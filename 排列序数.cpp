#include <iostream>
#include <string>
using namespace std;
#define ll long long
ll weight[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
string str;
ll res;
void f() {
    int l = str.length();
    for (int i = 0; i < l; i++) {
        int k = 0;
        for (int j = 0; j < i; j++) {
            if (str[i] > str[j])
                k++;
        }
        // cout << "P at " << i << "is: " << weight[l - i - 1] * (str[i] - 'a' - k) << endl;
        res += weight[l - i - 1] * (str[i] - 'a' - k);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin >> str;
    f();
    cout << res << '\n';
}
