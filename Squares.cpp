#include <cstdio>
#include <cstring>

using namespace std;
// h[i][j] shows if there is a horizontal line start from
// dot[i][j] to dot[i][j+1]
// v[i][j] shows if there is a vertical line start from
// dot[i][j] to dot[i+1][j]
bool h[10][10], v[10][10];

int N;
int find(int sz) {
  int cnt = 0;
  for (int i = 0; i < N * N; i++) {
    int x = i / N;
    int y = i % N;
    if ((y + sz > N - 1) || (x + sz > N)) {
      continue;
    }
    bool found = true;
    for (int j = 0; j < sz; j++) {
      if (!h[x][y + j] || !h[x + sz][y + j] || !v[x + j][y] ||
          !v[x + j][y + sz]) {

        found = false;
        break;
      }
    }
    if (found) {
      cnt++;
    }
  }
  return cnt;
}

void printDot() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d ", h[i][j]);
    }
    printf("\n");
  }
  puts("");
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d ", v[i][j]);
    }
    printf("\n");
  }
}
int main() {
  int T;
  int T1 = 0;
  while (scanf("%d %d", &N, &T) == 2) {
    memset(h, 0, sizeof(h));
    memset(v, 0, sizeof(v));
    while (T--) {
      char t;
      int x, y;
      scanf(" %c %d %d", &t, &x, &y);
      x--;
      y--;
      if (t == 'H') {
        h[x][y] = true;
      }
      if (t == 'V') {
        v[y][x] = true;
      }
    }
    //printDot();
    if (T1) {
      puts("");
      puts("**********************************");
      puts("");
    }
    printf("Problem #%d\n\n", T1 + 1);
    bool found = false;
    for (int i = 1; i < N; i++) {
      int num = 0;
      if ((num = find(i))) {
        printf("%d square (s) of size %d\n", num, i);
        found = true;
      }
    }
    if (!found) {
      printf("No completed squares can be found.\n");
    }
    T1++;
    
  }
}
