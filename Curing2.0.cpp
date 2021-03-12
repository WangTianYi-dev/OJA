#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
#define V 0
#define B 1
#define S 2
#define G 3
int w, h;
struct Node {
    char len;
    char board[22][22];
    char selfx, selfy;
    Node next(char sx, char sy, char bx, char by)
    {
        Node n;
        n.len = len + 1;
        memcpy(n.board, board, sizeof(n.board));
        n.board[bx][by] = 0;
        n.selfx = sx, n.selfy = sy;
        return n;
    }
    void print()
    {
        printf("selfx: %hhd, selfy: %hhd\n", selfx, selfy);
        printf("len: %hhd\n", len);
        // for (int i = 0; i <= h + 1; i++) {
        //     for (int j = 0; j <= w + 1; j++) {
        //         if (i == selfx && j == selfy) {
        //             printf(" x ");
        //         } else {
        //             printf(" %hhd ", board[i][j]);
        //         }
        //     }
        //     printf("\n");
        // }
    }
};

char board[22][22];

int bfs(int sx, int sy)
{
    Node n;
    n.len = 0;
    n.selfx = sx;
    n.selfy = sy;
    memcpy(n.board, board, sizeof(board));
    queue<Node> q;
    q.push(n);
    while (!q.empty()) {
        Node t = q.front();
        q.pop();
        // puts("\nCurNode:");
        // t.print();
        char(*curBoard)[22] = t.board;
        char curLen = t.len;

        if (curLen >= 10) {
            return -1;
        }
        char curx = t.selfx, cury = t.selfy;
        // char nextx, nexty;
        bool able[4] = { false, false, false, false };
        if (curBoard[curx][cury + 1] == 0 || curBoard[curx][cury + 1] == 2
            || curBoard[curx][cury + 1] == 3) {
            able[0] = true;
        }
        if (curBoard[curx + 1][cury] == 0 || curBoard[curx + 1][cury] == 2
            || curBoard[curx + 1][cury] == 3) {
            able[1] = true;
        }
        if (curBoard[curx][cury - 1] == 0 || curBoard[curx][cury - 1] == 2
            || curBoard[curx][cury - 1] == 3) {
            able[2] = true;
        }
        if (curBoard[curx - 1][cury] == 0 || curBoard[curx - 1][cury] == 2
            || curBoard[curx - 1][cury] == 3) {
            able[3] = true;
        }
        // for (int i = 0; i < 4; i++) {
        //     cout << able[i] << ' ';
        // }
        // cout << endl;
        for (int i = 0; i < 4; i++) {
            curx = t.selfx, cury = t.selfy;
            if (able[i]) {
                switch (i) {
                case 0 /* constant-expression */:
                    /* code */
                    // right
                    while (curBoard[curx][cury] == 0
                        || curBoard[curx][cury] == 2) {
                        cury++;
                    }
                    if (curBoard[curx][cury] == 1) {
                        q.push(t.next(curx, cury - 1, curx, cury));
                        // puts("Pushed:");
                        // q.front().print();
                    } else if (curBoard[curx][cury] == 3) {
                        return curLen + 1;
                    }
                    break;
                case 1:
                    // down
                    while (curBoard[curx][cury] == 0 || curBoard[curx][cury] == 2) {
                        curx++;
                    }
                    if (curBoard[curx][cury] == 1) {
                        q.push(t.next(curx - 1, cury, curx, cury));
                        // puts("Pushed:");
                        // q.front().print();
                    } else if (curBoard[curx][cury] == 3) {
                        return curLen + 1;
                    }
                    break;
                case 2:
                    //left
                    while (curBoard[curx][cury] == 0 || curBoard[curx][cury] == 2) {
                        cury--;
                    }
                    if (curBoard[curx][cury] == 1) {
                        q.push(t.next(curx, cury + 1, curx, cury));
                        // puts("Pushed:");
                        // q.front().print();
                    } else if (curBoard[curx][cury] == 3) {
                        return curLen + 1;
                    }
                    break;
                case 3:
                    while (curBoard[curx][cury] == 0
                        || curBoard[curx][cury] == 2) {
                        curx--;
                    }
                    if (curBoard[curx][cury] == 1) {
                        q.push(t.next(curx + 1, cury, curx, cury));
                        // puts("Pushed:");
                        // q.front().print();
                    } else if (curBoard[curx][cury] == 3) {
                        return curLen + 1;
                    }
                    break;
                default:
                    break;
                }
            }
        }
    }
    return -1;
}

int main()
{
    // int w, h;
    int sx, sy;
    while (scanf(" %d %d", &w, &h) != EOF && w && h) {
        memset(board, -1, sizeof(board));
        // printf("w=%d h=%d\n", w, h);
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                scanf(" %hhd", &board[i][j]);
                if (board[i][j] == 2) {
                    sx = i, sy = j;
                }
            }
        }
        // printf("%d %d", sx, sy);
        // printf("\nDEBUG:\n");
        // for (int i = 0; i <= h+1; i++) {
        //     for (int j = 0; j <= w+1; j++) {
        //         printf(" %hhd ", board[i][j]);
        //     }
        //     printf("\n");
        // }
        // printf("\nans\n");
        printf("%d\n", bfs(sx, sy));
    }
    return 0;
}
