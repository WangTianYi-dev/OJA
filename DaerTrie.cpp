#include <bits/stdc++.h>

int nodes[100000][27];
int total;
void insert(std::string s)
{
    int p = 0;
    for (auto c : s) {
        c -= 'A';
        if (!nodes[p][c]) {
            nodes[p][c] = ++total;
        }
        p = nodes[p][c];
    }
}

int main()
{
    std::string s;
    while (std::cin >> s) {
        insert(s);
    }
    std::cout << total + 1 << std::endl;
    return 0;
}