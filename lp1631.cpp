#include <cstdio>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
int a[100005] = {}, b[100005] = {}, to[100005] = {}, i, n;
priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int> > > q;
int main() {
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    for (i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
        to[i] = 1;
        q.push(pair<int, int>(a[1] + b[i], i));
    }

    while (n--) {
        printf("%d ", q.top().first);
        i = q.top().second;
        q.pop();
        q.push(pair<int, int>(a[++to[i]] + b[i], i));
    }
    return 0;
}