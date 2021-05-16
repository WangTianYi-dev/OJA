#include <cctype>
#include <cstdio>
#include <queue>
using namespace std;

int n, a[100001], b[100001];
int main() {
    scanf("%d", &n);
    for (register int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (register int i = 1; i <= n; ++i)
        scanf("%d", &b[i]);
    priority_queue<int, vector<int>, greater<int>> q;
    for (register int i = 1; i <= n; ++i)
        for (register int j = 1; (i - 1) * (j - 1) <= n && j <= n; ++j)
            q.push(a[i] + b[j]);
    for (register int i = 0; i < n; ++i) {
        printf("%d ", q.top());
        q.pop();
    }
    return 0;
}