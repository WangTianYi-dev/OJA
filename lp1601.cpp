#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void out(string s)
{
    reverse(s.begin(), s.end());
    cout << s << '\n';
}

string add(const string& a, const string& b)
{
    string s;
    char temp, carry = 0;
    int len = min(a.length(), b.length());
    for (int i = 0; i < len; i++) {
        temp = a[i] - '0' + b[i] - '0' + carry;
        carry = 0;
        if (temp > 9) {
            carry = 1;
            temp -= 10;
        }
        s.push_back(temp + '0');
    }
    for (int i = len; i < a.length(); i++) {
        temp = a[i] - '0' + carry;
        carry = 0;
        if (temp > 9) {
            carry = 1;
            temp -= 10;
        }
        s.push_back(temp + '0');
    }
    for (int i = len; i < b.length(); i++) {
        temp = b[i] - '0' + carry;
        carry = 0;
        if (temp > 9) {
            carry = 1;
            temp -= 10;
        }
        s.push_back(temp + '0');
    }
    if (carry == 1) {
        s.push_back('1');
    }
    return s;
}

int main()
{
    string a, b;
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    out(add(a, b));
    return 0;
}