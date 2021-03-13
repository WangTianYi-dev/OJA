#include <cstdio>
#include <iostream>
const int maxn = 1e9 + 10;
struct Node {
    int value, left, right, count, subsize;
} tree[maxn];

void add(int sub, int val) {
    tree[sub].subsize++;
    if (tree[sub].value == val) {

    }
};