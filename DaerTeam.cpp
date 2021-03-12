#include <cstdio>
#include <map>
#include <queue>
using namespace std;

constexpr int maxt = 1010;
int main()
{
    int t, kase = 0;
    while (scanf("%d", &t) == 1 && t != 0) {
        printf("Scenario #%d\n", ++kase);
        map<int, int> teamof;
        for (int i = 1; i <= t; i++) {
            int n, member;
            scanf("%d", &n);
            while (n--) {
                scanf("%d", &member);
                teamof[member] = i;
                // printf("%d:%d\n", member, teamof[member]);
            }
        }

        char msg[10] {};
        int member;
        queue<int> teamqs[maxt], sumq;
        while (msg[0] != 'S') {
            scanf("%s", msg);
            switch (msg[0]) {
            case 'E': {
                scanf("%d", &member);
                int team = teamof[member];
                if (teamqs[team].empty()) {
                    sumq.push(team);
                }
                teamqs[team].push(member);
            } break;
            case 'D': {
                int team = sumq.front();
                member = teamqs[team].front();
                printf("%d\n", member);
                teamqs[team].pop();
                if (teamqs[team].empty()) {
                    sumq.pop();
                }
            } break;
            }
        }
        puts("");
    }
    return 0;
}
