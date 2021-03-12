#include <iostream>
#include <string>
using namespace std;

string solve(int x)
{
    if (x == 0) {
        return "0";
    }
    int i = 0;
    string s = "";
    do {
        if (x & 1) {
            s = (i == 1 ? "2" : "2(" + solve(i) + ")") + (s == "" ? "" : "+") + s;
        }
    } while (i++, x >>= 1);
    return s;
}

int main()
{
    int n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}