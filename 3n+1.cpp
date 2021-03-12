#include <algorithm>
#include <iostream>
using namespace std;

long long len(long long t) {
  long long l = 0;
  while (t != 1) {
    /* code */
    if (t % 2 == 1) {
      t = 3 * t + 1;
    } else {
      t = t / 2;
    }
    l++;
  }
  return l + 1;
}

int main() {
  long long a, b;
  while (scanf("%lld %lld", &a, &b) == 2) {
    long long MAX = 0;
    bool rev = false;
    if (a > b) {
      swap(a, b);
      rev = true;
    }
    for (long long i = a; i <= b; i++) {
      MAX = max(MAX, len(i));
    }
    if (!rev) {
      printf("%lld %lld %lld\n", a, b, MAX);
    } else {
      printf("%lld %lld %lld\n", b, a, MAX);
    }
  }
  return 0;
}

