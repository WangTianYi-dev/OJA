#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
// #include <stack>
template <class T> struct RedBlackTree;
template <class T> using RBTree = RedBlackTree<T>;
enum color { red, black };

template <class T> struct node {
    T val;
    node *parent;
    node *leftChild;
    node *rightChild;
    int height;
    color c;

    node() {}

    node(T v, node *p, node *l, node *r)
        : val(v), parent(p), leftChild(l), rightChild(r) {
        height = -1;
        c = red;
    }
};

template <class T> bool IsRoot(node<T> *n) { return !(n->parent); }
template <class T> bool IsBlack(node<T> *n) { return !n || n->c == black; }
template <class T> bool IsLeftChild(node<T> *n) {
    return !IsRoot(n) && n->parent->leftChild == n;
}
template <class T> bool IsRightChild(node<T> *n) {
    return !IsRoot(n) && n->parent->rightChild == n;
}

template <class T> node<T> *sibling(node<T> *n) {
    node<T> *p = n->parent;
    if (n == p->leftChild) {
        return p->rightChild;
    } else {
        return p->leftChild;
    }
}

template <class T> node<T> *uncle(node<T> *n) { return sibling(n->parent); }

template <class T> int stature(node<T> *n) {
    if (n == nullptr) {
        return 0;
    } else {
        return n->height;
    }
}
template <class T> int updateHeight(node<T> *x) {
    x->height = std::max(stature(x->leftChild), stature(x->rightChild));
    if (isBlack(x))
        x->height++;
    return x->height;
};

template <class T>
node<T> *rebuild(node<T> *a, node<T> *b, node<T> *c, node<T> *t1, node<T> *t2,
                 node<T> *t3, node<T> *t4) {
    b->leftChild = a, b->rightChild = c, a->parent = b, c->parent = b;
    a->leftChild = t1, a->rightChild = t2;
    c->leftChild = t3, c->rightChild = t4;
    if (t1)
        t1->parent = a;
    if (t2)
        t2->parent = a;
    if (t3)
        t3->parent = c;
    if (t4)
        t4->parent = c;
    updateHeight(a), updateHeight(b), updateHeight(c);
    return b;
}

template <class T> node<T> *rotateAt(node<T> *x, node<T> *p, node<T> *g) {
    node<T> *a, *b, *c, *t1, *t2, *t3, *t4;
    if (IsRightChild(p)) {
        a = g;
        t1 = g->leftChild;
        if (IsRightChild(x)) {
            b = p;
            c = x;
        } else {
            b = x;
            c = p;
        }
    } else {
        c = g;
        t4 = g->rightChild;
        if (IsRightChild(x)) {
            a = p;
            b = x;
        } else {
            a = x;
            b = p;
        }
    }
    return b;
}

template <class T> struct RedBlackTree {
    node<T> *root;
    int size;
    node<T> *hot;
    node<T> *search(T v) {
        hot = root;
        node<T> *cur = root;
        while (cur && cur->val != v) {
            hot = cur;
            if (v < cur->val) {
                cur = cur->leftChild;
            } else {
                cur = cur->rightChild;
            }
        }
        return cur;
    };

    node<T> *insert(const T &e) {
        node<T> *n = search(e);
        if (n)
            return n;
        n = new node<T>(e, hot, nullptr, nullptr);
        size++;
        solveDoubleRed(n);
        return n ? n : hot->parent;
    };

    bool remove(const T &e);
    void solveDoubleRed(node<T> *x) {
        if (IsRoot(x)) {
            x->color = black;
            x->height++;
            return;
        }
        node<T> *p = x->parent;
        if (IsBlack(p))
            return;
        node<T> *g = p->parent;
        node<T> *u = uncle(x);
        if (IsBlack(u)) {
            node<T> *b = rotateAt(x, p, g);
            if (node<T> *gg = g->parent) {
            }
        }
    }
    
    void solveDoubleBlack(node<T> *x);
};
