#include <algorithm>
#include <assert.h>
#include <iostream>
#include <vector>
// template <class T> using SortedVec = std::vector<T>;
// typedef long long Rank;

template <class T> class SortedVec : public std::vector<T> {
  public:
    T &back() { return (*this)[this->size() - 1]; }

    int search(T &e) {
        int lo = 0, hi = this->size() - 1, mi = 0;
        while (lo < hi) {
            mi = (lo + hi) >> 1;
            if (e < (*this)[mi]) {
                hi = mi;
            } else {
                lo = mi + 1;
            }
        }
        return lo - 1;
    }
    void insert(int p, T &e) { this->insert(this->begin() + p, e); }

    // [lo, hi)
    SortedVec<T> slice(int lo, int hi) {
        SortedVec<T> sv(this->begin() + lo, this->begin() + hi);
        return sv;
    }

    SortedVec<T> &operator+=(SortedVec<T> &sv) {
        int l = sv.size();
        for (int i = 0; i < l; i++) {
            this->push_back(sv[i]);
        }
    }

    T remove(int r) { return remove(this->begin() + r); }
};

template <class T> struct BTNode;
template <class T> using p = BTNode<T> *;

template <class T> struct BTNode {
    p<T> parent;
    SortedVec<T> key;
    SortedVec<p<T>> child;
    BTNode() {
        parent = nullptr;
        child.push_back(nullptr);
    }

    BTNode(T e, p<T> lc = nullptr, p<T> rc = nullptr) {
        parent = nullptr;
        key.push_back(e);
        child.push_back(lc);
        child.push_back(rc);
        if (lc)
            lc->parent = this;
        if (rc)
            rc->parent = this;
    }
};

template <class T> class BTree {
    int size;
    int order;
    p<T> root;
    p<T> hot;

    void release(p<T> p) {
        if (p->lc) {
            release(p->lc);
        }
        if (p->rc) {
            release(p->rc);
        }
        delete p;
    }

    void solveOverflow(p<T> v) {
        if (order >= v->child.size())
            return;
        int s = order / 2;
        p<T> pr = v->parent;
        if (!pr) {
            root = pr = new BTNode<T>();
            pr->child[0] = v;
            v->parent = pr;
        }
        p<T> u = new BTNode<T>();
        u->child += v->child.slice(s + 1, v->child.size());
        // u->child += v->child.slice(order - s, v->child.size());
        u->key += u->key.slice(s + 1, u->key.size());

        if (u->child[0]) {
            for (int i = 0, l = u->child.size(); i < l; i++) {
                u->child[i]->parent = u;
            }
        }
        u->parent = pr;
        int r = 1 + pr->key.search(v->key[s]);
        pr->key.insert(r, v->key[s]);
        pr->child.insert(r + 1, u);
        v->key.pop_back();
        solveOverflow(pr);
    }

    void solveUnderflow(p<T> v) {
        if ((order + 1) / 2 <= v->child.size()) return;
        p<T> pr = v->parent;
        
    }

    BTree(int order = 3) : order(order), size(0) { root = new p<T>(); };
    ~BTree() {
        if (root)
            release(root);
    }

    bool empty() const { return !root; }

    p<T> search(const T &e) {
        p<T> v = root;
        hot = nullptr;
        while (v) {
            int r = v->key.search(e);
            if (0 <= r && e == v->key[r])
                return v;
            hot = v;
            v = v->child[r + 1];
        }
        return nullptr;
    }

    bool insert(const T &e) {
        p<T> v = search(e);
        if (v)
            return false;
        int r = search(hot->key, e);
        hot->key.insert(hot->key.begin() + r + 1, e);
        hot->child.insert(r + 2, nullptr);
        size++;
        solveOverflow(hot);
        return true;
    }

    bool remove(const T &e) {
        p<T> v = search(e);
        if (!v)
            return false;
        int r = v->key.search(e);
        if (v->child[0]) {
            p<T> u = v->child[r + 1];
            while (u->child[0])
                u = u->child[0];
            v->key[r] = u->key[0];
            v = u;
            r = 0;
        }
        v->key.remove(r);
        v->child.remove(r + 1);
        size--;
        solveUnderflow(v);
        return true;
    }
};
