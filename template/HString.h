#include <stdlib.h>
#include <string.h>

int *build_next(char *p) {
    size_t m = strlen(p), j = 0;
    int *n = (int *)malloc(m * sizeof(int));
    int t = n[0] = -1;
    while (j < m - 1) {
        if (t < 0 || p[j] == p[t]) {
            j++, t++;
            n[j] = (p[j] != p[t] ? t : n[t]);
        } else {
            t = n[t];
        }
    }
    return n;
}

int match(char *p, char *t) {
    int *next = build_next(p);
    int n = (int)strlen(t), i = 0;
    int m = (int)strlen(p), j = 0;
    while (j < m && i < n)
        if (j < 0 || t[i] == p[j]) {
            i++;
            j++;
        } else
            j = next[j];
    free(next);
    return i - j;
}

