#include <stdio.h>
#include <string.h>

#define maxd 1000
#define BIG 10000

int r, c, n, d[maxd][maxd], d2[maxd][maxd], ans[maxd][maxd], cols[maxd];

void copy(char type, int p, int q) {
  // if copy by row
  if (type == 'R') {
    for (int i = 1; i <= c; i++) {
      // the d's row p is replaced by d2's row q
      d[p][i] = d2[q][i];
    }
  } else {
    for (int i = 1; i <= r; i++) {
      // the d's col p is replaced by d2's col q
      d[i][p] = d2[i][q];
    }
  }
}

void del(char type) {
  memcpy(d2, d, sizeof(d));
  // cnt is the number of deleting
  int cnt = type == 'R' ? r : c, cnt2 = 0;
  for (int i = 1; i <= cnt; i++) {
    // col[i] is the flag shows if col/low i should be moded
    if (!cols[i]) {
      // if col[i] need to be deled
      // copy d2's row/cow i to d's row/col cnt2
      copy(type, ++cnt2, i);
    }
  }
  if (type == 'R') {
    r = cnt2;
  } else {
    c = cnt2;
  }
}

void ins(char type) {
  memcpy(d2, d, sizeof(d));
  int cnt = type == 'R' ? r : c, cnt2 = 0;
  for (int i = 1; i <= cnt; i++) {
    if (cols[i]) {
      copy(type, ++cnt2, 0);
    }
    copy(type, ++cnt2, i);
  }
  if (type == 'R') {
    r = cnt2;
  } else {
    c = cnt2;
  }
}

int main() {
  int r1, c1, r2, c2, q, kase = 0;
  char cmd[10];
  while (scanf(" %d %d %d", &r, &c, &n) == 3 && r) {
    // n:number of commands
    int r0 = r, c0 = c;
    // record position in this form:
    // d[i][j] = i*BIG + j
    for (int i = 1; i <= r; i++) {
      for (int j = 1; j <= c; j++) {
        d[i][j] = i * BIG + j;
      }
    }
    // execute commands
    while (n--) {
      scanf("%s", cmd);
      // if command is EX
      if (cmd[0] == 'E') {
        scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
        int t = d[r1][c1];
        d[r1][c1] = d[r2][c2];
        d[r2][c2] = t;
      } else {
        // delete or insert
        int a, x;
        scanf("%d", &a);
        memset(cols, 0, sizeof(cols));
        for (int i = 0; i < a; i++) {
          scanf("%d", &x);
          cols[x] = 1;
        }
        if (cmd[0] == 'D') {
          del(cmd[1]);
        } else {
          ins(cmd[1]);
        }
      }
    }
    memset(ans, 0, sizeof(ans));
    for (int i = 1; i <= r; i++) {
      for (int j = 1; j <= c; j++) {
        ans[d[i][j] / BIG][d[i][j] % BIG] = i * BIG + j;
      }
    }
    if (kase > 0) {
      printf("\n");
    }
    printf("Spreadsheet #%d\n", ++kase);
    scanf("%d", &q);
    while (q--) {
      scanf("%d%d", &r1, &c1);
      printf("Cell data in (%d,%d) ", r1, c1);
      if (ans[r1][c1] == 0) {
        printf("GONE\n");
      } else {
        printf("moved to (%d,%d)\n", ans[r1][c1] / BIG, ans[r1][c1] % BIG);
      }
    }
  }
  return 0;
}
