#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
int a[410][410];
bool b[410][410];
int m, n;
int dx[8] = { 2, -2, 2, -2, -1, 1, -1, 1 },
    dy[8] = { 1, 1, -1, -1, 2, 2, -2, -2 }; //方向

struct Node {
    int x, y, step;
};

bool valid(int x, int y)
{
    return x > 0 && x <= n && y > 0 && y <= m && !b[x][y];
}

void bfs(int x, int y)
{
    a[x][y] = 0;
    b[x][y] = true;
    queue<Node> q;
    Node n = { x, y, 0 };
    q.push(n);
    while (!q.empty()) {
        n = q.front();
        q.pop();
        int curx = n.x;
        int cury = n.y;
        int curstep = n.step;
        for (int i = 0; i < 8; i++) {
            int newx = curx + dx[i], newy = cury + dy[i];
            if (valid(newx, newy)) {
                Node n = { newx, newy, curstep + 1 };
                // printf("(%d, %d) pushed, step: %d\n", newx, newy, curstep + 1);
                q.push(n);
                a[newx][newy] = curstep + 1;
                b[newx][newy] = true;
            }
        }
    }
}

int main()
{
    memset(a, -1, sizeof(a));
    int x, y;
    cin >> n >> m >> x >> y;
    bfs(x, y);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%-5d", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
