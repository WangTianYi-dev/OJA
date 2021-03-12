#include <cstring>
#include <iostream>
using namespace std;

struct chess {
  char t;
  int x, y;
};

int n;
chess c[8];
chess gnr;
char tab0[11][11], tab[11][11]; //[10][9]

//在check函数中有j/2 所以mov和movh中的坐标需要对应
int mov[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int movh[8][2] = {{-1, 2}, {1, 2},   {2, 1},   {2, -1},
                  {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}};
/*
movh中0，1对应mov中0，movh中2，3对应mov中1...
*/
bool legal(int x, int y) { return 1 <= x && x <= 3 && 4 <= y && y <= 6; }

int cnt(chess p1, chess p2) {
  // count the num of chess between p1 and p2 on stright line
  // return -1 when p1 p2 are not on a line
  int cnt = 0;
  if (p1.x == p2.x) {
    // if on the same x
    int add = p1.y < p2.y ? 1 : -1;
    for (int i = p1.y + add; i != p2.y; i += add) {
    // from p1.y to p2.y
    // 
      if (tab[p1.x][i] != '0')
        cnt++;
    }
  } else if (p1.y == p2.y) {
    int add = p1.x < p2.x ? 1 : -1;
    for (int i = p1.x + add; i != p2.x; i += add) {
      if (tab[i][p1.y] != '0')
        cnt++;
    }
  } else
    cnt = -1;
  return cnt;
}

bool check() {
  // false when hongjiang is under attack
  for (int i = 1; i <= n; i++) {
    if (c[i].x == c[0].x && c[i].y == c[0].y)
    // if chess[i] is eaten by heijiang
      continue;
    if (c[i].t == 'R' || c[i].t == 'G') {
    // 为车或帅时
    // no chess between them
      if (cnt(c[i], c[0]) == 0)
        return false;
    }
    if (c[i].t == 'C') {
    // when is Pao
    // one chess between them
      if (cnt(c[i], c[0]) == 1)
        return false;
    }
    if (c[i].t == 'H') {
    // when is Ma

      for (int j = 0; j < 8; j++) {
        if (c[i].x + movh[j][0] == c[0].x && c[i].y + movh[j][1] == c[0].y 
        // Ma can tread it
        &&  tab[c[i].x + (mov[j / 2][0])][c[i].y + (mov[j / 2][1])] == '0')
        // without being bied
          return false;
      }
    }
  }
  return true;
}

int main() {
  while (cin >> n >> gnr.x >> gnr.y && (n || gnr.x || gnr.y)) {
    memset(tab0, '0', sizeof(tab0));
    tab0[gnr.x][gnr.y] = '1';
    for (int i = 1; i <= n; i++) {
      cin >> c[i].t >> c[i].x >> c[i].y;
      tab0[c[i].x][c[i].y] = c[i].t;
    }

    bool res = true;
    for (int i = 0; i < 4; i++) {
      // tab0为备份
      memcpy(tab, tab0, sizeof(tab0));
      c[0].x = gnr.x + mov[i][0];
      c[0].y = gnr.y + mov[i][1];
      if (!legal(c[0].x, c[0].y))
        continue;
    // 红将本身的位置并不重要，它能走的位置才重要，如果没有能走的位置，就算本身位置安全也不行。
      tab[c[0].x][c[0].y] = '1';
      tab[gnr.x][gnr.y] = '0';
      if (check()) {
        res = false;
        break;
      }
    }
    if (res)
    
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}