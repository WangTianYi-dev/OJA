#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<string, int> COUNT;
vector<string> WORDS;

string normal(string s) 
{
    string rv;
    for (int i = 0; i < s.length(); i++) {
        if (isupper(s[i])) {
            rv += tolower(s[i]);
        } else {
            rv += s[i];
        }
    }
    sort(rv.begin(), rv.end());
    return rv;
} 


int main() 
{
    string s;
    while (cin >> s) {
        if (s == "#") {
            break;
        }
        WORDS.push_back(s);
        if (!COUNT[normal(s)]) COUNT[normal(s)] = 0;
        COUNT[normal(s)]++;
    }
    sort(WORDS.begin(), WORDS.end());
    for (auto i : WORDS) {
        if (COUNT[normal(i)] == 1) {
            cout << i << endl;
        }
    }
    return 0;
}