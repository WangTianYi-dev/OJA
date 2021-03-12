// UVa455

#include <stdio.h>
#include <string.h>

char s[85], u[85];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf(" %s", s);
        int sz = strlen(s);
        for (int len = 1; len <= sz; len++) {
            int match = 1;
            strncpy(u, s, len);
            for (int num = 1; num * len < sz; num++) {
                int j = strncmp(s + num * len, u, len);
                if (strncmp(s + num * len, u, len) != 0) {
                    match = 0;
                    break;
                }
            }
            if (match) {
                printf("%d\n", len);
                break;
            }
        }
        printf("\n");
    }
    return 0;
}