#include <algorithm>
#include <vector>
template <class T>
struct heap {
    std::vector<T> vect;
    int size;

    bool cmp(T const &a, T const &b) {
        return a > b;
    }

    bool in_heap(int i) {
        return i >= 0 && size >= i;
    }
    int parent(int i) {
        return (i - 1) / 2;
    }
    int lchild(int i) {
        return i * 2 + 1;
    }
    int rchild(int i) {
        return i * 2 + 2;
    }

    T &bigger(int i, int j) {
        return vect[i] > vect[j] ? vect[i] : vect[j];
    }

    int next_parent(int i) {
        int j, r = i;
        // T t = vect[i];
        if (in_heap(j = lchild(i)) && cmp(vect[j], vect[r])) {
            r = j;
        }
        if (in_heap(j = rchild(i)) && cmp(vect[j], vect[r])) {
            r = j;
        }
        return r;
    }

    T get_max() {
        return vect[0];
    }

    T del_max() {
        T pre_max = vect[0];
        vect[0] = vect[size--];
        percolate_down(0);
        return pre_max;
    }

    void insert(T e) {
        size++;
        vect.push_back(e);
    }

    void percolate_up(int i) {
        int j = i;
        T t = vect[i];
        while (in_heap(j = parent(i))) {
            if (cmp(vect[j], vect[i]))
                break;
            vect[i] = vect[j];
            i = j;
        }
        vect[i] = t;
    }

    void percolate_down(int i) {
        int j = i, t;
        // T tm = vect[i];
        while (j != (t = next_parent(j))) {
            // vect[t] = vect[j];
            std::swap(vect[i], vect[j]);
            j = t;
        }
    }

    void floyd(int n) {
        for (int i = parent(n - 1); in_heap(i); i--) {
            percolate_down(i);
        }
    }

    void heap(vector<T> &v) {
        vect = v;
        size = vect.size();
        floyd(size);
    }
};