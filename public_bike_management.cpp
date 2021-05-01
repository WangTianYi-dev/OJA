#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 110;
int cmax, n, m, sp;
int c[maxn], lth[maxn][maxn];
int send, rtn;
vector<vector<int>> lst;
vector<int> hist;
struct node {
    int len;
    int bikes;
    vector<int> hs;
};
vector<node> ans;
int minDis = 0x7fffffff;
int curBike = 0;
bool visited[maxn];
int needBike(int p) { return cmax / 2 - c[p]; }

void dfs(int cur, int tar, int dis) {
    visited[cur] = true;
    hist.push_back(cur);
    curBike += needBike(cur);
    // send = max(curBike, send);
    // printf("cur: %d, send: %d\n", cur, send);
    if (dis > minDis) {
        return;
    }
    if (cur == tar) {
        // curBike -= needBike(cur);
        minDis = dis;
        if (!ans.empty() && minDis < ans.back().len) {
            ans.clear();
        }
        // printf("minDis: %d, curBike: %d\n", minDis, curBike);
        ans.push_back({minDis, curBike, hist});
        return;
    }
    // cout << "this: " << cur << endl;
    if (dis > minDis) {
        return;
    }
    for (auto i : lst[cur]) {
        if (!visited[i]) {
            // visited[i] = true;
            // hist.push_back(i);
            // curBike += needBike(i);
            // cout << "goto: " << i << endl;
            dfs(i, tar, dis + lth[cur][i]);
            hist.pop_back();
            visited[i] = false;
            curBike -= needBike(i);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin >> cmax >> n >> sp >> m;
    c[0] = cmax / 2;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    lst = vector<vector<int>>(n + 1, vector<int>());
    int si, sj, sij;
    for (int i = 1; i <= m; i++) {
        cin >> si >> sj >> sij;
        lst[sj].push_back(si);
        lst[si].push_back(sj);
        lth[sj][si] = sij;
        lth[si][sj] = sij;
    }
    // curBike = needBike(sp);
    dfs(0, sp, 0);
    int p = 0;
    for (int i = 0, l = ans.size(); i < l; i++) {
        if (ans[i].bikes < ans[p].bikes) {
            p = i;
        }
    }
    vector<int> &hs = ans[p].hs;
    int bk = 0;
    for (auto i : hs) {
        bk += needBike(i);
        send = max(send, bk);
    }
    cout << send << ' ';
    for (auto i = hs.begin(); i != hs.end() - 1; i++) {
        cout << *i << "->";
    }
    cout << *(hs.end() - 1) << ' ';
    // cout << "bk: " << bk << endl;
    rtn = send;
    for (auto i : hs) {
        rtn -= needBike(i);
    }
    cout << rtn << '\n';
    return 0;
    // cout <<
}