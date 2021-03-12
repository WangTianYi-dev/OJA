#include <bits/stdc++.h>
using namespace std;

const int maxt = 1010;

int main()
{
    int t, kase = 0;
    while (scanf("%d", &t) == 1 && t) {
        printf("Scenario #%d\n", ++kase);
        map<int, int> team;
        for (int i = 0; i < t; i++) {
            int n, x;
            scanf("%d", &n);
            while (n--) {
                scanf("%d", &x);
                // team[x]为代号x的队伍数
                team[x] = i;
            }
        }

        // q：队伍的队列。qsum：各个队伍的队列
        queue<int> q, qsum[maxt];
        for (;;) {
            int x;
            char cmd[10];
            scanf("%s", cmd);
            if (cmd[0] == 'S') {
                // stop
                break;
            } else if (cmd[0] == 'D') {
                // dequeue
                int t = q.front();
                printf("%d\n", qsum[t].front());
                qsum[t].pop();
                if (qsum[t].empty())
                    q.pop();
            } else if (cmd[0] == 'E') {
                // enqueue
                scanf("%d", &x);
                int t = team[x];
                if (qsum[t].empty()) {
                    q.push(t);
                }
                qsum[t].push(x);
            }
        }
        printf("\n");
    }
    return 0;
}
