#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <utility>
template <class T, class B> using pair = std::pair<T, B>;
enum color {
    RED,
    BLACK,
};

template <class A> struct node {
    node *left = nullptr, *right = nullptr;
    node *parent = nullptr;
    A data;
    color clr = RED;
    node(node *pr, A e) {
        parent = pr;
        data = e;
    }

    node *succ();
};

template <typename T> node<T> *node<T>::succ() { //定位节点v的直接后继
    node<T> *s = this;                           //记录后继的临时变量
    if (right) { //若有右孩子，则直接后继必在右子树中，具体地就是
        s = right; //右子树中
        while (s->left)
            s = s->left; //最靠左（最小）的节点
    } else { //否则，直接后继应是“将当前节点包含于其左子树中的最低祖先”，具体地就是
        while (s->parent->right == s)
            s = s->parent; //逆向地沿右向分支，不断朝左上方移动
        s = s->parent; //最后再朝右上方移动一步，即抵达直接后继（如果存在）
    }
    return s;
}

template <class T> static node<T> *removeAt(node<T> *&x, node<T> *&hot) {
    node<T> *w = x;          //实际被摘除的节点，初值同x
    node<T> *succ = nullptr; //实际被删除节点的接替者
    if (!x->left)            //若*x的左子树为空，则可
        succ = x = x->right; //直接将*x替换为其右子树
    else if (!x->right)      //若右子树为空，则可
        succ = x = x->left;  //对称地处理——注意：此时succ != NULL
    else { //若左右子树均存在，则选择x的直接后继作为实际被摘除节点，为此需要
        w = w->succ(); //（在右子树中）找到*x的直接后继*w
        std::swap(x->data, w->data); //交换*x和*w的数据元素
        node<T> *u = w->parent;
        ((u == x) ? u->right : u->left) = succ = w->right; //隔离节点*w
    }
    hot = w->parent; //记录实际被删除节点的父亲
    if (succ)
        succ->parent = hot; //并将被删除节点的接替者与hot相联
    delete w;
    return succ; //释放被摘除节点，返回接替者
}

template <class A> struct RBTree {
    using node = node<A>;
    node *root = nullptr, *hot = nullptr;

    node *search(A e) {
        node *cur = root;
        while (cur) {
            hot = cur;
            if (e == cur->data.first) {
                return cur;
            } else if (e < cur->data.first) {
                cur = cur->left;
            } else if (e > cur->data.first) {
                cur = cur->right;
            }
        }
        return nullptr;
    }

    node *connect34(node *a, node *b, node *c, node *T0, node *T1, node *T2,
                    node *T3) {
        a->left = T0;
        if (T0)
            T0->parent = a;
        a->right = T1;
        if (T1)
            T1->parent = a;
        c->left = T2;
        if (T2)
            T2->parent = c;
        c->right = T3;
        if (T3)
            T3->parent = c;
        b->left = a;
        a->parent = b;
        b->right = c;
        c->parent = b;
        return b; //该子树新的根节点
    }

    enum Side { RIGHT, LEFT, ROOT };

    Side WhichChild(node *n) {
        if (root == n)
            return ROOT;
        node *p = n->parent;
        if (p->left == n)
            return LEFT;
        else
            return RIGHT;
    }

    node *uncle(node *x) {
        node *p = x->parent;
        Side s = WhichChild(x);
        if (s == LEFT) {
            return p->right;
        } else {
            return p->left;
        }
    }

    template <typename T> node *rotateAt(node *v) { // v为非空孙辈节点
        node *p = v->parent;
        node *g = p->parent; //视v、p和g相对位置分四种情况
        Side sp = WhichChild(p), sv = WhichChild(v);
        if (sp == LEFT)                     /* zig */
            if (sv == LEFT) { /* zig-zig */ //*DSA*/printf("\tzIg-zIg: ");
                p->parent = g->parent;      //向上联接
                return connect34(v, p, g, v->lc, v->rc, p->rc, g->rc);
            } else { /* zig-zag */     //*DSA*/printf("\tzIg-zAg: ");
                v->parent = g->parent; //向上联接
                return connect34(p, v, g, p->lc, v->lc, v->rc, g->rc);
            }
        else                                 /* zag */
            if (sv == RIGHT) { /* zag-zag */ //*DSA*/printf("\tzAg-zAg: ");
            p->parent = g->parent;           //向上联接
            return connect34(g, p, v, g->lc, p->lc, v->lc, v->rc);
        } else { /* zag-zig */     //*DSA*/printf("\tzAg-zIg: ");
            v->parent = g->parent; //向上联接
            return connect34(g, v, p, g->lc, v->lc, v->rc, p->rc);
        }
    }

    void solveDoubleRed(node *x) {
        if (x == root) {
            root->clr = BLACK;
            return;
        }
        node *p = x->parent;
        if (p->clr == BLACK)
            return;
        node *g = p->parent;
        node *u = uncle(x);
        if (u->clr == BLACK) {
            if (WhichChild(x) == WhichChild(p)) {
                p->clr = BLACK;
            } else {
                x->clr = BLACK;
            }
            g->clr = RED;
            node *gg = g->parent;
            node *r = rotateAt(x);
            r->parent = gg;
            if (gg == nullptr) {
                root = r;
            } else if (gg->left == g) {
                gg->left = r;
            } else {
                gg->right = r;
            }
        } else {
            p->clr = BLACK;
            u->clr = BLACK;
            if (root != g) {
                g->clr = RED;
            }
            solveDoubleRed(g);
        }
    }

    node *insert(A e) {
        node *x = search(e);
        if (x)
            return nullptr;
        x = new node(hot, e);
        solveDoubleRed(x);
        return x ? x : hot->parent;
    }

    void solveDoubleBlack(node *r) {
        node *p = r ? r->parent : hot;
        if (!p)
            return;
        node *s = (r == p->left) ? p->right : p->right;
        if (s->clr == BLACK) {
            node *t = nullptr;
            if (s->right->clr == RED)
                t = s->right;
            if (s->left->clr == RED)
                t = s->left;
            if (t) {
                color oldC = p->clr;
                node *b = (root == p ? root : p) = rotateAt(t);
                if (b->left) {
                    b->left->clr = BLACK;
                }
                if (b->right) {
                    b->right->clr = BLACK;
                }
                b->clr = oldC;
            } else {
                s->clr = RED;
                s->height--;
                if (p->clr == RED) {
                    p->clr = BLACK;
                } else {
                    solveDoubleBlack(p);
                }
            }
        } else {
            s->clr = BLACK;
            p->clr = RED;
            node t = s->parent->left == s ? s->left : s->right;
            hot = p;
            (p == root ? root : p) = rotateAt(t);
            solveDoubleBlack(r);
        }
    }

    bool remove(const A &e) {
        node *x = search(e);
        if (!x)
            return false;
        node *r = removeAt(x, hot);
        if (!root) {
            return true;
        }
        if (!hot) {
            root->clr = BLACK;
            return true;
        }
        if (r->clr == RED) {
            r->clr = BLACK;
            r->height++;
            return true;
        }
        solveDoubleBlack(r);
        return true;
    };
};

template <class T> void printTree(RBTree<T> &tree) {
    using namespace std;

    struct te {
        node<T> n;
        int h;
    };

    queue<te> q;

    if (tree->root) {
        q.push({*tree->root, 0});
    }
    int curH = 0;
    while (!q.empty()) {
        te t = q.front();
        node<T> n = t.n;
        int h = t.h;
        if (curH < t.h) {
            curH = t.h;
            cout << endl;
        }
        cout << n.data << ' ';
        if (n.left) {
            q.push({*n.left, curH + 1});
        }
        if (n.right) {
            q.push({*n.right, curH + 1});
        }
    }
    return;
}