#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

long long n;
const int SZ = 1 << 20; //快速io
struct fastio {
    char inbuf[SZ];
    char outbuf[SZ];
    fastio()
    {
        setvbuf(stdin, inbuf, _IOFBF, SZ);
        setvbuf(stdout, outbuf, _IOFBF, SZ);
    }
} io;

const int maxn = 4e6 + 100;
typedef long long ll;
struct node {
    int x, y;
    // node()
    // {
    //     x = 0;
    //     y = 0;
    // }
    // node(int a, int b)
    //     : x(a)
    //     , y(b)
    // {
    // }
    // node& operator=(const node& n)
    // {
    //     x = n.x;
    //     y = n.y;
    //     return *this;
    // }
} dat[maxn], tmp[maxn];

bool operator<(node& x, node& y)
{
    if (x.x == y.x) {
        return x.y < y.y;
    } else {
        return x.x < y.x;
    }
}

void merge(int lo, int hi)
{
    if (hi - lo < 2)
        return;
    int mi = (lo + hi) >> 1;
    merge(lo, mi);
    merge(mi, hi);
    int plo = lo, phi = mi, i = lo;
    while (plo < mi && phi < hi) {
        dat[plo] < dat[phi] ? tmp[i++] = dat[plo++] : tmp[i++] = dat[phi++];
    }
    while (plo < mi) {
        tmp[i++] = dat[plo++];
    }
    while (phi < hi) {
        tmp[i++] = dat[phi++];
    }
    memcpy(dat + lo, tmp + lo, sizeof(node) * (hi - lo));
    // for (int i = 0; i < n; i++) {
    //     cout << "p0 " << dat[i].x << ' ' << dat[i].y << endl;
    // }
}

ll ans = 0;

ll cntRev(int lo, int hi)
{
    if (hi - lo < 2) {
        return 0;
    }
    int mi = (lo + hi) >> 1;
    ll rev = cntRev(lo, mi) + cntRev(mi, hi);
    int plo = lo, phi = mi, i = lo;
    while (plo < mi && phi < hi) {
        if (dat[plo].y < dat[phi].y) {
            tmp[i++].y = dat[plo++].y;
        } else {
            rev += plo - lo;
            tmp[i++].y = dat[phi++].y;
        }
    }
    while (plo < mi) {
        tmp[i++].y = dat[plo++].y;
    }
    while (phi < hi) {
        rev += plo - lo;
        tmp[i++].y = dat[phi++].y;
    }
    memcpy(dat + lo, tmp + lo, sizeof(node) * (hi - lo));
    // for (int i = 0; i < n; i++) {
    //     cout << "p1 " << dat[i].x << ' ' << dat[i].y << endl;
    // }
    return rev;
}

int main()
{
    scanf("%lld", &n);
    int x, y;
    for (long long i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        dat[i] = { x, y };
    }
    // for (int i = 0; i < n; i++) {
    //     printf("i:%d x: %d y: %d\n", i, dat[i].x, dat[i].y);
    // }
    merge(0, n);
    // for (int i = 0; i < n; i++) {
    //     printf("i:%d x: %d y: %d\n", i, dat[i].x, dat[i].y);
    // }

    long long k = cntRev(0, n);

    // for (int i = 0; i < n; i++) {
    //     printf("i:%d x: %d y: %d\n", i, dat[i].x, dat[i].y);
    // }

    printf("%lld\n", k);
    return 0;
}