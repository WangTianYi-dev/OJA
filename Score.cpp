#include <stdio.h>
#include <string.h>
int main()
{
    int T;
    scanf("%d", &T);
    char s[81];
    while (T--) {
        int sum = 0, tmp = 0;
        scanf("%s", s);
        for (int i = 0; i <= strlen(s); i++) {
            if (s[i] == 'O') {
                sum += ++tmp;
            } else {
                tmp = 0;
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}
