//
//  main.cpp
//  Temperature
//
//  Created by Daer Wang on 2021/4/16.
//

//#include <iostream>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
#include "temperature.h"
using ll = long long;

template <class T>
struct Vector {
    T* data;
    int size = 20, len;
    Vector()
        : len(0)
    {
        data = new T[size];
    }

    Vector(const Vector& v)
    {
        size = v.size;
        data = new T[v.size];
        memcpy(data, v.data, size * sizeof(T));
    }

    T& operator[](int idx)
    {
        return data[idx];
    }

    void push_back(T t)
    {
        if (size == len) {
            size *= 2;
            T* ndata = new T[size];
            memcpy(ndata, data, sizeof(T) * size);
            delete[] data;
            data = ndata;
        }
        data[len++] = t;
    }
};

int main(int argc, const char* argv[])
{
    // insert code here...
    //    std::cout << "Hello, World!\n";
    int n, q;
    n = GetNumOfStation();
    int x, y, v;
    for (int i = 0; i < n; i++) {
        GetStationInfo(i, &x, &y, &v);
    }
    int x1, y1, x2, y2;
    while (GetQuery(&x1, &y1, &x2, &y2)) {
    }
    return 0;
}
