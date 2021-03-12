#include <math.h>
#include <stdio.h>
#include <stdlib.h>
const int N = 105;
int main() {
  int i = 1;
  int b, n, m;
  while (scanf("%d %d %d", &b, &n, &m)) {
    int k = (70 * b + 21 * n + 15 * m) % 105;
    if (k > 10 || k < 100) {
      printf("Case %d: No answer\n", i);
    } else {
      printf("Case %d: %d\n", i, k);
    }
    i++;
  }
  return 0;
}