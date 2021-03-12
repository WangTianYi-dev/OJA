#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int MAX = 25;
typedef struct Point {
    int x, y, step, bitkeystate;
} Point;

char map[MAX + 1][MAX + 1];
bool visited[MAX + 1][MAX + 1][10086];
int n, m, t;
int sx, sy, tx, ty;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
bool legal(int x, int y)
{
    bool l = 0 <= x && x < n && 0 <= y && y < m && map[x][y] != '*';
    // cout << l << endl;
    return l;
}

void printmap()
{
    cout << "MAP:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << map[i][j];
        }
        cout << endl;
    }
}

int search()
{
    queue<Point> q;
    Point p = { sx, sy, 0, 0 };
    q.push(p);
    visited[sx][sy][0] = true;
    while (!q.empty()) {
        p = q.front();
        q.pop();
        int cx = p.x, cy = p.y, cs = p.step, bitck = p.bitkeystate;
        if (t <= cs) {
            // cout << "DEAD!" << endl;
            return -1;
        }
        if (cx == tx && cy == ty) {
            return cs;
        }
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i], ny = cy + dy[i];
            // printf("considering (%d, %d, %d, %d)\n", nx, ny, cs + 1, bitck);

            if (legal(nx, ny) && !visited[nx][ny][bitck]) {
                int curs = bitck;

                char cp = map[nx][ny];
                if ('a' <= cp && cp <= 'j') {
                    curs = curs | (1 << (cp - 'a'));
                }
                bool able = true;
                if ('A' <= cp && cp <= 'J') {
                    able = 1 << (cp - 'A') & curs;
                }
                if (able) {
                    Point p = { nx, ny, cs + 1, curs };
                    q.push(p);
                    visited[nx][ny][curs] = true;
                    // printf("(%d, %d, %d, %d) is pushed\n", nx, ny, cs + 1, curs);
                }
                // else {
                // printf("(%d, %d, %d, %d) is blocked, cp is %c\n", nx, ny, cs + 1, curs, cp);
                // }
            }
        }
    }
    // cout << "DEAD!" << endl;
    return -1;
}

int main()
{
    while (scanf(" %d %d %d", &n, &m, &t) != EOF) {
        memset(map, 0, sizeof(map));
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf(" %c", &map[i][j]);
                if (map[i][j] == '@') {
                    sx = i, sy = j;
                    map[i][j] = '.';
                } else if (map[i][j] == '^') {
                    tx = i, ty = j;
                    map[i][j] = '.';
                }
            }
        }
        // printmap();
        printf("%d\n", search());
    }
    return 0;
}

// #include <algorithm>
// #include <cstdio>
// #include <cstring>
// #include <iostream>
// #include <queue>
// using namespace std;
// const int MAX = 25;
// struct point {
//     int x, y, step, state;
//     point(int x = 0, int y = 0, int step = 0, int state = 0)
//         : x(x)
//         , y(y)
//         , step(step)
//         , state(state) {};
// };
// // char g[MAX][MAX];
// // int vis[MAX][MAX][1025];
// // int dirx[4] = { 0, 1, 0, -1 };
// // int diry[4] = { 1, 0, -1, 0 };
// // int n, m, t;
// // int sx, sy, ex, ey;
// // bool judgein(int x, int y)
// // {
// //     return 0 <= x && x < n && 0 <= y && y < m;
// // }
// // int bfs()
// // {
// //     memset(vis, 0, sizeof(vis));
// //     queue<point> que;
// //     vis[sx][sy][0] = 1;
// //     que.push(point(sx, sy, 0, 0));
// //     while (!que.empty()) {
// //         point top = que.front();
// //         que.pop();
// //         int x = top.x;
// //         int y = top.y;
// //         int step = top.step;
// //         int state = top.state;
//         if (step >= t) {
//             return -1;
//         }
//         if (x == ex && y == ey) {
//             return step;
//         }
//         for (int i = 0; i < 4; i++) {
//             int nx = x + dirx[i];
//             int ny = y + diry[i];
//             int nstep = step + 1;
//             int nstate = state;
//             if (judgein(nx, ny) && g[nx][ny] != '*' && !vis[nx][ny][nstate]) {
//                 if (g[nx][ny] == '.') {
//                     vis[nx][ny][nstate] = 1;
//                     que.push(point(nx, ny, nstep, nstate));
//                 } else if (g[nx][ny] >= 'A' && g[nx][ny] <= 'J') {
//                     int key = nstate & (1 << (g[nx][ny] - 'A'));
//                     if (key) {
//                         vis[nx][ny][nstate] = 1;
//                         que.push(point(nx, ny, nstep, nstate));
//                     }
//                 } else if (g[nx][ny] >= 'a' && g[nx][ny] <= 'j') {
//                     nstate = nstate | (1 << (g[nx][ny] - 'a'));
//                     vis[nx][ny][nstate] = 1;
//                     que.push(point(nx, ny, nstep, nstate));
//                 }
//             }
//         }
//     }
//     return -1;
// }
// int main()
// {
//     //freopen("in.txt","r",stdin);
//     //freopen("out.txt","w",stdout);
//     while (scanf("%d%d%d", &n, &m, &t) != EOF) {
//         getchar();
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 scanf("%c", &g[i][j]);
//                 if (g[i][j] == '@') {
//                     sx = i;
//                     sy = j;
//                     g[i][j] = '.';
//                 }
//                 if (g[i][j] == '^') {
//                     ex = i;
//                     ey = j;
//                     g[i][j] = '.';
//                 }
//             }
//             getchar();
//         }
//         /*        for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 printf("%c",g[i][j]);
//             }
//             printf("\n");
//         }
//         printf("%d %d\n",sx,sy);*/
//         int ans = bfs();
//         printf("%d\n", ans);
//     }
//     return 0;
// }