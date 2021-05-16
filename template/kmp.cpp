#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxn 1000007

char t[maxn], p[maxn];
int next[maxn];
int lt, lp;

void build_next() {
    int i = 0;
    int t = next[0] = -1;
    while (i < lp) {
        if (t == -1 || p[i] == p[t]) {
            next[++i] = ++t;
        } else {
            t = next[t];
        }
    }
}

void match() {
    build_next();
    int i = 0, j = 0;
    while (i < lt) {
        if (j == -1 || t[i] == p[j]) {
            i++, j++;
        } else {
            j = next[j];
        }
        if (j == lp) {
            printf("%d\n", i - j + 1);
            j = next[j];
        }
    }
}

int main() {
    scanf("%s", t);
    scanf("%s", p);
    lt = strlen(t), lp = strlen(p);
    match();
    for (int i = 1; i <= lp; i++) {
        printf("%d ", next[i]);
    }
    return 0;
}