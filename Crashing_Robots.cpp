#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#define N 0
#define E 1
#define S 2
#define W 3
#define WALL 10086
#define SAFE 10087
using namespace std;
struct Robot {
    int x, y;
    int state;
    int number;
};

struct Room {
    int cells[110][110];
    vector<Robot> robots;
    int xsize, ysize, numRobots;
    void SetRoom(int x, int y)
    {
        numRobots = 0;
        robots.clear();
        xsize = x;
        ysize = y;
        for (int i = 0; i <= xsize; i++) {
            for (int j = 0; j <= ysize; j++) {
                cells[i][j] = 0;
            }
        }
    }

    void AddRobot(int x, int y, char s)
    {
        cells[x][y] = ++numRobots;
        switch (s) {
        case 'E':
            robots.push_back({ x, y, E, numRobots });
            break;
        case 'N':
            robots.push_back({ x, y, N, numRobots });
            break;
        case 'W':
            robots.push_back({ x, y, W, numRobots });
            break;
        case 'S':
            robots.push_back({ x, y, S, numRobots });
            break;
        }
    }
    // char Turn(int no, char dir)
    // {

    //     switch (dir) {

    //     }
    // }

    int move(int no, char act, int repeat)
    {
        no--;
        if (act != 'F') {
            int tmp = robots[no].state;
            switch (act) {
            case 'L' /* constant-expression */:
                /* code */
                tmp = (tmp + 4 - (repeat % 4)) % 4;
                break;
            case 'R':
                tmp = (tmp + (repeat % 4)) % 4;
                break;
            default:
                break;
            }
            robots[no].state = tmp;
            return SAFE;
        } else {
            int d = robots[no].state, curx = robots[no].x,
                cury = robots[no].y;
            int dir[2];
            switch (d) {
            case N /* constant-expression */:
                /* code */
                dir[0] = 0;
                dir[1] = 1;
                break;
            case E:
                dir[0] = 1;
                dir[1] = 0;
                break;
            case S:
                dir[0] = 0;
                dir[1] = -1;
                break;
            case W:
                dir[0] = -1;
                dir[1] = 0;
                break;
            }
            int newx = curx, newy = cury;
            while (repeat--) {
                newx += dir[0];
                newy += dir[1];
                if (newx <= 0 || newx > xsize || newy <= 0 || newy > ysize) {
                    return WALL;
                } else {
                    if (cells[newx][newy] != 0) {
                        return cells[newx][newy];
                    }
                }
            }
            robots[no].x = newx;
            robots[no].y = newy;
            cells[curx][cury] = 0;
            cells[newx][newy] = robots[no].number;
            return SAFE;
        }
    }
} room;

int main()
{
    int k, n, m;
    cin >> k;
    int sizex, sizey;
    while (k--) {
        cin >> sizex >> sizey;
        room.SetRoom(sizex, sizey);
        cin >> n >> m;
        int x, y;
        char c;
        while (n--) {
            cin >> x >> y >> c;
            room.AddRobot(x, y, c);
        }
        bool pass = false;
        while (m--) {
            cin >> x >> c >> y;
            if (!pass) {
                int rtv;
                if ((rtv = room.move(x, c, y)) != SAFE) {
                    if (rtv == WALL) {
                        printf("Robot %d crashes into the wall\n", x);
                    } else {
                        printf("Robot %d crashes into robot %d\n", x, rtv);
                    }
                    pass = true;
                }
            }
        }
        if (!pass)
            puts("OK");
    }
    return 0;
}
