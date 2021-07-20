#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
const int MAXN = 1010;

int target[MAXN];
int n;
int main() {
    while (scanf("%d", &n), n) {
        while (1) {
            scanf("%d", &target[1]);
            if (target[1] == 0) {
                break;
            }
            for (int i = 2; i <= n; i++) {
                scanf("%d", &target[i]);
            }
            stack<int> st;
            int ia = 1, ib = 1;
            bool ok = true;
            while (ia <= n) {
                if (ib == target[ia]) {
                    ib++, ia++;
                } else if (!st.empty() && target[ia] == st.top()) {
                    st.pop();
                    ia++;
                } else if (ib <= n) {
                    st.push(ib++);
                } else {
                    ok = false;
                    break;
                }
            }
            printf("%s\n", ok ? "Yes" : "No");
        }
        printf("\n");
    }
}