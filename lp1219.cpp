#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 15;
const int maxsol = (int)1e5;
int N;
int queens[maxn]={}, cols[maxn]={}, dias1[2*maxn]={}, dias2[3*maxn]={};
int ans[maxsol][maxn]={{}}, curans;
void find(int cur)
{
    if (cur == N) {
        for (int i = 0; i < N; i++) {
            ans[curans][i] = queens[i]+1;
        }
        curans++;
    } else {
        for (int i = 0; i < N; i++) {
            // cout << "curpoint:(" << cur+1 << ", " << i+1 << ")" << endl; 
            if (cols[i] != 0) {
                continue;
            }
            int d1 = cur + i, d2 = cur - i + maxn;
            if (dias1[d1] != 0 || dias2[d2] != 0) {
                continue;
            }
            queens[cur] = i;
            cols[i] = 1;
            dias1[d1] = 1;
            dias2[d2] = 1;
            // cout << "getnext" << endl;
            find(cur+1);
            queens[cur] = 0;
            cols[i] = 0;
            dias1[d1] = 0;
            dias2[d2] = 0;
        }
    }
}

int main()
{
    cin >> N;
    find(0);
    int numsol = min(3, curans);
    for (int i = 0; i < numsol; i++) {
        for (int j = 0; j < N; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << curans << endl;
    return 0;
}
