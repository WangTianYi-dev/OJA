#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
const int maxn = 1000001;
const int INF = 2 << 20;
int n, temp[maxn];
struct Point {
    double x, y;
} S[maxn];

bool cmp(const Point& a, const Point& b)
{
    if (a.x == b.x)
        return a.y < b.y;
    else
        return a.x < b.x;
}

bool cmpy(const int& a, const int& b)
{
    return S[a].y < S[b].y;
}

double min(double a, double b)
{
    return a < b ? a : b;
}

double dist(int i, int j)
{
    double x = (S[i].x - S[j].x) * (S[i].x - S[j].x);
    double y = (S[i].y - S[j].y) * (S[i].y - S[j].y);
    return sqrt(x + y);
}

double merge(int left, int right)
{
    double d = INF;
    if (left == right) // if there is only one point, return infinity to avoid
        // influencing finding min distance
        return d;
    if (left + 1 == right) // if there are 2 points
        return dist(left, right);
    int mid = (left + right) >> 1;
    double d1 = merge(left, mid); // left part
    double d2 = merge(mid + 1, right); // right part
    // find min distance across parts
    d = min(d1, d2);
    int i, j, k = 0;
    // find all points in middle area (nearer than d to middle)
    // sto index in temp
    for (i = left; i <= right; i++)
        if (fabs(S[mid].x - S[i].x) <= d)
            temp[k++] = i;
    // sort index by y
    sort(temp, temp + k, cmpy);
    for (i = 0; i < k; i++)
        for (j = i + 1; j < k && S[temp[j]].y - S[temp[i]].y < d; j++) {
            double d3 = dist(temp[i], temp[j]);
            if (d > d3)
                d = d3;
        }
    // printf("[%d, %d]: %lf\n", left, right, d);
    return d;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%lf%lf", &S[i].x, &S[i].y);
    sort(S, S + n, cmp);
    return !printf("%.4lf\n", merge(0, n - 1));
}