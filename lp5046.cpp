#include <cstdio>
#include <iostream>
const int maxn = 1e9 + 10;
struct Node {
    int value, left = 0, right = 0, count, subsize;
} tree[maxn];

int sum;
void add(int sub, int val)
{
    tree[sub].subsize++;
    if (tree[sub].value == val) {
        tree[sub].count++;
        return;
    }
    if (tree[sub].value < val) {
        if (tree[sub].right != 0) {
            add(tree[sub].right, val);
        } else {
            sum++;
            tree[sum].value = val;
            tree[sum].size = tree[sum].count = 1;
        }
    }
};