#include "stdlib.h"
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <string>
using namespace std;

map<string, int> var;
int n = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, q = 0;
bool lk = false, enter = true, last = false;
struct pro {
    int id, now, sum; //编号，执行到哪，程序行数
    string action[30][2];
} num, aa;
string temp, waste;
deque<pro> wt, st;

void run(pro &aa) {
    int Q = q;
    bool judge = true;
    while (Q > 0) {
        if (aa.action[aa.now][0] == "end") {
            return;
        } else if (aa.action[aa.now][0] == "unlock") {
            lk = false;
            aa.now++;
            Q -= t4;
            if (!st.empty()) {
                wt.push_front(st.front());
                st.pop_front();
            }
        } else if (aa.action[aa.now][0] == "lock") {
            if (lk) {
                st.push_back(aa);
                return;
            }
            lk = true;
            Q -= t3;
            aa.now++;
        } else if (aa.action[aa.now][0] == "print") {
            cout << aa.id << ": " << var[aa.action[aa.now][1]] << endl;
            aa.now++;
            Q -= t2;
        } else {
            var[aa.action[aa.now][0]] = atoi(aa.action[aa.now][1].c_str());
            aa.now++;
            Q -= t1;
        }
    }
    wt.push_back(aa);
}

int main() {
    int t = 0;
    cin >> t;
    while (t--) {
        lk = false, enter = true, last = false;
        if (t == 0) {
            last = true;
        }
        var.clear(), wt.clear(), st.clear();
        cin >> n >> t1 >> t2 >> t3 >> t4 >> t5 >> q;
        for (int i = 0; i < n; i++) {
            num.id = i + 1;
            num.now = 0;
            num.sum = 0;
            while (true) {
                cin >> temp;
                if (temp == "end") {
                    num.action[num.sum++][0] = temp;
                    break;
                } else if (temp == "unlock" || temp == "lock") {
                    num.action[num.sum++][0] = temp;
                } else if (temp == "print") {
                    int a = num.sum;
                    num.action[a][0] = temp;
                    cin >> num.action[num.sum++][1];
                } else {
                    int a = num.sum;
                    num.action[a][0] = temp;
                    var[temp] = 0;
                    cin >> waste >> num.action[num.sum++][1];
                }
            }
            wt.push_back(num);
        }
        while (!wt.empty()) {
            aa = wt.front();
            wt.pop_front();
            run(aa);
        }
        if (!last) {
            cout << endl;
        }
    }
    return 0;
}
