// POJ3083
// DFS求靠左墙(右墙)走的路径长+BFS求最短路
// Time:0Ms  Memory:716K
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

#define MAX 45
#define INRANGE(x, y) (x >= 0 && x < n && y >= 0 && y < m)

struct Point {
    int x, y, d;
    Point(int xx, int yy, int dd)
        : x(xx)
        , y(yy)
        , d(dd)
    {
    }
};

int n, m;
int sx, sy;
char mize[MAX][MAX];
bool vis[MAX][MAX];
int mov[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } }; //东南西北

int dfs(int x, int y, int f, int c)
{
    /* 
basic train of thought:
    if rightside: next orientation = current orientation + 1
    if leftside: next orientation = (current orientation + 3) % 4
*/
    if (mize[x][y] == 'E')
        return 1;
    int px = x + mov[(f + c) % 4][0], py = y + mov[(f + c) % 4][1]; //左侧(右侧)
    int fx = x + mov[f][0], fy = y + mov[f][1]; //前侧
    if (mize[px][py] == '.' || mize[px][py] == 'E') {
        f = (f + c) % 4; //向左转(向右转)
        fx = x + mov[f][0], fy = y + mov[f][1];
    }
    while (mize[fx][fy] == '#') {
        f = (f + 4 - c) % 4; //向右转(向左转)
        fx = x + mov[f][0], fy = y + mov[f][1];
    }
    return 1 + dfs(fx, fy, f, c);
}

int bfs(int x, int y)
{
    memset(vis, false, sizeof(vis));
    queue<Point> q;
    q.push(Point(x, y, 1));
    vis[x][y] = true;
    while (!q.empty()) {
        Point cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int tx = cur.x + mov[i][0];
            int ty = cur.y + mov[i][1];
            if (INRANGE(tx, ty) && mize[tx][ty] != '#' && !vis[tx][ty]) {
                if (mize[tx][ty] == 'E')
                    return cur.d + 1;
                q.push(Point(tx, ty, cur.d + 1));
                vis[tx][ty] = true;
            }
        }
    }
    return 0;
}

int main()
{
    // freopen("in.txt","r",stdin);

    int T;
    scanf("%d", &T);
    while (T--) {
        memset(vis, false, sizeof(vis));
        scanf("%d%d", &m, &n);
        for (int i = 0; i < n; i++) {
            scanf("%s", mize[i]);
            for (int j = 0; j < m; j++)
                if (mize[i][j] == 'S')
                    sx = i, sy = j;
        }
        // f means current orientation
        int f = 0;
        for (; f < 4; f++) {
            int fx = sx + mov[f][0], fy = sy + mov[f][1];
            if (INRANGE(fx, fy) && mize[fx][fy] == '.' || mize[fx][fy] == 'E')
                break;
        }

        printf("%d %d %d\n", dfs(sx, sy, f, 3), dfs(sx, sy, f, 1), bfs(sx, sy));
    }
    return 0;
}