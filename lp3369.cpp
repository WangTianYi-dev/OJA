// main program for luogu p3369

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>
using namespace std;

#define LEFT 0
#define RIGHT 1
#define OTHER_SIDE(x) (x ^ 1)

void printtree();
const int maxn = 1000010;
struct node {
    int val;
    int node;
    int father;
    int son[2];
    int count;
    int subsize;
} tree[maxn];
// sum is the total number of nodes;
int root, sum;

// return which (left or right) son i is;
int WhichSon(int i)
{
    return tree[tree[i].father].son[RIGHT] == i;
}

void ClearNode(int i)
{
    tree[i].son[LEFT] = tree[i].son[RIGHT] = 0;
}

// update subsize of i;
void Update(int i)
{
    int size = tree[i].count;
    int t;
    if ((t = tree[i].son[0])) {
        size += tree[t].subsize;
    }
    if ((t = tree[i].son[1])) {
        size += tree[t].subsize;
    }
    tree[i].subsize = size;
}

// rotate right
int zig(int i)
{
    int f = tree[i].father, ls = tree[i].son[LEFT];
    int rgs;
    if ((rgs = tree[ls].son[RIGHT])) {
        tree[rgs].father = i;
    }
    if (f) {
        if (tree[f].son[LEFT] == i) {
            tree[f].son[LEFT] = ls;
        } else {
            tree[f].son[RIGHT] = ls;
        }
        tree[ls].father = f;
        tree[i].father = ls;
        tree[i].son[LEFT] = tree[ls].son[RIGHT];
        tree[ls].son[RIGHT] = i;
    } else {
        // i is root
        root = ls;
        tree[i].father = ls;
        tree[i].son[LEFT] = tree[ls].son[RIGHT];
        tree[ls].son[RIGHT] = i;
        tree[ls].father = 0;
    }

    // puts("zig:");
    // printtree();
    return ls;
}

// rotate left
int zag(int i)
{
    int f = tree[i].father, rs = tree[i].son[RIGHT];
    int lgs;
    if ((lgs = tree[rs].son[LEFT])) {
        tree[lgs].father = i;
    }
    if (f) {
        if (tree[f].son[LEFT] == i) {
            tree[f].son[LEFT] = rs;
        } else {
            tree[f].son[RIGHT] = rs;
        }
        tree[i].father = rs;
        tree[i].son[RIGHT] = tree[rs].son[LEFT];
        tree[rs].son[LEFT] = i;
        tree[rs].father = f;
    } else {
        root = rs;
        tree[i].father = rs;
        tree[i].son[RIGHT] = tree[rs].son[LEFT];
        tree[rs].son[LEFT] = i;
        tree[rs].father = 0;
    }

    // puts("zag:");
    // printtree();
    return rs;
}

// rotate up i a level;
void Rotate(int i)
{
    int f = tree[i].father;
    int gf = tree[f].father;
    if (gf) {
        int dirF = WhichSon(i), dirGF = WhichSon(f);
        if (dirF == dirGF) {
            if (dirF == LEFT) {
                zig(gf);
                zig(f);
            } else {
                zag(gf);
                zag(f);
            }
        } else {
            if (dirF == LEFT) {
                zig(f);
                zag(gf);
            } else {
                zag(f);
                zig(gf);
            }
        }
        Update(gf);
        Update(f);
        Update(i);
    } else {
        int dirF = WhichSon(i);
        if (dirF == LEFT) {
            zig(f);
        } else {
            zag(f);
        }
        Update(f);
        Update(i);
    }
}

// splay in splay tree
void printtree();
void Splay(int i)
{
    /*
    essence of splay
    if i and its father are son of same side then rotate its father before than 
    rotate i, to make the tree balanced.
    */
    int f = tree[i].father;
    while (f) {
        Rotate(i);
        f = tree[i].father;
        // printtree();
    }
    root = i;
}

void Insert(int x)
{
    // new a root node
    if (!root) {
        sum++;
        root = sum;
        tree[sum].father = 0;
        tree[sum].son[LEFT] = tree[sum].son[RIGHT] = tree[sum].father = 0;
        tree[sum].subsize = ++tree[sum].count;
        tree[sum].val = x;
        return;
    }
    int cur = root, f = 0;
    for (;;) {
        // hit
        int curval = tree[cur].val;
        if (x == curval) {
            tree[cur].count++;
            Update(cur);
            Update(f);
            Splay(cur);
            break;
        }
        f = cur;
        cur = tree[cur].son[curval < x];
        // if not found, new a node
        if (!cur) {
            sum++;
            tree[sum].son[LEFT] = tree[sum].son[RIGHT] = 0;
            tree[sum].father = f;
            tree[sum].subsize = tree[sum].count = 1;
            tree[sum].val = x;
            tree[f].son[curval < x] = sum;
            // different from AVL, there is no need to update predecessors
            // because tree[sum] will be the new root;
            Update(f);
            // printf("JUST INSERTED:\n");
            // printtree();
            Splay(sum);
            break;
        }
    }
}

int FindNumByRank(int r)
{
    int cur = root;
    while (cur) {
        // using ref just to simplify code
        node& cn = tree[cur];
        // if current node's leftson exists and rank < current node's subsize
        // it means that target is in left subtree
        int beforeRank = (cn.son[LEFT] ? tree[cn.son[LEFT]].subsize : 0);
        int nextRank = beforeRank + cn.count;
        if (r <= beforeRank) {
            cur = cn.son[LEFT];
        } else if (r <= nextRank) {
            return cn.val;
        } else {
            cur = cn.son[RIGHT];
            r -= nextRank;
        }
    }
    return 0;
}

int FindRankByVal(int n)
{
    int cur = root, ans = 0;
    while (cur) {
        node& cn = tree[cur];
        if (n < cn.val) {
            cur = cn.son[LEFT];
        } else {
            // when not go left, add the size of leftsubtree to rank
            ans += (cn.son[LEFT] ? tree[cn.son[LEFT]].subsize : 0);
            if (n == cn.val) {
                Splay(cur);
                // the lowest rank of this value
                return ans + 1;
            }
            ans += cn.count;
            cur = cn.son[RIGHT];
        }
    }
    return 0;
}

// find prefix or sufix of root
// not splayed
int FindPredessor()
{
    int cur = tree[root].son[LEFT];
    while (tree[cur].son[RIGHT]) {
        cur = tree[cur].son[RIGHT];
    }
    return cur;
}

int FindSuccessor()
{
    int cur = tree[root].son[RIGHT];
    while (tree[cur].son[LEFT]) {
        cur = tree[cur].son[LEFT];
    }
    return cur;
}

void DeleteVal(int x)
{
    int rk = FindRankByVal(x);
    // node of x has been splayed to root

    // rn means root node
    node& rn = tree[root];
    if (rn.count > 1) {
        rn.count--;
        Update(root);
        return;
    } else if (!rn.son[LEFT] && !rn.son[RIGHT]) {
        ClearNode(root);
        root = 0;
        return;
    }
    // rn.count == 1 and rn only have right son
    else if (!rn.son[LEFT]) {
        int oldRoot = root;
        root = rn.son[RIGHT];
        tree[root].father = 0;
        ClearNode(oldRoot);
        return;
    } else if (!rn.son[RIGHT]) {
        int oldRoot = root;
        root = rn.son[LEFT];
        tree[root].father = 0;
        ClearNode(oldRoot);
        return;
    } else {
        int leftMax = FindPredessor(), oldRoot = root;
        // root = leftMax;
        Splay(leftMax);
        // it is granteed that tree[oldRoot] only has right son
        tree[root].son[RIGHT] = tree[oldRoot].son[RIGHT];
        tree[tree[oldRoot].son[RIGHT]].father = root;
        ClearNode(oldRoot);
        Update(root);
    }
}

char info[1000];
char* getinfo(int i)
{
    node& n = tree[i];
    sprintf(info, "value: %d, left: %d, right: %d, father: %d, count:"
                  "%d, subsize: %d",
        n.val, tree[n.son[LEFT]].val, tree[n.son[RIGHT]].val, tree[n.father].val, n.count,
        n.subsize);
    return info;
}

void printtree()
{
    printf("root: ");

    int cur = root;
    queue<int> q;
    q.push(cur);
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        printf("%s\n", getinfo(t));
        if (tree[t].son[LEFT]) {
            q.push(tree[t].son[LEFT]);
        }
        if (tree[t].son[RIGHT]) {
            q.push(tree[t].son[RIGHT]);
        }
    }
}

int main()
{
    int m, num, be_dealt;
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> num >> be_dealt;
        switch (num) {
        case 1:
            Insert(be_dealt);
            break;
        case 2:
            DeleteVal(be_dealt);
            break;
        case 3:
            printf("%d\n", FindRankByVal(be_dealt));
            break;
        case 4:
            printf("%d\n", FindNumByRank(be_dealt));
            break;
        case 5:
            Insert(be_dealt);
            printf("%d\n", tree[FindPredessor()].val);
            DeleteVal(be_dealt);
            break;
        case 6:
            Insert(be_dealt);
            // printtree();
            printf("%d\n", tree[FindSuccessor()].val);
            DeleteVal(be_dealt);
            break;
        }
        // #ifdef DEBUG
        // puts("DONE:");
        // printtree();
        // #endif
    }
    return 0;
}
