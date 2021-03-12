#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
bool Refrigerator[4][4];
int steps;
int best = 20;
int indexBest;
int routine[20];
int recordRoutine[1000][20];
void Switch(int x, int y)
{
    Refrigerator[x][y] = !Refrigerator[x][y];
    for (int i = 0; i < 4; i++) {
        Refrigerator[x][i] = !Refrigerator[x][i];
        Refrigerator[i][y] = !Refrigerator[i][y];
    }
}

void printRef()
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            putchar(Refrigerator[i][j] ? '+' : '-');
        }
        putchar('\n');
    }
}

bool check()
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (Refrigerator[i][j])
                return false;
        }
    }
    return true;
}

void test()
{
    int rou[10][2] = { { 1, 2 }, { 2, 1 }, { 2, 2 }, { 2, 3 }, { 2, 4 }, { 3, 1 },
        { 3, 2 }, { 3, 3 }, { 3, 4 }, { 4, 2 } };
    for (int i = 0; i < 10; i++) {
        Switch(rou[i][0] - 1, rou[i][1] - 1);
        printf("%d\n", i);
        printRef();
    }
}
// 6
// 1 1
// 1 3
// 1 4
// 4 1
// 4 3
// 4 4
int Index = 0;
void solve(int i)
{
    if (i >= 16) {
        if (check() && steps < best) {
            best = steps;
            indexBest = Index++;
            memcpy(recordRoutine[indexBest], routine, sizeof(int) * sizeof(routine));
        }
    } else {
        solve(i + 1);
        steps++;
        if (steps < best) {
            Switch(i / 4, i % 4);
            routine[i] = 1;
            solve(i + 1);
            Switch(i / 4, i % 4);
            routine[i] = 0;
        }
        steps--;
    }
}

int main()
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            char ch = getchar();
            while (ch != '+' && ch != '-') {
                ch = getchar();
            }
            Refrigerator[i][j] = (ch == '+') ? true : false;
        }
    }
    solve(0);
    printf("%d\n", best);
    for (int i = 0; i < 16; i++) {
        if (recordRoutine[indexBest][i]) {
            int x = i / 4;
            int y = i % 4;
            printf("%d %d\n", x + 1, y + 1);
        }
    }
    // test();
}