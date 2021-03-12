#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
struct Radar {
    double start, end;
    bool friend operator<(Radar a, Radar b)
    {
        return a.start < b.start;
    }
} radar[1005];

int main()
{
    int n, d, x, y, m, num, flag;
    double l, r;
    m = 1;
    while (scanf("%d%d", &n, &d)) {
        if (!n && !d)
            break;
        flag = true;
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &x, &y);
            if (y > d)
                flag = false;
            radar[i].start = x - sqrt(d * d - y * y);
            radar[i].end = x + sqrt(d * d - y * y);
        }
        if (!flag) {
            printf("Case %d: -1\n", m++);
            continue;
        }
        sort(radar, radar + n);
        num = 1, l = radar[0].start, r = radar[0].end; //切记l和r是double类型!!!!!
        for (int i = 1; i < n; i++) {
            if (radar[i].start >= l && radar[i].end <= r) { //对应情况1
                l = radar[i].start;
                r = radar[i].end;
            } else if (radar[i].start <= r && radar[i].end >= r) //对应情况2
                l = radar[i].start;
            else if (radar[i].start > r) { //对应情况3
                l = radar[i].start;
                r = radar[i].end;
                num++;
            }
        }
        printf("Case %d: %d\n", m++, num);
    }
    return 0;
}
