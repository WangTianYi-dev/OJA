#include <stdio.h>
#include <string.h>
#define maxd 10000

struct Command {
  char c[5];
  int r1, r2, c1, c2;
  int a, x[100];
} cmd[maxd];

int r, c, n;

int simulate(int *r0, int *c0) {
  for (int i = 0; i < n; i++) {
    if (cmd[i].c[0] == 'E') {
      // simulate the exchange
      // by change r0 and c0
      if (cmd[i].r1 == *r0 && cmd[i].c1 == *c0) {
        *r0 = cmd[i].r2;
        *c0 = cmd[i].c2;
      } else if (cmd[i].r2 == *r0 && cmd[i].c2 == *c0) {
        *r0 = cmd[i].r1;
        *c0 = cmd[i].c1;
      }
    } else {
      // else is insert or delete
      int dr = 0, dc = 0;
      for (int j = 0; j < cmd[i].a; j++) {
        int x = cmd[i].x[j];
        if (cmd[i].c[0] == 'I') {
          // Insert
          if (cmd[i].c[1] == 'R' && x <= *r0) dr++;
          if (cmd[i].c[1] == 'C' && x <= *c0) dc++;
        } else {
          // delete
          if (cmd[i].c[1] == 'R' && x == *r0) return 0;
          if (cmd[i].c[1] == 'C' && x == *c0) return 0;
          if (cmd[i].c[1] == 'R' && x < *r0) dr--;
          if (cmd[i].c[1] == 'C' && x < *c0) dc--;
        }
      }
      *r0 += dr; *c0  += dc;
    }
  }
  return 1;
}

int main() {
  int r0, c0, q, kase = 0;
  while (scanf("%d %d %d", &r, &c, &n) == 3 && r) {
    for (int i = 0; i < n; i++) {
      scanf("%s", cmd[i].c);
      // if command is EX then record the position
      if (cmd[i].c[0] == 'E') {
        scanf("%d %d %d %d", &cmd[i].r1, &cmd[i].c1, &cmd[i].r2, &cmd[i].c2);
      } else {
        // a records the number of actions
        scanf("%d", &cmd[i].a);
        // x records the positions of actions
        for (int j = 0; j < cmd[i].a; j++) {
          scanf("%d", &cmd[i].x[j]);
        }
      }
    }
    if (kase > 0) {
      printf("\n");
    }
    printf("Spreadsheet #%d\n", ++kase);

    scanf("%d", &q);
    while (q--) {
      scanf("%d %d", &r0, &c0);
      printf("Cell data in (%d,%d) ", r0, c0);
      // simulate change the value in r0 and c0
      if (!simulate(&r0, &c0))
        printf("GONE\n");
      else
        printf("moved to (%d,%d)\n", r0, c0);
    }
  }
  return 0;
}
