#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long BIT64;
constexpr int W = 8, IPW = 4 * W;

inline bool inRange(int x, int left, int right)
{
    if (left > right)
        return inRange(x, right, left);
    return left <= x && x <= right;
}

void printIp(const int* v)
{
    bool first = true;
    for (int i = 0; i < 4; i++) {
        int x = 0;
        for (int j = i * W; j < (i + 1) * W; j++) {
            x = (x << 1) | v[j];
        }
        if (first) {
            first = false;
        } else {
            printf(".");
        }
        printf("%d", x);
    }
    puts("");
}

void toBinary(int x, int* v, int pos)
{
    assert(inRange(x, 0, 255));
    for (int i = 0; i < W; i++) {
        v[pos + W - i - 1] = x % 2;
        x /= 2;
    }
}

constexpr int MAXM = 1024;
int ips[MAXM][IPW + 4];

int main()
{
    int m, ip[4], subNet[IPW];
    while (scanf("%d", &m) == 1) {
        memset(subNet, 0, sizeof(subNet));
        for (int i = 0; i < m; i++) {
            scanf("%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);
            for (int j = 0; j < 4; j++) {
                toBinary(ip[j], ips[i], j * W);
            }
        }

        int n;
        for (n = 0; n < IPW; n++) {
            bool same = true;
            for (int j = 1; j < m; j++) {
                if (ips[j][n] != ips[j - 1][n]) {
                    same = false;
                    break;
                }
            }
            if (!same)
                break;
        }
        // the first n bit of network mask
        fill_n(subNet, n, 1);
        fill_n(ips[0] + n, IPW - n, 0);
        printIp(ips[0]);
        printIp(subNet);
        for (int i = 0; i < n; i++) {
            putchar(subNet[n] + '0');
        }
    }
    return 0;
}