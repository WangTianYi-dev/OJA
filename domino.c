#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *add(char a[], char b[]) // highprec addition return string of int prefix a \0
{
    int len, aIdx, bIdx, k, ifCarry, adderA, adderB, adderTemp;
    char *resultRev, *back;

    len = (strlen(a) > strlen(b)) ? strlen(a) + 2 : strlen(b) + 2;
    resultRev = (char *)malloc(len * sizeof(char));
    back = (char *)malloc(len * sizeof(char));

    // i,j are index of adder
    aIdx = strlen(a) - 1;
    bIdx = strlen(b) - 1;
    k = 0;
    ifCarry = 0;

    while (aIdx >= 0 || bIdx >= 0)
    {
        // if goes over range
        if (aIdx < 0)
            adderA = '0';
        else
            adderA = a[aIdx];
        if (bIdx < 0)
            adderB = '0';
        else
            adderB = b[bIdx];
        adderTemp = adderA - '0' + adderB - '0';

        if (ifCarry == 1)
            adderTemp += 1;
        if (adderTemp > 9)
        {
            ifCarry = 1;
            adderTemp %= 10;
        }
        else
            ifCarry = 0;
        resultRev[k++] = adderTemp + '0';
        aIdx--;
        bIdx--;
    }
    if (ifCarry)
        resultRev[k++] = '1';
    resultRev[k] = '\0';

    //reverse
    aIdx = 0;
    for (k -= 1; k >= 0; k--)
        back[aIdx++] = resultRev[k];
    back[aIdx] = 0;
#ifdef TEST
    printf("add:%s\n", back);
#endif
    return back;
}

char *sub(char a[], char b[]) // highprec subtract
{
    int len, aIdx, bIdx, k, down, adderA, adderB, adderTemp;
    char *resultRev, *back;

    len = strlen(a);
    resultRev = (char *)malloc(len * sizeof(char));
    back = (char *)malloc(len * sizeof(char));

    aIdx = strlen(a) - 1;
    bIdx = strlen(b) - 1;
    k = 0;
    down = 0;

    while (aIdx >= 0 || bIdx >= 0)
    {
        if (aIdx < 0)
            adderA = '0';
        else
            adderA = a[aIdx];
        if (bIdx < 0)
            adderB = '0';
        else
            adderB = b[bIdx];
        adderTemp = adderA - '0' - (adderB - '0') - down;
        if (adderTemp < 0)
        {
            down = 1;
            adderTemp += 10;
        }
        else
            down = 0;
        resultRev[k++] = adderTemp + '0';
        aIdx--;
        bIdx--;
    }
    while (resultRev[--k] == '0')
        ;

    //reverse
    aIdx = 0;
    for (k; k >= 0; k--)
    {
        back[aIdx++] = resultRev[k];
    }
    back[aIdx] = 0;
#ifdef TEST
    printf("%s sub %s :%s\n", a, b, back);
#endif
    return back;
}

char *power(int n) // return power n of 2
{
    int i;
    char *temp = "2";

    for (i = 2; i <= n; i++)
    {
        temp = add(temp, temp);
    }
#ifdef TEST
    printf("power:%s\n", temp);
#endif
    return temp;
}

char *fib(int n) // return the n-th number of fibanacci
{
    char *p = "1", *q = "1";
    char *s = "1";
    int i;

    for (i = 0; i < n - 1; i++)
    {
        s = add(p, q);
        p = q;
        q = s;
    }
#ifdef TEST
    printf("fib:%s\n", s);
#endif
    return s;
}

int main()
{
    int n;
    char *mi, *f;

    scanf("%d", &n);

    mi = power(n);
    f = fib(n);
    f = add(f, f);

    printf("%s\n", sub(mi, f));

    return 0;
}
