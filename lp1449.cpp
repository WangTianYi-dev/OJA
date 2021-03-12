#include <cstdio>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int parse(string& s)
{
    int rt = 0;
    for (int i = 0; i < s.length(); i++) {
        rt *= 10;
        rt += s[i] - '0';
    }
    return rt;
}

int main()
{
    char c;
    string s;
    stack<int> st;
    for (;;) {
        cin >> c;
        if (c == '@') {
            cout << st.top() << endl;
            break;
        } else if (c == '.') {
            int d = parse(s);
            st.push(d);
            s.clear();
            // printf("%lf pushed\n", st.top());
        } else if ('0' <= c && c <= '9') {
            s += c;
        } else {
            int a, b;
            b = st.top();
            
            st.pop();
            a = st.top();
            st.pop();
            // printf("%lf %lf poped\n", a, b);
            switch (c) {
            case '+':
                st.push(a + b);
                break;
            case '-':
                st.push(a - b);
                break;
            case '*':
                st.push(a * b);
                break;
            case '/':
                st.push(a / b);
                break;
            }
            // printf("%lf pushed\n", st.top());
        }
    }
    return 0;
}
