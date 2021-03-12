#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
vector<string> v;
string reverse(string& s)
{
    string rs;
    for (int i = s.length() - 1; i >= 0; i--) {
        rs += s[i];
    }
    return rs;
}

int solve(string& s)
{

    for (int i = 0; i < s.length(); i++) {
        string a, b;
        a = s.substr(0, i);
        b = s.substr(i, s.size());
        string ra = a, rb = b;
        reverse(ra.begin(), ra.end()), reverse(rb.begin(), rb.end());
        v.push_back(a + b);
        v.push_back(ra + b);
        v.push_back(a + rb);
        v.push_back(ra + rb);
        v.push_back(b + a);
        v.push_back(rb + a);
        v.push_back(b + ra);
        v.push_back(rb + ra);
    }
    // cout << "OLD:\n";
    // for (auto i : v) {
    //     cout << i << endl;
    // }
    sort(v.begin(), v.end());
    vector<string>::iterator new_end = unique(v.begin(), v.end());
    // cout << "NEW:\n";
    // for (auto i = v.begin(); i != new_end; i++) {
    //     cout << *i << endl;
    // }
    return distance(v.begin(), new_end);
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    while (n--) {
        v.clear();
        string s;
        cin >> s;
        cout << solve(s) << '\n';
    }
    return 0;
}
