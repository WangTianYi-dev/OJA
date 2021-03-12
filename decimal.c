#include <stdio.h>
int main() {
  int a, b, c;
  while (scanf("%d %d %d", &a, &b, &c) && (a != 0 && b != 0 && c != 0)) {
    printf("%d", a / b);
    if (c > 0)
      printf(".");
    for (int i = 0; i < c - 1; i++) {
      printf("%d", a * 10 / b);
      a = a * 10 % b;
    }
    if (a > 5) {
      printf("%d\n", a * 10 / b + 1);
    } else {
      printf("%d\n", a * 10 / b);
    }
  }
}
