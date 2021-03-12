// #include <cstdio>
// #include <cstring>
// #include <iostream>
// using namespace std;

// int n, a[205], g[205][205], pre[205], t, f[205], ans;

// void print(int x)
// {
//     if (pre[x] == 0) {
//         printf("%d", x);
//         return;
//     }
//     print(pre[x]);
//     printf(" %d", x);
// }

// int main()
// {
//     scanf("%d", &n);
//     for (int i = 1; i <= n; i++)
//         scanf("%d", a + i);
//     for (int i = 1; i < n; i++) {
//         for (int j = i + 1; j <= n; j++) {
//             int x;
//             scanf("%d", &x);
//             if (x == 1)
//                 g[i][j] = 1;
//         }
//     }
//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= n; j++) {
//             if (g[j][i] && f[j] > f[i]) {
//                 f[i] = f[j];
//                 pre[i] = j;
//             }
//         }
//         f[i] += a[i];
//         if (f[i] > ans) {
//             ans = f[i];
//             t = i;
//         }
//     }
//     print(t);
//     printf("\n%d", ans);
//     return 0;
// }

#include <iostream>
#include <cstdio>
using namespace std;

const int maxn = 25;
int n;
int a[maxn] = {}, f[maxn] = {}, pre[maxn] = {}, m[maxn][maxn] = {};


void print(int c) {
    if (pre[c] == 0) {
        printf("%d", c);
    } else {
    print(pre[c]);
    printf(" %d", c);
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            cin >> m[i][j];
        }
    }
    int ans = 0;
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (m[j][i] && f[j] > f[i]) {
                f[i] = f[j];
                pre[i] = j;
            }
        }
        f[i] += a[i];
        if (f[i] > ans) {
            ans = f[i];
            cur = i;
        }
    }
    print(cur);
    printf("\n%d\n", ans);
    return 0;
}

