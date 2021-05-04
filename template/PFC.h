#include <vector>
template <class T> struct BinNode {
    BinNode *left = nullptr, *right = nullptr, *parent = nullptr;
    T value;
    BinNode(T e, BinNode *pr) : value(e), parent(pr){};
    BinNode(T e, BinNode *pr, BinNode *left, BinNode *right)
        : value(e), parent(pr), left(left), right(right){};
};

template <class T> struct BinTree {
    BinNode<T> *root = nullptr;
    void insertRoot(T e) {
        if (!root) {
            root = new BinNode<T>(e, nullptr);
        } else {
            T v = root->value;
            if (v <= e) {
                root = new BinNode<T>(e, nullptr, root, nullptr);
            } else {
                root = new BinNode<T>(e, nullptr, nullptr, root);
            }
        }
    }

    void insertLeft(BinNode<T> *n, T e) {
        n->left = new BinNode<T>(e, n, n->left, nullptr);
    }

    void insertRight(BinNode<T> *n, T e) {
        n->right = new BinNode<T>(e, n, nullptr, n->right);
    }

    void attachLeft(BinNode<T> *n, BinTree<T> *t) {
        n->left = t->root;
        t->root->parent = n;
        delete t;
    }

    void attachRight(BinNode<T> *n, BinTree<T> *t) {
        n->right = t->root;
        t->root->parent = n;
        delete t;
    }
};

using PFCTree = BinTree<char>;

using PFCForest = std::vector<PFCTree *>;

#include <algorithm>
#include <bitset>
#include <map>
#include <stdlib.h>
#include <time.h>
using PFCTable = std::map<char, char *>;

#define N_CHAR (0x80 - 0x20)

PFCForest *initForest() {
    PFCForest *forest = new PFCForest;
    for (int i = 0; i < N_CHAR; i++) {
        forest->push_back(new PFCTree);
        (*forest)[i]->insertRoot(0x20 + i);
    }
    return forest;
}

PFCTree *generateTree(PFCForest *forest) {
    srand(time(NULL));
    while (1 < forest->size()) {
        PFCTree *s = new PFCTree;
        s->insertRoot('^');
        int r1 = rand() % forest->size();
        s->attachLeft(s->root, (*forest)[r1]);
        forest->erase(forest->begin() + r1);
        int r2 = rand() % forest->size();
        s->attachRight(s->root, (*forest)[r2]);
        forest->erase(forest->begin() + r2);
        forest->push_back(s);
    }
    return (*forest)[0];
}

#include "BitMap.h"

void generateCT(BitMap *code, int length, PFCTable *table, BinNode<char> *v) {
    if (!v->left && !v->left) {
        (*table)[v->value] = code->toString(length);
        return;
    }
    if (v->left) {
        code->clear(length);
        generateCT(code, length + 1, table, v->right);
    }
    if (v->right) {
        code->clear(length);
        generateCT(code, length + 1, table, v->left);
    }
}

