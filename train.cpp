#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 1600010;
const int PUSH = 1, POP = 2;
struct Stack {
    int data[maxn];
    int size;
    void push(int i)
    {
        data[size++] = i;
    }
    void pop()
    {
        size--;
    }
    int getTop()
    {
        return data[size - 1];
    }
} s;

int a[maxn], ops[2 * maxn];
int n, m;
// emulate stack permutation
bool permute()
{
    int iOp = 1, iA = 1;
    int curNum = 1;
    s.push(curNum++);
    ops[iOp++] = PUSH;
    while (iOp <= 2 * n) {
        int top = s.getTop();
        int back = a[iA];
        #ifdef DEBUG
        cout << iOp << ' ' << top << ' ' << back << endl;
        #endif
        if (top > back || s.size > m) {
            return false;
        }
        if (top == back) {
            ops[iOp++] = POP;
            s.pop();
            iA++;
        }
        if (top < back) {
            ops[iOp++] = PUSH;
            s.push(curNum++);
        }
    }
    return true;
}

int main()
{
    scanf(" %d %d", &n, &m);
    s.size = 0;
    for (int i = 1; i <= n; i++) {
        scanf(" %d", &a[i]);
    }
    if (permute()) {
        for (int i = 1; i <= 2 * n; i++) {
            switch (ops[i]) {
            case POP:
                puts("pop");
                break;
            case PUSH:
                puts("push");
                break;
            }
        }
    } else {
        puts("No");
    }
    return 0;
}
