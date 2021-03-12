#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

double dis(double x1, double y1, double x2, double y2)
{
    double dx = x1 - x2, dy = y1 - y2;
    return sqrt(dx * dx + dy * dy);
}

int main()
{
    double d[6];
    for (int i = 0; i < 6; i++) {
        cin >> d[i];
    }
    double a = 0.0;
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            a += dis(d[2*i], d[2*i+1], d[2*j], d[2*j+1]);
        }
    }
    printf("%.2lf\n", a);
    return 0;
}
