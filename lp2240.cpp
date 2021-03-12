#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;

struct Node {
    double weight, value;
} nodes[110];

bool cmp(Node& aa, Node& bb)
{ //定义排序方法
    return aa.value * bb.weight > aa.weight * bb.value; //按性价比从高到低排序，为防止精度问题直接交叉相乘
}
int main()
{
    int N;
    double T;
    cin >> N >> T;
    for (int i = 0; i < N; i++) {
        cin >> nodes[i].weight >> nodes[i].value;
    }
    sort(nodes, nodes + N, cmp);
    // for (int i = 0; i < N; i++) {
    //     cout << nodes[i].weight << ' ' << nodes[i].value << endl;
    // }
    double sumv = 0.0;

    for (int i = 0; i < N; i++) {
        if (nodes[i].weight < T) {
            T -= nodes[i].weight;
            sumv += nodes[i].value;
        } else {
            sumv += nodes[i].value * (T / nodes[i].weight);
            break;
        }
    }
    printf("%.2lf\n", sumv);
    return 0;
}