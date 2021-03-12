#include <stdio.h>
#define N 100010
typedef struct node {
    int x, step;
} node;
node q[N];
int vis[N];
int bfs(int n, int k)
{
    node now, next;
    int head = 0, tail = 1;
    q[head].x = n;
    q[head].step = 0;
    vis[n] = 1;
    while (head != tail) {
        now = q[head++];
        for (int i = 0; i < 3; i++) {
            if (i == 0)
                next.x = now.x - 1;
            else if (i == 1)
                next.x = now.x + 1;
            else if (i == 2)
                next.x = now.x * 2;
            if (next.x < 0 || next.x > N)
                continue;
            if (!vis[next.x]) {
                vis[next.x] = 1;
                next.step = now.step + 1;
                q[tail++] = next;
            }
            if (next.x == k)
                return next.step;
        }
    }
}
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    if (n >= k)
        printf("%d\n", n - k);
    else
        printf("%d\n", bfs(n, k));
    return 0;
}