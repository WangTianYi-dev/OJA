#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-6;
int main() {
  char line[256];
  double lg2 = log10(2), A, lgv;
  int B;
  while (scanf("%s", line) == 1 && strcmp(line, "0e0") != 0) {
    *strchr(line, 'e') = ' ';
    sscanf(line, "%lf%d", &A, &B);
    lgv = log10(A) + B;
    for (int M = 1; M <= 10; ++M) {
      int E =
          round(log10((lgv + M * lg2 - log10(pow(2, M) - 1)) / lg2 + 1) / lg2);
      if (fabs(((1 << E) - 1) * lg2 + log10(pow(2, M) - 1) - M * lg2 - lgv) <=
          EPS) {
        printf("%d %d\n", M - 1, E);
        break;
      }
    }
  }
}