#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdint.h>

#define maxn 
#define X 0
#define Y 1

int n, curDim;

struct Station {
    int loc[2], temp;
} s