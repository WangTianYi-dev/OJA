/**
 * POJ1753,Accepted
 * 棋盘上每一个棋子都有翻转和不翻转两种选择
 * 总共16个棋子，就是2^16种可能
 * 问题的解是这所有可能的一个子集
 * 在此利用回溯法遍历子集树
 * 剪枝函数设定为：当前已经翻转的次数如果大于已经得到的最优次数则不再往下
 * 由于问题是求解最少的翻转次数，为了提高效率，回溯函数中优先搜索不翻转的情况
 * 这样的话搜索过程中翻转的次数就是递增的，一旦得到结果，剩余的翻转次数更多的情况会被剪枝
 * 每得到一个子集，检查棋盘状态和翻转次数是否更少（递归出口）
 */
#include <stdio.h>

int Checkerboard[16]; //4x4棋盘，0代表白，1代表黑
int Count = 20; //记录最优翻转次数，由于最多翻转16次，初始化大于16的数
int times; //自动初始化0，记录当前已经翻转的次数，用于剪枝函数，若times>Count则没必要往下
bool Check()
{ //检查是否全部同色
    for (int i = 0; i < 16; ++i) {
        if (Checkerboard[0] != Checkerboard[i])
            return false;
    }
    return true;
}

void printboard(int i)
{
    printf("%d\n", i);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (Checkerboard[i * 4 + j] == 0)
                putchar('w');
            if (Checkerboard[i * 4 + j] == 1)
                putchar('b');
        }
        putchar('\n');
    }
}

void Flip(int target)
{ //翻转target及其上下左右棋子
    int r = target / 4; //用于辨别边界棋子
    int c = target % 4; //同上
    Checkerboard[target] = !Checkerboard[target];
    if (r > 0)
        Checkerboard[target - 4] = !Checkerboard[target - 4];
    if (r < 3)
        Checkerboard[target + 4] = !Checkerboard[target + 4];
    if (c > 0)
        Checkerboard[target - 1] = !Checkerboard[target - 1];
    if (c < 3)
        Checkerboard[target + 1] = !Checkerboard[target + 1];
}

void Backtrack(int i)
{
    if (i >= 16) { //得到一个子集
        if (Check() && times < Count)
            Count = times;
    } else {
        Backtrack(i + 1); //优先不翻转，提高效率
        times++; //翻转后的总翻转次数
        if (times < Count) {
            Flip(i); //翻转
            // printboard(i);
            Backtrack(i + 1);
            Flip(i); //回溯，恢复上一次状态
        }
        times--;
    }
}

int main()
{
    char ch;
    for (int i = 0; i < 16; ++i) {
        ch = getchar();
        if (ch == '\n') {
            --i;
            continue;
        }
        Checkerboard[i] = (119 - ch) / 21; //哈希函数，直接把w映射到0，b映射到1
    }
    Backtrack(0);
    if (Count == 20)
        printf("Impossible\n");
    else
        printf("%d\n", Count);
    return 0;
}
