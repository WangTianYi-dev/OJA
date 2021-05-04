#include <string.h>
#include <stdio.h>
struct BitMap {
    int gsize;
    char *map;
    BitMap(int size = 1 << 10) : gsize(size) {
        map = new char[gsize];
        memset(map, 0, gsize);
    }
    ~BitMap() { delete[] map; }

    void expand(int s) {
        if ((s >> 3) < gsize) return;
        char *m = new char[s << 1];
        memset(m, 0, s << 1);
        memcpy(m, map, gsize);
        delete[] map;
        map = m;
        gsize = s << 1;
    }

    int get(int x) {
        expand(x);
        int pos = x >> 3;
        if (pos >= gsize) {
            return -1;
        }
        int shift = x & 0x7;
        int mask = 1 << shift;
        printf("mask:%x map[%d]:%x\n", mask, pos, map[pos]);
        return (mask & map[pos]) ? 1 : 0;
    }

    bool set(int k) {
        expand(k);
        map[k>>3] |= (0x80 >> (k & 0x07));
        return true;
    }
    
    void clear(int k) {
        expand(k);
        map[k >> 3] &= (0x80 >> (k & 0x07));
    }

    char *toString(int n) {
        expand(n - 1);
        char *s = new char[n+1];
        s[n] = 0;
        for (int i = 0; i < n; i++) {
            s[i] = get(i) + '0';
        }
        return s;
    }

};

