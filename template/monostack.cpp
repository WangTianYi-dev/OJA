#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;
struct decStack {
    stack<int> s;
    decStack() {};
    void push(int x)
    {
        while (s.empty() || s.top() > x) {
            s.pop();
        }
        s.push(x);
    }
    int pop()
    {
        int t = s.top();
        s.pop();
        return t;
    }
};

struct incStack {
    stack<int> s;
    incStack() {};
    void push(int x)
    {
        while (s.empty() || s.top() < x) {
            s.pop();
        }
        s.push(x);
    }
    int pop()
    {
        int t = s.top();
        s.pop();
        return t;
    }
};
