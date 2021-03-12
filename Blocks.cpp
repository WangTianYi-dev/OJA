#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int maxn = 30;
int n;
vector<int> PILES[maxn];

// block = PILES[a][b]
void FindBlock(int block, int& p, int& h)
{
    for (p = 0; p < n; p++)
        for (h = 0; h < PILES[p].size(); h++)
            if (PILES[p][h] == block)
                return;
}

void ClearAbove(int p, int h)
{
    for (int i = h + 1; i < PILES[p].size(); i++) {
        int b = PILES[p][i];
        PILES[b].push_back(b);
    }
    PILES[p].resize(h + 1);
}

// pile h and above
void PileOnto(int p, int h, int p2)
{
    for (int i = h; i < PILES[p].size(); i++)
        PILES[p2].push_back(PILES[p][i]);
    PILES[p].resize(h);
}


void Print() 
{
    for (int i = 0; i < n; i++) {
        printf("%d:", i);
        for (int j = 0; j < PILES[i].size(); j++) {
            printf(" %d", PILES[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int a, b;
    cin >> n;
    for (int i = 0; i < n; i++)
        PILES[i].push_back(i);
    string s1, s2;
    while (cin >> s1 >> a >> s2 >> b) {
        int pa, pb, ha, hb;
        FindBlock(a, pa, ha);
        FindBlock(b, pb, hb);
        if (pa == pb) continue;
        if (s2 == "onto") ClearAbove(pb, hb);
        if (s1 == "move") ClearAbove(pa, ha);
        PileOnto(pa, ha, pb);
    }
    Print();
    return 0;
}