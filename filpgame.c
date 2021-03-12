#include <stdbool.h>
#include <stdio.h>
int board[16];
void printboard(int i)
{
    printf("%d\n", i);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i * 4 + j] == 0)
                putchar('w');
            if (board[i * 4 + j] == 1)
                putchar('b');
        }
        putchar('\n');
    }
}

// void flip(int target)
// { //翻转target及其上下左右棋子
//     int r = target / 4; //用于辨别边界棋子
//     int c = target % 4; //同上
//     board[target] = !board[target];
//     if (r > 0)
//         board[target - 4] = !board[target - 4];
//     if (r < 3)
//         board[target + 4] = !board[target + 4];
//     if (c > 0)
//         board[target - 1] = !board[target - 1];
//     if (c < 3)
//         board[target + 1] = !board[target + 1];
// }
void flip(int t)
{
    int r = t / 4;
    int c = t % 4;
    board[t] = !board[t];
    if (r > 0) {
        board[t - 4] = !board[t - 4];
    }
    if (r < 3) {
        board[t + 4] = !board[t + 4];
    }
    if (c > 0) {
        board[t - 1] = !board[t - 1];
    }
    if (c < 3) {
        board[t + 1] = !board[t + 1];
    }
}

// bool check()
// {
//     int c = board[0];
//     for (int i = 1; i < 16; i++) {
//         if (board[i] != c) {
//             return false;
//         }
//     }
//     return true;
// }

int best = 17;
int time = 0;

bool check()
{ //检查是否全部同色
    for (int i = 0; i < 16; ++i) {
        if (board[0] != board[i])
            return false;
    }
    return true;
}

void backtrack(int i)
{
    // if (check()) {
    //     printboard(i);
    // }
    if (i >= 16) {
        if (check() && time < best) {
            best = time;
        }
    } else {
        backtrack(i + 1);
        time++;
        if (time < best) { //剪枝
            flip(i);
            //printboard(i);
            // putchar(time);
            // printf("%d\n", time);
            backtrack(i + 1);
            flip(i);
        }
        time--;
    }
}

int main()
{
    char c;
    for (int i = 0; i < 16; i++) {
        c = getchar();
        if (c == '\n') {
            i--;
            continue;
        }
        board[i] = (119 - c) / 21;
    }
    //printboard(0);
    backtrack(0);
    if (best == 17) {
        puts("Impossible");
    } else {
        printf("%d", best);
    }
    return 0;
}