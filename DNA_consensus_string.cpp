#include <iostream>
#include <string>
#include <vector>

using namespace std;

int SumDis(char c, vector<string> vs, int loc)
{
    int rt = 0;
    for (auto i : vs) {
        if (i[loc] != c) {
            rt++;
        }
    }
    return rt;
}

char bases[4] = { 'A', 'C', 'G', 'T' };

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, b;
        scanf("%d %d", &n, &b);
        vector<string> dats;
        string tstr;
        while (n--) {
            cin >> tstr;
            dats.push_back(tstr);
        }
        string ans;
        int anssum = 0;
        for (int i = 0; i < b; i++) {
            int minDis = 10000;
            char minchar = '*';
            for (auto j : bases) {
                int curDis = SumDis(j, dats, i);
                if (curDis < minDis) {
                    minDis = curDis;
                    minchar = j;
                }
            }
            anssum += SumDis(minchar, dats, i);
            ans += minchar;
        }
        cout << ans << '\n';
        cout << anssum << '\n';
    }
    return 0;
}