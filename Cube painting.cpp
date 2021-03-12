#include <stdio.h>
#include <string.h>
// use on C-style index
#define f(x) (x - 1)

void rotatez(char* cube)
// rotate around 1-6 axis
{
    char t = cube[f(2)];
    cube[f(2)] = cube[f(4)];
    cube[f(4)] = cube[f(5)];
    cube[f(5)] = cube[f(3)];
    cube[f(3)] = t;
}

void rotatex(char* cube)
// rotate around 3-4 axis
{
    char t = cube[f(2)];
    cube[f(2)] = cube[f(1)];
    cube[f(1)] = cube[f(5)];
    cube[f(5)] = cube[f(6)];
    cube[f(6)] = t;
}

void rotatey(char* cube)
// rotate around 2-5 axis
{
    char t = cube[f(1)];
    cube[f(1)] = cube[f(4)];
    cube[f(4)] = cube[f(6)];
    cube[f(6)] = cube[f(3)];
    cube[f(3)] = t;
}

int main()
{
    int r4[4] {};
    char tmp[20], cubeA[10], cubeB[10];
    while (scanf("%s", tmp) != EOF) {
        strncpy(cubeA, tmp, 6);
        strncpy(cubeB, tmp + 6, 6);
        cubeA[6] = cubeB[6] = 0;
        bool match = false;
        for (int i : r4) {
            rotatex(cubeA);
            if (strcmp(cubeA, cubeB) == 0) {
                match = true;
                goto output;
            }
            for (int i : r4) {
                rotatey(cubeA);
                if (strcmp(cubeA, cubeB) == 0) {
                    match = true;
                    goto output;
                }
                for (int i : r4) {
                    rotatez(cubeA);
                    if (strcmp(cubeA, cubeB) == 0) {
                        match = true;
                        goto output;
                    }
                }
            }
        }
    output:
        if (match) {
            puts("TRUE");
        } else {
            puts("FALSE");
        }
    }
    return 0;
}
