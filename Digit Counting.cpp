#include <iostream>

#include <cstring>

using namespace std;

int count[10];
int main()
{
    int T;
    scanf("%d", &T);
    int N;
    while (T--) {
        scanf("%d", &N);
        memset(count, 0, sizeof(count));
        for (int i = 1; i <= N; i++) {
            int k = i;
            while (k > 0) {
                count[k % 10]++;
                k /= 10;
            }
        }
        for (int i = 0; i < 9; i++) {
            printf("%d ", count[i]);
        }
        printf("%d", count[9]);
        putchar('\n');
    }
    return 0;
}