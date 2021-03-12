#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
const double EPS = 1e-5;
double a, b;

// double F(double x) //这里的f函数是自己根据题目推导出来的，主要还是x有关y的函数
// {
//     double y = b * sqrt(1.0 - (x * x) / (a * a));
//     return y;
// }
double F(double x)
{
    return sqrt(pow(b, 2) - pow(x, 2) * pow(b, 2) / pow(a, 2));
}

double simpson(double (*F)(double), double a, double b)
{
    double m = (a + b) / 2.0;
    return (F(a) + F(b) + 4.0 * F(m)) * (b - a) / 6.0;
}

double ars(double (*F)(double), double a, double b, double eps)
{
    double m = (a + b) / 2.0;
    double mid = simpson(F, a, b), l = simpson(F, a, m), r = simpson(F, m, b);
    if (fabs(l + r - mid) <= 15 * eps)
        return l + r + (l + r - mid) / 15.0;
    return ars(F, a, m, eps / 2.0) + ars(F, m, b, eps / 2.0);
}

// double ars(double a, double b, double eps) //这里就是递归求辛普森最重要的一段函数了，
// {
//     double c = (a + b) / 2.0;
//     double mid = simpson(F, a, b), l = simpson(F, a, c), r = simpson(F, c, b);
//     if (fabs(l + r - mid) <= 15 * eps)
//         return l + r + (l + r - mid) / 15.0;
//     return ars(a, c, eps / 2.0) + ars(c, b, eps / 2.0);
// }

int main()
{
    int N;
    cin >> N;
    while (N--) {
        double l, r;
        cin >> a >> b >> l >> r;
        printf("%.3lf\n", 2.0 * ars(F, l, r, EPS));
    }
    return 0;
}