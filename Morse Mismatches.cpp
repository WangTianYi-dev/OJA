#include <bits/stdc++.h>
using namespace std;

map<char, string> morse;
int main()
{
    string s;
    string c;
    for (;;) {
        cin >> s;
        if (s == "*")
            break;
        cin >> c;
        morse[s[0]] = c;
    }
}