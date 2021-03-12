#include <cstdio>
#include <iostream>
using namespace std;
int n;

struct Team {
    int id, power;
} a[1 << 8], tree[1 << 10];

const Team& maxt(const Team& t1, const Team& t2)
{
    return (t1.power > t2.power) ? t1 : t2;
}

const Team& mint(const Team& t1, const Team& t2) {
    return (t1.power > t2.power) ? t2 : t1;
}

Team buildTree(int i, int l, int h)
{
    if (l == h) {
        return a[l];
    }
    int lchild = 2 * i, rchild = 2 * i + 1;
    tree[lchild] = buildTree(lchild, l, (l + h) >> 1);
    tree[rchild] = buildTree(rchild, ((l + h) >> 1) + 1, h);
    return maxt(tree[lchild], tree[rchild]);
}

void printTree() {
    int cnt = 1;
    for (int i = 1; i <= 1 << n; i++) {
        printf(" {%d, %d}", tree[i].id, tree[i].power);
        if (i == cnt) {
            cout << endl;
            cnt = cnt * 2 + 1;
        }
    }
}


int main()
{
    scanf(" %d", &n);
    for (int i = 1; i <= 1 << n; i++) {
        scanf(" %d", &a[i].power);
        a[i].id = i;
    }
    buildTree(1, 1, 1<<n);
    #ifdef DEBUG
    printTree();
    #endif
    printf("%d\n", mint(tree[2], tree[3]).id);
    return 0;
}
