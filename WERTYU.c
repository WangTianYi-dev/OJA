#include <stdio.h>
char s[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
int main()
{
    int ch, it;
    while ((ch = getchar()) != EOF) {
        for (it = 1; s[it] && s[it] != ch; it++)
            ;
        if (s[it])
            putchar(s[it - 1]);
        else
            putchar(ch);
    }
    return 0;
}
