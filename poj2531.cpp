#include <iostream>
using namespace std;

const int MAX_N = 20;
int n;
int map[MAX_N + 1][MAX_N + 1];
bool in_group[MAX_N + 1];
int ans;

void dfs(int id, int cur_sum)
{
    in_group[id] = true;
    int tmp_sum = cur_sum;
    for (int i = 1; i <= n; i++) {
        if (in_group[i]) {
            tmp_sum -= map[id][i];
        } else {
            tmp_sum += map[id][i];
        }
    }
    if (tmp_sum > ans) {
        ans = tmp_sum;
    }
    if (tmp_sum > cur_sum) {
        for (int i = id + 1; i <= n; i++) {
            dfs(i, tmp_sum);
        }
    }
    in_group[id] = false;
}

int main()
{
    cin >> n;
    memset(in_group, 0, sizeof(in_group));
    ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];
        }
    }
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}