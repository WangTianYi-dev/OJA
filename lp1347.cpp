#include <algorithm>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 1050;
int n, m;
vector<int> chart[maxn], in(maxn, 0);
bool isInChart[maxn][maxn];
int data[maxn];

struct Node {
    int v, l;
};

int topo()
{
    int ans = 0, top = 0;
    queue<Node> q;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) {
            q.push({ .v = i, .l = 1 });
        }
    }
    while (!q.empty()) {
        Node nd = q.front();
        q.pop();
        ans = max(ans, nd.l);
        for (auto i : chart[nd.v]) {
            in[i]--;
            if (in[i] == 0) {
                q.push({ .v = i, .l = nd.l + 1 });
            }
        }
    }
    return ans;
}

void printChart()
{
    for (int i = 1; i <= n; i++) {
        cout << i << " : ";
        for (int j : chart[i]) {
            cout << j << ' ';
        }
        cout << endl;
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        bool isInData[maxn];
        vector<int> fathers;
        memset(isInData, 0, sizeof(isInData));
        int s;
        cin >> s;
        for (int j = 1; j <= s; j++) {
            cin >> data[j];
            isInData[data[j]] = true;
            fathers.push_back(data[j]);
        }

        for (int k = data[1]; k <= data[s]; k++) {
            if (!isInData[k]) {
                for (auto i : fathers) {
                    if (!isInChart[i][k]) {
                        isInChart[i][k] = true;
                        chart[i].push_back(k);
                        in[k]++;
                    }
                }
            }
        }
    }
#ifdef DEBUG
    printChart();
#endif
    cout << topo() << endl;
    return 0;
}
