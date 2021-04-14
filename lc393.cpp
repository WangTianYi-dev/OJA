#include "leetcode.h"

class Solution {
public:
    bool validUtf8(vector<int>& data)
    {
        int csize = 0;
        int mask1 = 1 << 7;
        int mask2 = 1 << 6;
        for (int i = 0, l = data.size(); i < l; i++) {
            if (csize == 0) {
                int mask = 1 << 7;
                while (mask && mask & data[i]) {
                    csize++;
                    mask >>= 1;
                }
                if (!csize) {
                    continue;
                }
                if (csize > 4 || csize == 1) {
                    return false;
                }
            } else {
                if (!(data[i] & mask1) || (data[i] & mask2)) {
                    return false;
                }
            }
            csize--;
        }
        return csize == 0;
    }
};