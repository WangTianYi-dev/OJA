#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
bool IsPrime(int n)
{
    if (n == 1) {
        return false;
    } else {
        int root = (int)sqrt(n);
        for (int i = 2; i <= root; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
}

bool prime[10000];
bool passed[10000];

int equal(int is[4])
{
    int c = 1000 * is[0] + 100 * is[1] + 10 * is[2] + is[3];
    return c;
}

struct node {
    int num;
    int len;
    node(int a, int b)
        : num(a)
        , len(b) {};
};

int Routine(int a, int b)
{
    memset(passed, false, sizeof(passed));
    int cur = a;
    passed[cur] = true;
    int nums[4];
    for (int i = 3; i >= 0; i--) {
        nums[i] = cur % 10;
        cur /= 10;
    }
    int curnum[4];
    memcpy(curnum, nums, sizeof(curnum));
    queue<node> q;
    q.push(node(a, 0));
    // printf("num:%d len:%d\n", q.front().num, q.front().len);
    while (!q.empty()) {
        node cur = q.front();
        if (cur.num == b) {
            // printf("ans: %d, len: %d\n", cur.num, cur.len);
            return cur.len;
        }
        q.pop();
        for (int i = 3; i >= 0; i--) {
            curnum[i] = cur.num % 10;
            cur.num /= 10;
        }
        memcpy(nums, curnum, sizeof(nums));
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 10; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                if (j != nums[i]) {
                    curnum[i] = j;
                }
                int cn = equal(curnum);
                if (!passed[cn] && IsPrime(cn)) {
                    q.push(node(cn, cur.len + 1));
                    // printf("num:%d len:%d\n", cn, cur.len + 1);
                    passed[cn] = true;
                }
            }
            memcpy(curnum, nums, sizeof(curnum));
        }
    }
    return -1;
}

int main()
{
    for (int i = 1000; i < 10000; i++) {
        if (IsPrime(i)) {
            prime[i] = true;
        }
    }
    int n;
    cin >> n;
    int a, b;
    while (n--) {
        cin >> a >> b;
        
        cout << Routine(a, b) << '\n';
    }
    return 0;
}
