#include <stdio.h>
#include <string.h>
const int maxn = 1e5 + 7;

char a[maxn], b[maxn];
char t[maxn];
int l;

void cycle(int x) {
    for (int i = 0; i < l; i++) {
        t[i] = b[(i + x) % l];
    }
}

bool is_cycle() {
    for (int i = 0; i < l; i++) {
        cycle(i);
        if (strcmp(a, t) == 0) return true;
    }
    return false;
}

int main() {
    while (scanf("%s %s", a, b) != EOF) {
        l = strlen(a);
        if (is_cycle()) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}