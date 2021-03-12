#include <cctype>
#include <cstring>
#include <iostream>
using namespace std;

int main()
{
    int T, cnt, sz;
    double W[256], ans;
    // W is a analog hashmap
    char buf[256], c, s; // c stands for current character,
        // s stands for current atom
    W['C'] = 12.01, W['H'] = 1.008, W['O'] = 16.0, W['N'] = 14.01;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", buf);
        ans = 0;
        s = 0;
        cnt = -1;
        // cnt = -1 means no number of atoms available
        sz = strlen(buf);
        for (int i = 0; i < sz; i++) {
            char c = buf[i];
            if (isupper(c)) { // if c is C, H...
            // add on ans
                if (i) {
                    // if i is not 0
                    // exclude extra add on ans when first char
                    if (cnt == -1)
                        cnt = 1;
                    // add on mass of last atoms
                    ans += W[s] * cnt;
                }
                s = c;
                cnt = -1;
            } else {
                // count for numbers
                if (cnt == -1)
                    cnt = 0;
                cnt = cnt * 10 + c - '0';
            }
        }
        if (cnt == -1)
            cnt = 1;
        ans += W[s] * cnt;
        printf("%.3lf\n", ans);
    }
    return 0;
}
