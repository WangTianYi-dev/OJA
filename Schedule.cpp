#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxn 4000007

typedef struct task {
    unsigned long long priority;
    char name[9];
} task;

// former
bool operator<(const task &a, const task &b) {
    return a.priority == b.priority ? strcmp(a.name, b.name) < 0 : a.priority < b.priority;
}

task q[maxn];

int n, m;

#define in_heap(i) (i > 0 && i <= n)
#define parent(i) (i / 2)
#define left(i) (i * 2)
#define right(i) (i * 2 + 1)

int next_parent(int i) {
    int x = i;
    if (in_heap(left(i)) && q[left(i)] < q[x]) {
        x = left(i);
    }
    if (in_heap(right(i)) && q[right(i)] < q[x]) {
        x = right(i);
    }
    return x;
}

void Swap(task &a, task &b) {
    task c = a;
    a = b;
    b = c;
}

int perlocate_down(int i) {
    int j;
    while (i != (j = next_parent(i))) {
        Swap(q[i], q[j]);
        i = j;
    }
    return i;
}

int perlocate_up(int i) {
    while (in_heap(parent(i))) {
        int j = parent(i);
        if (q[j] < q[i])
            break;
        Swap(q[i], q[j]);
        i = j;
    }
    return i;
}

void floyd() {
    for (int i = parent(n); in_heap(i); i--) {
        perlocate_down(i);
    }
}

task del_max() {
    task t = q[1];
    q[1] = q[n--];
    perlocate_down(1);
    return t;
}

void insert(task t) {
    q[++n] = t;
    perlocate_up(n);
}

void printqueue() {
    for (int i = 1; i <= n; i++) {
        printf("%d: pri: %lld, name: %s\n", i, q[i].priority, q[i].name);
    }
    puts("------------------");
}

int main() {
    scanf("%d", &n);
    scanf("%d", &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &q[i].priority);
        scanf("%s", q[i].name);
    }
    floyd();
#ifdef debug
    printqueue();
#endif
    for (int i = 0; i < m; i++) {
        task t = del_max();
        printf("%s\n", t.name);
        t.priority *= 2;
        if (t.priority < ((long long)1 << 32)) {
            insert(t);
        }
#ifdef debug
        printqueue();
#endif
        if (n == 0)
            break;
    }
    return 0;
}
