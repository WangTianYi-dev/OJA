#include <ctype.h>
#include <stdio.h>
#include <string.h>
// '|' stands for character not reverseable
// since that the reverse of a reverseable character is still reversable,
// we can only put in the column of 'Reverse'
const char* rev = "A|||3||HIL|JM|O|||2TUVWXY51SE|Z||8";

// just like a hash map
const char* msg[] = { "not a palindrome", "a regular palindrome", "a mirrored string",
    "a mirrored palindrome" };

// translate char to index of rev
char GetRev(char ch)
{
    if (isalpha(ch))
        return rev[ch - 'A'];
    else
        // because there is not a '0'
        return rev[ch - '0' + 25];
}

int main()
{
    char s[30];
    while (scanf("%s", s) == 1) {
        int len = strlen(s);
        int ifPalin = 1, ifMirror = 1;
        for (int i = 0; i < (len + 1) / 2; i++) {
            if (s[i] != s[len - 1 - i])
                ifPalin = 0;
            if (GetRev(s[i]) != s[len - 1 - i])
                ifMirror = 0;
        }
        printf("%s -- is %s.\n\n", s, msg[ifPalin + ifMirror * 2]);
    }
    return 0;
}
