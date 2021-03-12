#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
const int maxn = 1000001;
const double INF = 1 << 20;
int n;
struct Point {
    double x, y;
} S[maxn], T[maxn];

bool cmpx(const Point& a, const Point& b)
{
    return a.x < b.x;
}

bool cmpy(const Point& a, const Point& b)
{
    return a.y < b.y;
}

double dist(const Point& a, const Point& b)
{
    double dx = a.x - b.x, dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

double minD(int l, int h)
{
    if (l + 1 == h) {
        return INF;
    }
    if (l + 2 == h) {
        return dist(S[l], S[h - 1]);
    }
    int mid = (l + h) >> 1;
    double dL = minD(l, mid);
    double dR = minD(mid, h);
    double dMin = min(dL, dR);
    int s = 0;
    for (int i = l; i < h; i++) {
        if (abs(S[i].x - S[mid].x) < dMin) {
            T[s++] = S[i];
        }
    }
    sort(T, T + s, cmpy);
    for (int i = 0; i < s; i++) {
        for (int j = i + 1; j < s; j++) {
            if (T[j].y - T[i].y > dMin) {
                break;
            }
            dMin = min(dMin, dist(T[i], T[j]));
        }
    }
    return dMin;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf%lf", &S[i].x, &S[i].y);
    }
    sort(S, S + n, cmpx);
    printf("%.4lf\n", minD(0, n));
    return 0;

}
