#include <stdio.h>
#define maxn 1010
int guess[maxn], code[maxn];

int main()
{
    int n;
    int game = 0;
    while (scanf("%d", &n) == 1 && n) {
        printf("Game %d:\n", ++game);
        for (int i = 0; i < n; i++)
            scanf("%d", code + i);
        for (;;) {
            for (int j = 0; j < n; j++) {
                scanf("%d", guess + j);
            }
            if (guess[0] == 0)
                break;
            int strong = 0;
            for (int j = 0; j < n; j++) {
                if (guess[j] == code[j]) {
                    strong++;
                }
            }
            int sumweak = 0;
            for (int j = 1; j <= 9; j++) {
                int weak1 = 0, weak2 = 0;
                for (int k = 0; k < n; k++) {
                    if (code[k] == j) {
                        weak1++;
                        //printf("1::%d:%d\n",j, k);
                    }
                    if (guess[k] == j) {
                        weak2++;
                        //printf("2::%d:%d\n",j, k);
                    }
                }
                sumweak += weak1 > weak2 ? weak2 : weak1;
            }
            printf("    (%d,%d)\n", strong, sumweak - strong);
        }
    }
    return 0;
}