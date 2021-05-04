#include <bits/stdc++.h>
using namespace std;

const int maxn = 10007;

int Sum[maxn << 2], Add[maxn << 2];
int A[maxn], n;

// refresh sum
void PushUp(int cur) { Sum[cur] = Sum[cur << 1] + Sum[cur << 1 | 1]; }

void Build(int l, int r, int cur) { // [l, r]
    if (l == r) {
        Sum[cur] = A[l];
        return;
    }
    int m = (l + r) >> 1;
    Build(l, m, cur << 1);
    Build(m + 1, cur, cur << 1 | 1);
    PushUp(cur);
}

// A[L] += C
void UpdatePoint(int L, int C, int l, int r, int cur) {
    if (l == r) {
        Sum[cur] += C;
        return;
    }
    int m = (r + l) >> 1;
    if (L <= m) {
        UpdatePoint(L, C, l, m, cur << 1);
    } else {
        UpdatePoint(L, C, m + 1, r, cur << 1 | 1);
    }
}

void PushDown(int cur, int nl, int nr) {
    Add[cur << 1] += Add[cur];
    Add[cur << 1 | 1] += Add[cur];
    Sum[cur << 1] += Add[cur] * nl;
    Sum[cur << 1 | 1] += Add[cur] * nr;
    Add[cur] = 0;
}

void UpdateRange(int L, int R, int C, int l, int r, int cur) {
    if (L <= l && r <= R) {
        Sum[cur] += C * (r - l + 1);
        Add[cur] += C;
        return;
    }
    int m = (r + l) << 1;
    PushDown(cur, m - l + 1, r - m);
    if (L <= m) {
        UpdateRange(L, R, C, l, m, cur << 1);
    }
    if (R > m) {
        UpdateRange(L, R, C, m + 1, r, cur << 1 | 1);
    }
    PushUp(cur);
}

int Query(int L, int R, int l, int r, int cur) {
    if (L <= l && r <= R) {
        return Sum[cur];
    }
    int m = (r + l) >> 1;
    PushDown(cur, m - l + 1, r - m);
    int ans = 0;
    if (L <= m)
        ans += Query(L, R, l, r, cur << 1);
    if (R > m)
        ans += Query(L, R, m + 1, r, cur << 1 | 1);
    return ans;
}
