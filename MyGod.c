#include <stdio.h>
float gailv(int a);
int main() {
  int b, e, c[20], j;
  float i, a; //承接子函数的值
  scanf("%d", &b);
  for (j = 0; j < b; j++) //输入每次试验的人数
  {
    scanf("%d", &c[j]);
  }
  for (j = 0; j < b; j++) //对每次试验进行判断
  {
    e = c[j];
    i = gailv(e);
    a = i * 100;
    printf("%.2f%%%\t", a);
  }
  return 0;
}
float gailv(int a) //判断试验发生的几率
{
  int r;
  float m = 1;
  if (a == 1)
    m = 0;
  else {
    for (int i = 1, j = 0; i < a; i++, j++)
      m = m * (a - j - 1) / (a - j);
  }
  m = m * 10000;
  r = (int)m;
  if ((r % 10) >= 5) {
    m = (float)r;
    m = m + 1;
  }
  m = m / 10000;
  m = (float)m;
  return m;
}