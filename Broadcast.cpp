#include <iostream>
using namespace std;
const int maxn = 10010;
int n, m;
int queue[maxn], head, tail;
int cover;
// list node
struct lnode {
    int val;
    lnode* nxt;
    lnode()
    {
    }
    lnode(int v, lnode* n)
        : val(v)
        , nxt(n)
    {
    }
};

struct town {
    int state;
    lnode* nbr;
    town()
        : state(0)
        , nbr(nullptr)
    {
    }
    void insert(int num)
    {
        nbr = new lnode(num, nbr);
    }
} towns[maxn];

bool search(int i)
{
    queue[tail++] = i;
    towns[i].state = 1;
    cover++;
    while (head < tail) {
        town& cur = towns[queue[head]];
        lnode* tmp = cur.nbr;
        while (tmp != nullptr) {
            int j = tmp->val;
            if (!towns[j].state) {
                towns[j].state = -cur.state;
                cover++;
                queue[tail++] = j;
            } else if (towns[j].state == cur.state)
                return false;
            tmp = tmp->nxt;
        }
        head++;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int a, b;
    while (m--) {
        cin >> a >> b;
        towns[a].insert(b);
        towns[b].insert(a);
    }
    for (int i = 1; i <= n; i++) {
        if (!towns[i].state) {
            if (!search(i)) {
                printf("-1\n");
                return 0;
            }
            if (cover == n) {
                printf("1\n");
                return 0;
            }
        }
    }
    return 0;
}