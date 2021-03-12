#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
char dat[10000000];

int main()
{
    int len = 0;
    while (1) {
        scanf(" %c", dat + len);
        if (dat[len] == 'E') {
            break;
        } else {
            len++;
        }
    }

    int wWin1 = 0, lWin1 = 0, wWin2 = 0, lWin2 = 0;
    int target1 = 11, target2 = 21;
    for (int i = 0; i < len; i++) {
        if (dat[i] == 'W') {
            wWin1++;
        }
        if (dat[i] == 'L') {
            lWin1++;
        }
        if (wWin1 == target1 || lWin1 == target1) {
            if (abs(lWin1 - wWin1) > 1) {
                printf("%d:%d\n", wWin1, lWin1);
                wWin1 = 0;
                lWin1 = 0;
                target1 = 11;
            } else {
                target1++;
            }
        }
    }
    printf("%d:%d\n", wWin1, lWin1);
    puts("");

    for (int i = 0; i < len; i++) {
        if (dat[i] == 'W') {
            wWin2++;
        }
        if (dat[i] == 'L') {
            lWin2++;
        }
        if (wWin2 == target2 || lWin2 == target2) {
            if (abs(wWin2 - lWin2) > 1) {
                printf("%d:%d\n", wWin2, lWin2);
                wWin2 = 0;
                lWin2 = 0;
                target2 = 21;
            } else {
                target2++;
            }
        }
    }
    printf("%d:%d\n", wWin2, lWin2);
    return 0;
}
