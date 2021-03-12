#include <bits/stdc++.h>
using namespace std;
constexpr char B = 'B';
constexpr char W = 'W';
typedef struct Point {
  int x, y;
  Point(){};
  Point(int a, int b) : x(a), y(b){};
  Point operator+(Point p) {
    Point rp;
    rp.x = x + p.x;
    rp.y = y + p.y;
    return rp;
  }
  bool operator==(Point p) { return p.x == x && p.y == y; }

} Vector;

bool operator<(const Point p1, const Point p2) {
  return (p1.x == p2.x) ? p1.y < p2.y : p1.x < p2.x;
}

Vector operator*(int i, Vector v) {
  v.x = v.x * i;
  v.y = v.y * i;
  return v;
}

vector<Vector> MV = {{1, 0},  {1, 1},   {0, 1},  {-1, 1},
                     {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

char BOARD[10][10];

void PrintBoard() {
  //puts("PrintBoard:\n");
  for (int i = 1; i <= 8; i++) {
    for (int j = 1; j <= 8; j++) {
      printf("%c", BOARD[i][j]);
    }
    putchar('\n');
  }
}

bool Availiable(Point p) { return p.x <= 8 && p.x > 0 && p.y <= 8 && p.y > 0; }

// 长度为8，每一位代表一个方向的可行距离，为0则不行
vector<int> getDirLen(char Player, Point curP) {
  Point tp = curP;
  vector<int> dirlen;
  char enemy = (Player == W) ? B : W;
  for (int i = 0; i < 8; i++) {
    Vector mv = MV[i];
    tp = tp + mv;
    if (BOARD[tp.x][tp.y] != enemy || !Availiable(tp)) {
      dirlen.push_back(0);
    } else {
      int len;
      for (len = 1; BOARD[tp.x][tp.y] == enemy; len++) {
        tp = tp + mv;
      }
      if (Availiable(tp) && BOARD[tp.x][tp.y] == '-') {
        dirlen.push_back(len);
      } else {
        dirlen.push_back(0);
      }
    }
    tp = curP;
  }
  return dirlen;
}

vector<Point> getDirPoint(char Player, Point curP) {
  vector<int> dirLen = getDirLen(Player, curP);
  vector<Point> vp;
  for (int i = 0; i < 8; i++) {
    if (dirLen[i] == 0)
      continue;
    else {
      vp.push_back(curP + (dirLen[i] * MV[i]));
    }
  }
  return vp;
}

vector<Point> initSump(char Player) {
  vector<Point> sumP;
  //PrintBoard();
  for (int i = 1; i <= 8; i++) {
    for (int j = 1; j <= 8; j++) {
      if (BOARD[i][j] == Player) {
        vector<Point> tv = getDirPoint(Player, Point(i, j));
        sumP.insert(sumP.end(), tv.begin(), tv.end());
      }
    }
  }
  sort(sumP.begin(), sumP.end());
  sumP.erase(unique(sumP.begin(), sumP.end()), sumP.end());
  // for (int i = 1; i < 4; i++) {
  //   bool b = (sumP[i - 1] < sumP[i]);
  //   cout << b << endl;
  // }
  // set<Point> st(sumP.begin(), sumP.end());
  return sumP;
}

void LuoZi(char Player, Point p) {
  BOARD[p.x][p.y] = Player;
  char enemy = (Player == W) ? B : W;
  for (int i = 0; i < 8; i++) {
    Point tp = p + MV[i];
    if (BOARD[tp.x][tp.y] == Player || BOARD[tp.x][tp.y] == '-' || !Availiable(tp))
      continue;
    while (BOARD[tp.x][tp.y] == enemy) {
      tp = tp + MV[i];
    }
    if (BOARD[tp.x][tp.y] != Player)
      continue;
    else {
      Point pp = p;
      while (!(pp == tp)) {
        BOARD[pp.x][pp.y] = Player;
        pp = pp + MV[i];
      }
    }
  }
}

int main() {
  int T;
  scanf(" %d ", &T);
  char tmpLine[10];
  while (T--) {
    memset(BOARD, 0, sizeof(BOARD));
    for (int i = 0; i < 8; i++) {
      scanf("%s",tmpLine);
      for (int j = 0; j < 8; j++) {
        BOARD[i + 1][j + 1] = tmpLine[j];
      }
    }

    scanf("%s", tmpLine);
    char Player;
    if (tmpLine[0] == 'W') {
      Player = W;
    } else {
      Player = B;
    }
    while (tmpLine[0] != 'Q') {
      // printf("TEST\n");
      // PrintBoard();
      scanf("%s", tmpLine);
      vector<Point> sumP;
      sumP = initSump(Player);
      if (tmpLine[0] == 'L') {
        if (sumP.size() == 0) {
          printf("No legal move.\n");
          Player = (Player == B) ? W : B;
          sumP = initSump(Player);
        } else {
          int j = 0;
          for (auto i : sumP) {
            if (j)
              putchar(' ');
            printf("(%d,%d)", i.x, i.y);
            j++;
          }
          putchar('\n');
        }
      } else if (tmpLine[0] == 'M') {
        Point p(tmpLine[1] - '0', tmpLine[2] - '0');
        LuoZi(Player, p);
        int cntW = 0, cntB = 0;
        for (int i = 1; i <= 8; i++) {
          for (int j = 1; j <= 8; j++) {
            if (BOARD[i][j] == B)
              cntB++;
            else if (BOARD[i][j] == W)
              cntW++;
          }
        }
        printf("Black -%3d White -%3d\n", cntB, cntW);
        Player = (Player == B) ? W : B;
      }
      
    }
    PrintBoard();
    if (T != 0)
      putchar('\n');
  }
  return 0;
}
