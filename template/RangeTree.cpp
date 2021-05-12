#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
using namespace std;

template <class T>
struct QuickSelect {
    QuickSelect()
    {
        srand(time(0));
    }

    void swap(T data[], int a, int b)
    {
        T t = data[a];
        data[a] = data[b];
        data[b] = t;
    }

    int operator()(T data[], int lo, int hi, int k)
    {
        if (lo >= hi) {
            return data[hi - 1];
        }
        int p = rand() % (hi - lo) + lo;
        int i = hi - 1, j = hi - 1;
        swap(data, lo, p);
        while (j > lo) {
            if (data[j] >= data[lo]) {
                swap(data, i, j);
                i--;
            }
            j--;
        }
        swap(data, i, j);
        // printf("lo: %d, hi: %d\n", lo, hi);
        // for (int i = lo; i < hi; i++) {
        //     cout << data[i] << ' ';
        // }
        // cout << endl;
        int curRnk = i - lo + 1;
        // cout << "curRnk: " << curRnk << endl;
        if (curRnk == k) {
            return data[i];
        } else if (curRnk > k) {
            return operator()(data, lo, i, k);
        } else {
            return operator()(data, i + 1, hi, k - curRnk);
        }
    }
};

int main()
{
    int a[] = { 312, 432, 42, 52, 412, 465 };
    QuickSelect<int> qs;
    for (int i = 1; i <= 6; i++) {
        std::cout << i << "th: " << qs(a, 0, 6, i) << '\n';
    }
}
