#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <string>
using namespace std;
int C;
string merge(string s1, string s2)
{
    string s;
    for (int i = 0; i < C; i++) {
        s += s1[i];
        s += s2[i];
    }
    // printf("s1: %s, s2: %s, merge: %s\n", s1.c_str(), s2.c_str(), s.c_str());
    return s;
}

struct Node {
    string str;
    int len;
    Node(string str, int len)
        : str(str)
        , len(len)
    {
    }
};

int Solve(string s1, string s2, string s)
{
    map<string, bool> m;
    queue<Node> q;
    q.push(Node(merge(s1, s2), 1));
    printf("%s pushed\n", merge(s1, s2).c_str());
    m[merge(s1, s2)] = true;
    if (m.count(merge(s2, s1)) == 0) {
        q.push(Node(merge(s2, s1), 1));
        printf("%s pushed\n", merge(s2, s1).c_str());
        m[merge(s2, s1)] = true;
    }
    while (!q.empty()) {
        Node n = q.front();
        q.pop();
        string curs = n.str;
        int curlen = n.len;
        if (curs == s) {
            printf("ans: %s, len %d\n", curs.c_str(), curlen);
            return curlen;
        } else {
            string curs1 = curs.substr(0, C);
            string curs2 = curs.substr(C, C);
            string mers1 = merge(curs1, curs2);
            string mers2 = merge(curs2, curs1);
            cout << "curs: " << curs << endl
                 << " curs1: " << curs1 << " curs2: " << curs2 << endl
                 << " mers1: " << mers1 << " mers2: " << mers2 << endl;
            if (m.count(mers1) == 0) {
                q.push(Node(mers1, curlen + 1));
                m[mers1] = true;
                printf("%s pushed, len %d\n", mers1.c_str(), curlen + 1);
            }
            if (m.count(mers2) == 0) {
                q.push(Node(mers2, curlen + 1));
                m[mers2] = true;
                printf("%s pushed, len %d\n", mers2.c_str(), curlen + 1);
            }
        }
    }
    return -1;
}

int main()
{
    int N;
    cin >> N;
    string S1, S2, S;
    for (int i = 1; i <= N; i++) {
        cin >> C >> S1 >> S2 >> S;
        // printf("IIII\n");
        cout << i << ' ' << Solve(S1, S2, S) << endl;
    }
    return 0;
}