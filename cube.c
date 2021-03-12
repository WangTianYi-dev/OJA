#include <stdio.h>
int main()
{
    int n, x, i, j;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &x);
        if (x < 0) {
            printf("No\n");
            continue;
        }
        for (i = 1; i * i * i <= x; i++)
            ;
        --i;
        x -= i * i * i;
        for (j = 1; j * j * j <= x; j++)
            ;
        --j;
        x -= j * j * j;
        printf("%s\n", x ? "No\n" : "Yes\n");
    }
    return 0;
}