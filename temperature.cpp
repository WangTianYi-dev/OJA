// modified from csdn by DaerHoy

#include "temperature.h"
#include <cstdio>
#include <ctime>
#include <stdlib.h>
#define mod 1000000007
#define ll long long
using namespace std;

#define X 0
#define Y 1

int n, dim;
ll lastans;
bool randomOn = true;

struct P {
    int d[2], mx[2], mn[2], v, l, r;
    ll sum, cnt;

    int &operator[](int x) {
        return d[x];
    }

    friend bool operator==(P a, P b) {
        return a.d[0] == b.d[0] && a.d[1] == b.d[1];
    }

    friend bool operator<(P a, P b) {
        return a[dim] < b[dim];
    }
} p[200005];

int cmp(const void *aa, const void *bb) {
    return (*(P *)bb)[dim] - (*(P *)aa)[dim];
}

bool in(int x1, int y1, int x2, int y2, int X1, int Y1, int X2, int Y2) {
    return x1 <= X1 && X2 <= x2 && y1 <= Y1 && Y2 <= y2;
}

bool out(int x1, int y1, int x2, int y2, int X1, int Y1, int X2, int Y2) {
    return x1 > X2 || x2 < X1 || y1 > Y2 || y2 < Y1;
}

inline int Max(int a, int b) {
    return (a > b ? a : b);
}

inline int Min(int a, int b) {
    return (a < b ? a : b);
}

template <class T>
void Swap(T &a, T &b) {
    T c = a;
    a = b;
    b = c;
}

template <class T>
T quick_select(T *a, int lo, int tar, int hi) {
    int p = rand() % (hi - lo + 1) + lo;
    Swap(a[lo], a[p]);
    int i = hi, j = hi;
    while (lo < j) {
        if (a[lo] < a[j]) {
            Swap(a[i--], a[j]);
        }
        j--;
    }
    Swap(a[i], a[lo]);
    if (i == tar) {
        return a[i];
    } else if (i < tar) {
        return quick_select(a, i + 1, tar, hi);
    } else
        return quick_select(a, lo, tar, i - 1);
}

struct data {
    P t[200005], now;
    int rt, cnt;
    ll count, ans;

    void update(int k) {
        int l = t[k].l, r = t[k].r;
        for (int i = 0; i < 2; i++) {
            t[k].mn[i] = t[k].mx[i] = t[k][i];
            if (l)
                t[k].mn[i] = Min(t[k].mn[i], t[l].mn[i]);
            if (l)
                t[k].mx[i] = Max(t[k].mx[i], t[l].mx[i]);
            if (r)
                t[k].mn[i] = Min(t[k].mn[i], t[r].mn[i]);
            if (r)
                t[k].mx[i] = Max(t[k].mx[i], t[r].mx[i]);
        }
        t[k].sum = t[k].v + t[l].sum + t[r].sum;
        t[k].cnt = 1 + t[l].cnt + t[r].cnt;
    }

    void insert(int &k, bool dim) {
        if (!k) {
            k = ++cnt;
            t[k][0] = t[k].mn[0] = t[k].mx[0] = now[0];
            t[k][1] = t[k].mn[1] = t[k].mx[1] = now[1];
        }
        if (now == t[k]) {
            t[k].v += now.v, t[k].sum += now.v;
            return;
        }
        if (now[dim] < t[k][dim])
            insert(t[k].l, dim ^ 1);
        else
            insert(t[k].r, dim ^ 1);
        update(k);
    }

    void query(int k, int x1, int y1, int x2, int y2) {
        if (!k)
            return;
        ll tmp = 0;
        if (in(x1, y1, x2, y2, t[k].mn[0], t[k].mn[1], t[k].mx[0], t[k].mx[1])) {
            ans += t[k].sum;
            count += t[k].cnt;
            return;
        }
        if (out(x1, y1, x2, y2, t[k].mn[0], t[k].mn[1], t[k].mx[0], t[k].mx[1]))
            return;
        if (in(x1, y1, x2, y2, t[k][0], t[k][1], t[k][0], t[k][1])) {
            ans += t[k].v;
            count++;
        }
        query(t[k].l, x1, y1, x2, y2);
        query(t[k].r, x1, y1, x2, y2);
    }

    int rebuild(int l, int r, bool f) {
        if (l > r)
            return 0;
        int mid = (l + r) >> 1;
        dim = f;
        // qsort(p + l, r - l + 1, sizeof(p[0]), cmp);

        t[mid] = quick_select(p, l, mid, r);
        t[mid].l = rebuild(l, mid - 1, f ^ 1);
        t[mid].r = rebuild(mid + 1, r, f ^ 1);
        update(mid);
        return mid;
    }
} T;

int main() {
    // srand(time(NULL));
    n = GetNumOfStation();
    if (n == 0) {
        int x1, x2, y1, y2;
        while (GetQuery(&x1, &y1, &x2, &y2)) {
            Response(0);
            // printf("0\n");
        }
        return 0;
    }
    int opt, x, y, x2, y2, A, m = 10000;
    for (int i = 0; i < n; i++) {
        GetStationInfo(i, &p[i + 1][0], &p[i + 1][1], &p[i + 1].v);
        p[i + 1].sum = p[i + 1].v;
    }
    T.rt = T.rebuild(1, n, 0);
    while (GetQuery(&x, &y, &x2, &y2)) {
        T.count = 0;
        T.ans = 0;
        T.query(T.rt, x, y, x2, y2);

        if (T.count != 0) {
            Response(T.ans / T.count);
        } else {
            Response(0);
        }
    }
    return 0;
}
