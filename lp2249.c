#include <stdio.h>
#define maxn ((int)1e6 + 10)
int N, M;
int dat[maxn];
// int find(int n)
// {
//     int lo = 1, hi = N;
//     int mi;
//     do {
//         mi = (hi + lo) >> 1;
//         if (dat[mi] == n) {
//             return mi;
//         } else {
//             if (n < dat[mi]) {
//                 hi = mi;
//             } else {
//                 lo = mi + 1;
//             }
//         }
//     } while (lo < hi);
//     return -1;
// }
int find(int x) //二分查找
{
    int l = 1, r = N;
    while (l < r) {
        int mid = (l + r) >> 1;
        // if (dat[mid] == x) return mid;
        if (dat[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }

    if (dat[l] == x)
        return l; //找都了就输出他的位置
    else
        return -1; // 没找到输出-1
}
int main()
{
    scanf(" %d %d", &N, &M);
    for (int i = 1; i <= N; i++) {
        scanf(" %d", dat + i);
        // printf("%d\n", i);
    }
    int t;
    for (int i = 1; i <= M; i++) {
        scanf(" %d", &t);
        printf("%d ", find(t));
    }
    puts("");
    return 0;
}