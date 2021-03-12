#include <iostream>
using namespace std;

const int maxn = 4000010;
struct Node {
    int left, right;
} tree[maxn];
int findpre[maxn], pre[maxn], post[maxn], findpost[maxn];
int n;
int root;

int buildTree(int left, int right)
{
    if (left == right) {
        return left;
    }
    int v = left, nxtl = left + 1, nxtr = findpre[post[findpost[pre[v]] - 1]];
    tree[pre[v]].left = pre[buildTree(nxtl, nxtr - 1)];
    tree[pre[v]].right = pre[buildTree(nxtr, right)];
    return v;
}

void traverseIn(int root)
{
    if (tree[root].left != 0) {
        traverseIn(tree[root].left);
    }
    printf("%d ", root);
    if (tree[root].right != 0) {
        traverseIn(tree[root].right);
    }
}

void printTree()
{

    printf("root: %d\n", root);
    for (int i = 1; i <= n; i++) {
        printf("no: %d left: %d right: %d\n", i, tree[i].left, tree[i].right);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &pre[i]);
        findpre[pre[i]] = i;
    }
    root = pre[1];
    for (int i = 1; i <= n; i++) {
        scanf("%d", &post[i]);
        findpost[post[i]] = i;
    }
    buildTree(1, n);
#ifdef DEBUG
    printTree();
#endif
    traverseIn(root);
    cout << endl;
    return 0;
}
