#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
int a[25][25];

int i1, i2, jack1, j2, ans;
int dir[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } }; //上，右，下，左
struct node {
    int x, y;
};
node search(int i, int j, int m, int ci) //顺着m方向找到第一个block
{
    node n;
    while (!a[i][j] && (i != i2 || j != j2)) {
        i += dir[m][0];
        j += dir[m][1];
    }
    if (a[i][j] == 2) {
        n.x = 0;
        n.y = 0;
    } else {
        if (i == i2 && j == j2) {
            ans = min(ans, ci);
            n.x = n.y = 0;
        } else {
            n.x = i;
            n.y = j;
        }
    }
    return n;
}
void dfs(int, int, int); //深搜，记录位置，次数
int main()
{
    int row, column, i, j;
    int c;
    while (~scanf("%d %d", &column, &row) && row && column) {
        ans = 11;
        for (i = 0; i <= row + 1; i++) //读入和初始化
        {
            for (j = 0; j <= column + 1; j++) {
                if (j == 0 || j == column + 1 || i == 0 || i == row + 1)
                    a[i][j] = 2;
                else {
                    cin >> c;
                    if (c == 1 || c == 0)
                        a[i][j] = c;
                    else {
                        if (c == 2) {
                            i1 = i;
                            jack1 = j;
                            a[i][j] = 0;
                        } else {
                            i2 = i;
                            j2 = j;
                            a[i][j] = 0;
                        }
                    }
                }
            }
        }
        dfs(i1, jack1, 1);
        if (ans == 11)
            cout << "-1" << endl;
        else
            cout << ans << endl;
    }
    return 0;
}
void dfs(int i, int j, int cishu) //深搜，记录位置，次数
{
    int k;
    node m;
    if (cishu > ans || cishu > 10)
        return; //比现在的answer都大，还要它何用
    for (k = 0; k < 4; k++) {
        i += dir[k][0];
        j += dir[k][1];
        if (!a[i][j]) {
            //cout<<i<<' '<<j<<' '<<k<<' '<<cishu<<endl;
            m = search(i, j, k, cishu); //m为此方向上的第一个block
            //cout<<i<<' '<<j<<' '<<m.x<<' '<<m.y<<' '<<k<<' '<<cishu<<endl;
            if (m.x) //出界，则直接跳过
            {
                a[m.x][m.y] = 0; //先把block消除
                m.x -= dir[k][0];
                m.y -= dir[k][1];
                //cout<<cishu<<endl;
                dfs(m.x, m.y, cishu + 1);
                a[m.x + dir[k][0]][m.y + dir[k][1]] = 1;
            }
        }
        i -= dir[k][0];
        j -= dir[k][1];
    }
}