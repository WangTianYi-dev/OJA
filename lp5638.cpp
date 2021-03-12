// #include <bits/stdc++.h>
// #define ll long long
// // #define reg register
// //上面这两个没啥用
// using namespace std;
// ll k, n, maxn, sum, a[1000010], num; //开long long是习惯
// int main()
// {
//     cin >> n >> k; //无聊的输入
//     for (int i = 1; i < n; ++i) { //注意是小于n，因为n是点数，a[]存储的是距离
//         //上面那个reg没有影响，忽略不计
//         cin >> a[i];
//         num += a[i]; //这个是总长度
//         if (i <= k) { //在选取的区间长度小于k时
//             sum += a[i];
//         }
//         if (i > k) { //在长度大于k时，我们就要把新的加进来，前面的点减出去
//             sum += a[i]; //加上新的
//             sum -= a[i - k]; //减去旧的
//         }
//         maxn = max(maxn, sum); //更新
//     }
//     cout << num - maxn; //输出
//     return 0; //完结撒花
// }
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k, fin, sum, a[1000010], num;

int main()
{
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        cin >> a[i];
        num += a[i];
        if (i <= k) {
            sum += a[i];
        }
        if (i > k) {
            sum += a[i];
            sum -= a[i - k];
        }
        fin = max(fin, sum);
    }
    cout << num - fin << endl;
    return 0;
}