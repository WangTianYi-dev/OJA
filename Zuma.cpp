#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxn = 2e4 + 100;
bool vis[maxn];
char str[maxn];
int m, pos;

struct no {
    int num;
    char ch;
} st[maxn];

void ins(int pos, char op) {
    int len = strlen(str + 1);
    str[len + 2] = '\0';
    for (int i = len + 1; i > pos + 1; i--) {
        str[i] = str[i - 1];
    }
    str[pos + 1] = op;
}


void _delete() {
    int len = strlen(str + 1);
    int tot = 0;
    for (int i = 1; i <= len; i++) {
        if (tot == 0) {
            tot++;
            st[tot].num = 1;
            st[tot].ch = str[i];
        } else if (st[tot].ch == str[i]) {
            st[tot].num++;
        } else if (st[tot].ch != str[i]) {
            if (st[tot].num >= 3) {
                tot--;
                if (tot != 0 && st[tot].ch == str[i]) {
                    st[tot].num++;
                } else {
                    tot++;
                    st[tot].ch = str[i];
                    st[tot].num = 1;
                }
            } else {
                tot++;
                st[tot].num = 1;
                st[tot].ch = str[i];
            }
        }
    }
    if (tot != 0 && st[tot].num >= 3) tot--;
    int cnt = 1;
    for (int i = 1; i <= tot; i++) {
        for (int j = 0; j < st[i].num; j++) {
            str[cnt++] = st[i].ch;
        }
    }
    str[cnt] = '\0';
}

int main() {
    char op;
    cin.getline(str + 1, maxn - 2);
    scanf("%d", &m);
    while (m--) {
        scanf("%d %c", &pos, &op);
        ins(pos, op);
        _delete();
        if (strlen(str + 1) == 0) {
            printf("-\n");
        } else {
            printf("%s\n", str + 1);
        }
    }
    return 0;
}