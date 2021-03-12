#include <iostream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
using namespace std;
#define PASS 0
#define OUT -1
#define EMPTY 0
struct Game {
    char grid[20][20];
    int curx, cury;
    int path[20][20];
    int numRow, numCol, numColStrt;
    int numMove;
    void init(int row, int col, int strt)
    {
        numRow = row;
        numCol = col;
        numColStrt = strt;
        curx = 1;
        cury = strt;
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {
                grid[i][j] = EMPTY;
                path[i][j] = 0;
            }
        }
        path[curx][cury] = 1;
        numMove = 1;
    }
    int run()
    {
        char curMove = grid[curx][cury];
        int nextx = curx, nexty = cury;
        switch (curMove) {
        case 'N' /* constant-expression */:
            /* code */
            nextx -= 1;
            break;
        case 'E':
            nexty += 1;
            break;
        case 'S':
            nextx += 1;
            break;
        case 'W':
            nexty -= 1;
            break;
        default:
            break;
        }
        if (grid[nextx][nexty] == EMPTY) {
            return OUT;
        } else {
            if (path[nextx][nexty]) {
                return path[nextx][nexty];
            } else {
                numMove++;
                path[nextx][nexty] = numMove;
                curx = nextx;
                cury = nexty;
                return PASS;
            }
        }
    }
    void printgrid()
    {
        for (int i = 1; i <= numRow; i++) {
            for (int j = 1; j <= numCol; j++) {
                putchar(grid[i][j]);
                putchar(' ');
            }
            putchar('\n');
        }
    }
} game;

int main()
{
    int row, col, strt;
    while (scanf(" %d %d %d", &row, &col, &strt) != EOF) {
        if (!row) {
            break;
        }
        game.init(row, col, strt);
        char c;
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                scanf(" %c", &c);
                // printf("c:%d\n", c);
                game.grid[i][j] = c;
            }
        }
        // game.printgrid();
        int state;
        while ((state = game.run()) == PASS)
            ;
        if (state == OUT) {
            printf("%d step(s) to exit\n", game.numMove);
        } else {
            printf("%d step(s) before a loop of %d step(s)\n", state - 1,
                game.numMove - state + 1);
        }
    }
    return 0;
}