#include <bits/stdc++.h>
using namespace std;
int g[510][510], tot, f[510][510]; //f数组充当临时数组
    int n, m;
void print() {
    cout << "G:" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << g[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "F:" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << g[i][j] << ' ';
        }
        cout << endl;
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            g[i][j] = ++tot;
            f[i][j] = g[i][j];
        }
    }


    for (int i = 1; i <= m; i++) {
        int a, b, r, opt;
        scanf("%d %d %d %d", &a, &b, &r, &opt); //下面的分析都是针对那一块矩阵而言的
        if (opt == 0) { //第i行第j个 变成倒数第i列第j个 顺时针
            for (int i = a - r; i <= a + r; i++)
                for (int j = b - r; j <= b + r; j++)
                    f[a - b + j][a + b - i] = g[i][j];
            // print();
            // for (int i = a - r; i <= a + r; i++)
            //     for (int j = b - r; j <= b + r; j++)
            //         g[i][j] = f[i][j];
            memcpy(g, f, sizeof(g));
            // print();
        } else { //第i行第j个 变成第i列倒数第j个 逆时针
            for (int i = a - r; i <= a + r; i++)
                for (int j = b - r; j <= b + r; j++)
                    f[a + b - j][b - a + i] = g[i][j];
            // print();
            // for (int i = a - r; i <= a + r; i++)
            //     for (int j = b - r; j <= b + r; j++)
            //         g[i][j] = f[i][j];
            memcpy(g, f, sizeof(g));
            // print();
        }
    }
    for (int i = 1; i <= n; i++) { //输出结果咯
        for (int j = 1; j <= n; j++)
            printf("%d ", g[i][j]);
        printf("\n");
    }
    return 0;
}