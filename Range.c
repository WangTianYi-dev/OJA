#include <stdio.h>
#include <stdlib.h>
#define MAX ((int)1e7)
#define max(x, y) ((x > y) ? x : y)
int data[MAX + 100];
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int x;
    int most = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        data[x]++;
    }
    for (int i = 1; i < MAX + 99; i++) {
        data[i] += data[i - 1];
    }
    int a, b;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        if (a == 0) {
            printf("%d\n", data[b] - data[a]);
        } else {
            printf("%d\n", data[b] - data[a - 1]);
        }
    }
    return 0;
}
