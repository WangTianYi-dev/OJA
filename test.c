#include <stdio.h>

int fun1(unsigned word) {
    return (int) ((word << 24) >> 24);
}

int fun2(unsigned word) {
    return (((int) word << 24) >> 24);
}

int main()
{
    unsigned i;
    for (;;) {
        scanf("%x", &i);
        printf("fun1: %x\n", fun1(i));
        printf("fun2: %x\n", fun2(i));
    }
    return 0;
}