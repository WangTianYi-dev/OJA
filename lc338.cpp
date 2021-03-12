#include "leetcode.h"

vector<int> countBits(int num)
{
    vector<int> bits(num + 1);
    int highBit = 0;
    for (int i = 0; i <= num; i++) {
        if ((i & (i - 1)) == 0) {
            highBit = i;
        }
        bits[i] = bits[i - highBit] + 1;
    }
    return bits;
}

int main()
{
    return 0;
}