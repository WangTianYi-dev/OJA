#include <iostream>
#include <string>
using namespace std;
bool cmps(string& a, string& b)
{
    if (a.length() != b.length()) {
        return a.length() > b.length();
    }
    for (int i = 0; i < a.length(); i++) {
        if (a[i] != b[i]) {
            return a[i] > b[i];
        }
    }
    return false;
}

string a[100];
int n;

int main()
{
    cin >> n;
    string maxv = "";
    int maxp = -1;
    // string ts;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (cmps(a[i], maxv)) {
            maxv = a[i];
            maxp = i;
        }
    }
    cout << maxp + 1 << endl;
    cout << a[maxp] << endl;
    return 0;
}