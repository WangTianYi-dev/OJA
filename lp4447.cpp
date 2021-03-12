#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;
// int a[100005], n;
// int cnt, minn = INT_MAX;
// int lst[100005], len[100005];
// int main()
// {
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//         cin >> a[i];
//     sort(a + 1, a + 1 + n);
//     for (int i = 1; i <= n; i++) { //将组的大小排列
//         bool find = false;
//         int res = 0, maxn = INT_MAX;
//         for (int j = 1; j <= cnt; j++) //从最小组开始，一组一组的找，慢慢寻找最小值。
//             if (lst[j] == a[i] - 1 && len[j] < maxn) {
//                 maxn = len[j];
//                 res = j;
//                 find = true;
//             }
//         if (!find) //开队列进行查找。
//         {
//             lst[++cnt] = a[i];
//             len[cnt] = 1;
//         } else {
//             lst[res] = a[i];
//             len[res]++;
//         }
//     }
//     for (int i = 1; i <= cnt; i++)
//         minn = min(minn, len[i]); //进行比较看哪一种情况更小
//     cout << minn << endl;
//     return 0;
// }

int dat[100005], back[100005], quelen[100005], size;
unordered_map<int, int> m;
int max = INT_MAX;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> dat[i];
    }
    sort(dat + 1, dat + n + 1);

    // for (int i = 1; i <= n; i++) {
    //     cout << dat[i] << ' ';
    // }
    // cout << endl;

    for (int i = 1; i <= n; i++) {
        int minvalue = INT_MAX;
        bool found = false;
        int curloc;
        for (int j = 0; j < ::size; j++) {
            if (back[j] + 1 == dat[i] && quelen[j] < minvalue) {
                minvalue = min(quelen[j], minvalue);
                curloc = j;
                found = true;
            }
        }
        if (!found) {
            back[::size] = dat[i];
            quelen[::size] = 1;
            size++;
        } else {
            back[curloc] = dat[i];
            quelen[curloc]++;
        }
    }
    int minv = INT_MAX;
    for (int i = 0; i < ::size; i++) {
        // cout << back[i] << ' ' << quelen[i] << endl;
        if (quelen[i] < minv) {
            minv = quelen[i];
        }
    }
    
    cout << minv << endl;
    return 0;
}
