#include <cstdio>
#include <cstring>
using namespace std;

const int maxd = 20;
int l;
int D, I;

int main() {
    scanf("%d", &l);

    while (scanf("%d%d", &D, &I) == 2) {
        int n = (1 << D) - 1;
        int p = 1;
        for (int i = 0; i < D - 1; i++) {
            if (I % 2) {
                p = p * 2;
                I = (I + 1) / 2;
            } else {
                p = p * 2 + 1;
                I = I / 2;
            }
        }
        printf("%d\n", p);
    }
    return 0;
}
