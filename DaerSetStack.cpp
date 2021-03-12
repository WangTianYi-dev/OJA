#include <bits/stdc++.h>
using namespace std;

vector<set<int>> SETLIST;
map<set<int>, int> SETMAP;

int GetID(set<int> st)
{
    if (!SETMAP[st]) {
        SETLIST.push_back(st);
        return SETMAP[st] = SETLIST.size() - 1;
    } else {
        return SETMAP[st];
    }
}

int main()
{
    int T;
    cin >> T;
    while (T--) {
        stack<int> s;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            string instruct;
            cin >> instruct;
            if (instruct == "PUSH") {
                s.push(GetID(set<int>()));
            } else if (instruct == "DUP") {
                s.push(s.top());
            } else {
                set<int> x1 = SETLIST[s.top()];
                s.pop();
                set<int> x2 = SETLIST[s.top()];
                s.pop();
                set<int> x;
                if (instruct == "UNION") {
                    set_union(x1.begin(), x1.end(), x2.begin(), x2.end(),
                        inserter(x, x.begin()));
                } else if (instruct == "INTERSECTION") {
                    set_intersection(x1.begin(), x1.end(), x2.begin(), x2.end(),
                        inserter(x, x.begin()));
                } else if (instruct == "ADD") {
                    x = x2;
                    x.insert(GetID(x1));
                }
                s.push(GetID(x));
            }
            cout << SETLIST[s.top()].size() << endl;
        }
        cout << "***" << endl;
    }
    return 0;
}