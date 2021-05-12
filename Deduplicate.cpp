#include <cctype>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
const int maxn = 6e5 + 10;
const int maxm = 5e4;
char temp[50];
struct Bucket {
    // bool in;
    int size;
    char sto[50][50];
    bool printed[50];
} b[maxm];

int n;

size_t BKDRHash(const char *str) {
    register size_t hash = 0;
    while (size_t ch = (size_t)*str++) {
        hash = hash * 131 + ch;
    }
    return hash;
}

int search(const int hash, const char *str) {
    // int hash = BKDRHash(str) % maxm;
    for (int i = 0; i < b[hash].size; i++) {
        if (strcmp(str, b[hash].sto[i]) == 0) {
            return i;
        }
    }
    return -1;
}

void insert(const int hash, const char *str) {
    strcpy(b[hash].sto[b[hash].size++], str);
}

void routine(const char *str) {
    int hash = BKDRHash(str) % maxm;
    int loc = search(hash, str);
    if (loc == -1) {
        insert(hash, str);
        return;
    } else {
        if (b[hash].printed[loc]) {
            return;
        }
        printf("%s\n", b[hash].sto[loc]);
        b[hash].printed[loc] = true;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", temp);
        routine(temp);
    }
    return 0;
}
