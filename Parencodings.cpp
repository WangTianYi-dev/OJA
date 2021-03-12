#include <iostream>
#include <stack>
#include <vector>
using namespace std;
vector<char> S;
int lastPi = 0;
void read(int pi)
{
    if (pi > lastPi) {
        int times = pi - lastPi;
        lastPi = pi;
        while (times--) {
            S.push_back('(');
        }
    }
    S.push_back(')');
}


int main()
{
    int n;
    cin >> n;
    int len, t;
    while (n--) {  
        S.clear();
        stack<int> left;
        cin >> len;
        lastPi = 0;
        while (len--) {
            cin >> t;
            read(t);
        }
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == '(') {
                left.push(i);
            } else if (S[i] == ')') {
                int j = left.top();
                left.pop();
                cout << (i - j) / 2 + 1 << ' ';
            }
        }
        cout << '\n';
    }
}
