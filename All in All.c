#include <stdio.h>
#include <string.h>

#define LEN 10002400

char s[LEN], t[LEN];

int main()
{
    while (scanf("%s%s", s, t) == 2) {
        int lens = strlen(s);
        int lent = strlen(t);
        int found = 1;
        int i = 0, j = 0, k = -1;
        while (found && i < lens) {
            found = 0;
            j = k + 1;
            while (j < lent) {
                if (s[i] == t[j]) {
                    found = 1;
                    break;
                }
                j++;
            }
            k = j;
            i++;
        }
        if (found) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

}