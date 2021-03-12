#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int marbles[10086];

int main()
{
    int n, m;
    int count = 1;
    while (scanf("%d %d", &n, &m) == 2 && n != 0) {
        memset(marbles, 0, sizeof(marbles));
        for (int i = 0; i < n; i++) {
            scanf("%d", &marbles[i]);
        }
        sort(marbles, marbles + n);
        printf("CASE# %d:\n", count);
        int quary;
        while (m--) {
            scanf("%d", &quary);
            for (int i = 0; i < n; i++) {
                if (marbles[i] == quary) {
                    printf("%d found at %d\n", quary, i + 1);
                    break;
                } else if (marbles[i] > quary || i == (n - 1)) {
                    printf("%d not found\n", quary);
                    break;
                }
            }
        }
        count++;
    }
    return 0;
}