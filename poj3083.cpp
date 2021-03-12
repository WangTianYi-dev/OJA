#include <cstdio>
#include <iostream>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;
int numRow, numCol;
#define INSIDE(x, y) (x >= 0 && y >= 0 && x < numRow && y < numCol)
char map[50][50];
// orientation: 0:east 1:south 2:west 3:north
int movex[] = { 0, 1, 0, -1 };
int movey[] = { 1, 0, -1, 0 };
#define RIGHT 1
#define LEFT 3
// type: 1:right 3:left
int dfs(int x, int y, int orient, int type)
{
    // printf("CurPoint(%d, %d)\n", x, y);
    if (map[x][y] == 'E') {
        return 1;
    }
    int nextPos[2];
    int nextOrient = (orient + type) % 4;
    nextPos[0] = x + movex[nextOrient];
    nextPos[1] = y + movey[nextOrient];
    while (INSIDE(nextPos[0], nextPos[1])
        && map[nextPos[0]][nextPos[1]] == '#') {
        nextOrient = (nextOrient + (4 - type)) % 4;
        nextPos[0] = x + movex[nextOrient];
        nextPos[1] = y + movey[nextOrient];
    }
    return 1 + dfs(nextPos[0], nextPos[1], nextOrient, type);
}

struct Point {
    int x, y, len;
    Point(int x, int y, int len)
        : x(x)
        , y(y)
        , len(len)
    {
    }
};

bool visited[50][50];
// int bfs(int x, int y)
// {
//     memset(visited, false, sizeof(visited));
//     queue<Point> q;
//     q.push(Point(x, y, 1));
//     visited[x][y] = true;
//     while (!q.empty()) {
//         Point cur = q.front();
//         q.pop();
//         for (int i = 0; i < 4; i++) {
//             int tx = cur.x + movex[i];
//             int ty = cur.y + movey[i];
//             if (INSIDE(tx, ty) && map[tx][ty] != '#' && !visited[tx][ty]) {
//                 if (map[tx][ty] == 'E')
//                     return cur.len + 1;
//                 q.push(Point(tx, ty, cur.len + 1));
//                 visited[tx][ty] = true;
//             }
//         }
//     }
//     return 0;
// }

int bfs(int x, int y)
{
    memset(visited, 0, sizeof(visited));
    queue<Point> q;
    q.push(Point(x, y, 1));
    int curx = x, cury = y, curlen = 1;
    visited[x][y] = true;
    while (!q.empty()) {
        Point curp = q.front();
        q.pop();
        curx = curp.x, cury = curp.y, curlen = curp.len;
        // printf("CurPoint(%d, %d), CurLen:%d\n", curx, cury, curlen);
        // visited[curx][cury] = true;
        if (map[curx][cury] == 'E') {
            return curlen;
        } else {
            for (int i = 0; i < 4; i++) {
                int nextx = curx + movex[i];
                int nexty = cury + movey[i];
                if (INSIDE(nextx, nexty)
                    && !visited[nextx][nexty]
                    && map[nextx][nexty] != '#') {
                    q.push(Point(nextx, nexty, curlen+1));
                    visited[nextx][nexty] = true;
                }
            }
        }
    }
    return 0;
}

int main()
{
    int T;
    cin >> T;
    int sx, sy;
    while (T--) {
        cin >> numCol >> numRow;
        for (int i = 0; i < numRow; i++) {
            for (int j = 0; j < numCol; j++) {
                cin >> map[i][j];
                if (map[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }
            }
        }
        int f = 0;
        for (; f < 4; f++) {
            int fx = sx + movex[f], fy = sy + movey[f];
            if (INSIDE(fx, fy) && (map[fx][fy] == '.' || map[fx][fy] == 'E'))
                break;
        }
        printf("%d %d %d\n", dfs(sx, sy, f, 3), dfs(sx, sy, f, 1), bfs(sx, sy));
    }
    return 0;
}
