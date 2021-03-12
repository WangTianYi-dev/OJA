#include <iostream>
#include <string>
#include <sstream>
#include <set>
using namespace std;

set<string> DICT;

int main()
{
    string s;
    while (cin >> s) {
        for (int i = 0; i < s.length(); i++) {
            if (isalpha(s[i])) {
                s[i] = tolower(s[i]);
            } else {
                s[i] = ' ';
            }
        }
        stringstream ss(s);
        while (ss >> s) {
            DICT.insert(s);
        }
    }
    for (auto i : DICT) {
        cout << i << '\n';
    }
    return 0;
}