#include <iostream>
#include <string>

std::string s;

namespace Trie {
int tot, nxt[100000][27];
// nxt[p][c]即为第p个节点相连的字符c的节点
void insert(const std::string& s)
{
    int p = 0;
    // 从ROOT开始遍历每个节点
    for (int c : s) {
        c -= 'A';
        if (!nxt[p][c])
            nxt[p][c] = ++tot;
        // p指向下一个节点
        p = nxt[p][c];
    }
}
} // Trie

int main()
{
    std::ios::sync_with_stdio(false);
    // desync with stdio
    std::cin.tie(nullptr);
    // detie with cout
    while (std::cin >> s)
        Trie::insert(s);
    std::cout << Trie::tot + 1;
    return 0;
}