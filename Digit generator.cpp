#include <stdio.h>
#define maxn 1000070
long long ans[maxn];
int main()
{
    for (int i = 1; i < maxn; i++) {
        int x = i, y = i;
        while (x > 0) {
            y += x % 10;
            x /= 10;
        }
        if (ans[y] == 0 || i < ans[y])
            ans[y] = i;
    }
    int n;
    scanf("%d", &n);
    int gtor;
    while (n--) {
        scanf("%d", &gtor);
        printf("%d\n",ans[gtor]);
    }
}