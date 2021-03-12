#include <stdio.h>

#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define WALL 1
#define ROAD 0
#define PASSED 2

int map[10][10], curPos, tempPath[100][2];

int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
struct Path {
  int p[100][2];
  int len;
} paths[100];

struct Elem {
  int x, y, len;
  bool did;
  Elem(){};
  Elem(int x, int y, int len, bool did) : x(x), y(y), len(len), did(did) {}
} pathstack[1000];
int top = 0;

void printmap() {
  for (int i = 1; i <= 5; i++) {
    for (int j = 1; j <= 5; j++) {
      cout << map[i][j] << ' ';
    }
    cout << endl;
  }
}

void solve() {
  tempPath[0][0] = 1;
  tempPath[0][1] = 1;
  pathstack[top] = Elem(1, 1, 1, false);
  map[pathstack[top].x][pathstack[top].y] = PASSED;
  while (~top) {
    int curx = pathstack[top].x, cury = pathstack[top].y,
        len = pathstack[top].len;
    if (curx == 5 && cury == 5) {
      // printf("VICTORY:\ncurPos:%d len:%d numstack: %d curx: %d cury: %d\n",
            //  curPos, len, top, curx, cury);
      paths[curPos].len = len;
      for (int i = 0; i < len; i++) {
        paths[curPos].p[i][0] = tempPath[i][0];
        paths[curPos].p[i][1] = tempPath[i][1];
      }
      paths[curPos].p[len-1][0] = 5;
      paths[curPos].p[len-1][1] = 5;
      curPos++;
      top--;
      map[curx][cury] = ROAD;
    } else {
      if (!pathstack[top].did) {
        pathstack[top].did = true;
        tempPath[len - 1][0] = curx;
        tempPath[len - 1][1] = cury;
        // printf("len:%d numstack: %d curx: %d cury: %d\n", len, top, curx, cury);
        // printmap();
        for (int i = 0; i < 4; i++) {
          int tx = curx + dir[i][0], ty = cury + dir[i][1];
          // printf("Enquired %d %d ", tx, ty);
          if (map[tx][ty] != WALL && map[tx][ty] != PASSED) {
            // printf("is ROAD\n");
            map[tx][ty] = PASSED;
            pathstack[++top] = Elem(tx, ty, len + 1, false);
          } else {
            // printf("is WALL\n");
          }
        }
      } else {
        map[curx][cury] = ROAD;
        top--;
      }
    }
  }
}

// void dfs(int x, int y, int len) {
//   if (x == 5 && y == 5) {
//     paths[curPos].len = len;
//     for (int i = 0; i < len; i++) {
//       paths[curPos].p[i][0] = tempPath[i][0];
//       paths[curPos].p[i][1] = tempPath[i][1];
//       // cout << paths[curPos].p[i][0] << ' ' << paths[curPos].p[i][0] <<
//       endl;
//     }
//     curPos++;
//     return;
//   } else {
//     for (int i = 0; i < 4; i++) {
//       int dx = x + dir[i][0], dy = y + dir[i][1];
//       if (map[dx][dy] != WALL) {
//         map[dx][dy] = WALL;
//         tempPath[len][0] = dx;
//         tempPath[len][1] = dy;
//         dfs(dx, dy, len + 1);
//         map[dx][dy] = ROAD;
//       }
//     }
//   }
// }

int main() {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      map[i][j] = WALL;
    }
  }
  for (int i = 1; i <= 5; i++) {
    for (int j = 1; j <= 5; j++) {
      cin >> map[i][j];
    }
  }
  int ans = 0;
  solve();
  for (int i = 0; i < curPos; i++) {
    if (paths[i].len < paths[ans].len)
      ans = i;
  }
  // cout << ans << endl;
  // cout << paths[ans].len << endl;
  for (int i = 0; i < paths[ans].len; i++) {
    cout << '(' << paths[ans].p[i][0]-1 << ", " << paths[ans].p[i][1]-1
         << ')' << endl;
  }
  return 0;
}