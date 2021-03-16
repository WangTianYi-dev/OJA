#include <cstdio>
#include <cctype>
using namespace std;

inline int qread()
{
    int res = 0, k = 1;
    char c = getchar();
    while (!isdigit(c)) {
        if (c == '-')
            k = -1;
        c = getchar();
    }
    while (isdigit(c)) {
        res = (res << 1) + (res << 3) + c - 48;
        c = getchar();
    }
    return res * k;
}