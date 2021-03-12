#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int eliminate(char s[])
{
    
    int rv = 0;
    int i = 0, j = 0;
    while (s[i] != 0) {
        while (s[i] == s[j]) {
            i++;
        }
        if (3 <= i - j) {
            int k;
            for (k = j; s[k + i - j] != 0; k++) {
                s[k] = s[k + i - j];
            }
            s[k] = s[k + i - j];
            i = j;
            rv = 1;
        } else {
            j = i;
        }
    }
    return rv;
}

char game[(int)10e4], temp[(int)10e4];

int main()
{
    gets(game);
    int n;
    scanf("%d", &n);
    int Index;
    char letter;
    if (n == 0) {
        while (eliminate(game))
            ;
        strlen(game) != 0 ? puts(game) : puts("-");
        return 0;
    }
    while (n--) {
        scanf("%d %c", &Index, &letter);
        if (strlen(game) < Index) {
            Index = strlen(game);
        } else if (Index < 0) {
            Index = 0;
        }

        // printf("index: %d, letter: %c\n", index, letter);
        // strncpy(temp, game, index);
        // printf("len of game: %d, len of temp: %d\n", strlen(game), strlen(temp));
        for (int i = 0; i < Index; i++) {
            temp[i] = game[i];
            // printf("t: %d\n", temp[i]);
        }
        // printf("Temp1: %s\n", temp);
        temp[Index] = letter;
        temp[Index + 1] = '\0';
        // printf("Temp2: %s\n", temp);
        strcat(temp, game + Index);
        // printf("Temp3: %s\n", temp);
        strcpy(game, temp);
        // printf("Game1: %s\n", game);
        // for (int i = index; i <= strlen(game); i++) {
        //     temp[i + 1] = game[i];
        // }
        // for (int i = 0; i <= strlen(temp); i++) {
        //     game[i] = temp[i];
        // }
        while (eliminate(game))
            ;
        strlen(game) != 0 ? puts(game) : puts("-");
        // for (int i = 0; i < strlen(game); i++) {
        //     printf("%d: %c\n", i, game[i]);
        // }
    }
    return 0;
}
