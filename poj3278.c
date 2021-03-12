#include <stdio.h>
#include <string.h>
#define MAX 200010
struct Step {
    int pos, len;
} queue[MAX];
int vis[MAX];
int bfs(int n, int k)
{
    int head = 0, tail = 0;
    queue[tail].pos = n;
    queue[tail].len = 0;
    tail++;
    vis[n] = 1;
    struct Step now, next;
    while (head != tail) {
        now = queue[head++];
        for (int i = 0; i < 3; i++) {
            switch (i) {
            case 0:
                next.pos = now.pos - 1;
                break;
            case 1:
                next.pos = now.pos + 1;
                break;
            case 2:
                next.pos = now.pos * 2;
                break;
            }
            if (next.pos > MAX || vis[next.pos]) {
                continue;
            } else {
                vis[next.pos] = 1;
                next.len = now.len + 1;
                queue[tail++] = next;
            }
            if (next.pos == k) {
                return next.len;
            }
        }
    }
    return 0;
}

int main()
{
    memset(queue, 0, sizeof(queue));
    int n, k;
    scanf(" %d %d", &n, &k);
    if (k < n) {
        printf("%d\n", n - k);
    } else {
        printf("%d\n", bfs(n, k));
    }
}
