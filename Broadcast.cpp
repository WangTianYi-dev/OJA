#include <cstdio>
#include <cstring>
#include <iostream>
//请勿搬抄，尤其中国石油大学的学生，一定要自己实现，避免查重，加油，有不理解的地方可以与我交流
using namespace std;
#define MAX 10010
int n, m; //小镇数-相距20Km内小镇对数
int queue[MAX], head, tail; //模拟队列-队首-队尾
int cover; //Broadcast放置数量

struct Node {
    int num;
    Node* next;
    Node()
    {
        next = NULL;
    }
    Node(int n, Node* k)
        : num(n)
        , next(k)
    {
    }
};

struct Town {
    int state;
    Node* t;
    Town()
    {
        state = 0;
        t = NULL;
    }
    void insert(int num);
} town[MAX];

void Town::insert(int num)
{
    if (this->t == NULL)
        this->t = new Node(num, NULL);
    else
        this->t = new Node(num, this->t);
}

bool BFS(int x)
{
    queue[tail++] = x;
    town[x].state = 1;
    cover++;
    while (head < tail) {
        Town cur = town[queue[head]];
        Node* tmp = cur.t;
        while (tmp != NULL) {
            if (!town[tmp->num].state) {
                town[tmp->num].state = -cur.state;
                cover++;
                queue[tail++] = tmp->num;
            } else if (town[tmp->num].state == cur.state)
                return false;
            tmp = tmp->next;
        }
        head++;
    }
    return true;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        town[x].insert(y);
        town[y].insert(x);
    }
    for (int i = 1; i <= n; i++) {
        if (town[i].state == 0) {
            if (BFS(i) == false) {
                printf("-1\n");
                return 0;
            }
            if (cover == n) {
                printf("1\n");
                return 0;
            }
        }
    }
    return 0;
}

// ————————————————
// 版权声明：本文为CSDN博主「菜小波」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
// 原文链接：https://blog.csdn.net/qq_16497423/article/details/106537997