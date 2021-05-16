#include <stdio.h>
#include <string.h>

#define MAX 43000
struct Board {
    int hash, former;
    char str[9];
} m[2 * MAX], ts;

int map[MAX] = {};

int contor(struct Board *b) {
    int res = 0;
    static int fact[8] = {1, 1, 2, 6, 24, 120, 720, 5040};
    for (int i = 0; i < 8; i++) {
        int k = 0;
        for (int j = i + 1; j < 8; j++) {
            if (b->str[j] < b->str[i]) {
                k++;
            }
        }
        res += k * fact[7 - i];
    }
    return res;
}

struct Board A(struct Board *b) {
    struct Board bd = {.former = 0};
    for (int i = 0; i < 8; i++) {
        bd.str[(i + 4) % 8] = b->str[i];
    }
    bd.hash = contor(&bd);
    return bd;
}

struct Board
B(struct Board *b) {
    struct Board bd = {.former = 0};
    for (int i = 0; i < 4; i++)
        bd.str[(i + 3) % 4] = b->str[i];
    for (int i = 4; i < 8; i++)
        bd.str[(i + 3) % 4 + 4] = b->str[i];
    bd.hash = contor(&bd);
    return bd;
}

struct Board
C(struct Board *b) {
    struct Board bd = {.former = 0};
    strcpy(bd.str, b->str);
    bd.str[5] = b->str[1];
    bd.str[1] = b->str[2];
    bd.str[2] = b->str[6];
    bd.str[6] = b->str[5];
    bd.hash = contor(&bd);
    return bd;
}

void
init(char s[9]) {
    strcpy(m[0].str, s);
    m[0].hash = contor(&m[0]);
    int front = 0, rear = 1;
    while (front < rear) {
        if (map[m[front].hash]) {
            front++;
            continue;
        }
        map[m[front].hash] = map[m[m[front].former].hash] + 1;
        m[rear] = A(&m[front]);
        if (!map[m[rear].hash]) {
            m[rear].former = front;
            rear++;
        }
        m[rear] = B(&m[front]);
        if (!map[m[rear].hash]) {
            m[rear].former = front;
            rear++;
        }
        m[rear] = C(&m[front]);
        if (!map[m[rear].hash]) {
            m[rear].former = front;
            rear++;
        }
        front++;
    }
}

int main() {
    init("12348765");
    int n;
    scanf("%d", &n);
    while (n--) {
        int tmp;
        for (int i = 0; i < 4; i++) {
            scanf("%d", &tmp);
            ts.str[i] = tmp + '0';
        }
        for (int i = 4; i < 8; i++) {
            scanf("%d", &tmp);
            ts.str[(8 - i) + 3] = tmp + '0';
        }
        ts.hash = contor(&ts);
        printf("%d\n", map[ts.hash] - 1);
    }
    return 0;
}
