#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int next[100005];
int a[1000005], b[100005];
int n, m;
void build() {
    int i = 0, j = -1;
    next[0] = -1;
    while (i < m) {
        if (j == -1 || b[i] == b[j]) {
            i++;
            j++;
            next[i] = j;
        } else
            j = next[j];
    }
}
int kmp(int i, int j) {
    while (i < n && j < m) {
        if (a[i] == b[j] || j == -1) {
            i++;
            j++;
        } else
            j = next[j];
    }
    if (j == m)
        return i - j + 1;
    else
        return -1;
}

int main() {
    int i;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    scanf("%d", &m);
    for (i = 0; i < m; i++)
        scanf("%d", &b[i]);
    build();
    int k = kmp(0, 0);
    if (k != -1) {
        int t = kmp(k + m - 1, next[m]);
        if (t == -1)
            printf("%d %d\n", k, k + m - 1);
        else
            printf("-1\n");
    } else
        printf("-1\n");
    return 0;
}
