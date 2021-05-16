#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXL 1000007

char p[MAXL], t[MAXL];
int next[MAXL];
int n, m, i, j;
void build_next(int l) {
    // int *n = (int *)malloc(l * sizeof(int)), j = 0;
    int j = 0;
    int t = next[0] = -1;
    while (j < l - 1) {
        if (t < 0 || p[t] == p[j]) {
            j++;
            t++;
            next[j] = (p[j] == p[t] ? next[t] : t);
        } else {
            t = next[t];
        }
    }
    // return n;
}

int match() {
    n = (int)strlen(t), i = 0;
    m = (int)strlen(p), j = 0;
    build_next(m);
    while (j < m && i < n) {
        if (j < 0 || t[i] == p[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
    }
    return i - j;
}

int main() {
    while (scanf("%s%s", t, p) != EOF) {
        int m = match();
        if (m == n) {
            printf("-1\n");
        } else {
            printf("%d\n", m + 1);
        }
    }
    return 0;
}