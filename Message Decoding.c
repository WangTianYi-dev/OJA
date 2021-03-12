#include <stdio.h>
#include <stdlib.h>
char code[8][1 << 8];

char ReadChar() {
  char ch;
  if (ch == EOF) {
      exit(0);
  }
  for (;;) {
    ch = getchar();
    if (ch != '\n' && ch != ' ') {
      break;
    }
  }
  return ch;
}

int ReadInt(int len) {
  int rv = 0;
  while (len--) {
    // printf("rv = %d\n", rv);
    rv = (rv << 1) + ReadChar() - '0';
  }
  return rv;
}

int ReadCode() {
  code[1][0] = ReadChar();
  for (int len = 2; len <= 7; len++) {
    for (int i = 0; i < (1 << len) - 1; i++) {
      char ch = getchar();
      if (ch == '\n' || ch == '\r') {
        return 1;
      }
      if (ch == EOF) {
        return 0;
      }
      code[len][i] = ch;
    };
  }
  return 1;
}

void PrintCode() {
  for (int len = 1; len <= 7; len++) {
    for (int i = 0; i < (1 << len) - 1; i++) {
      if (code[len][i] == 0) {
        return;
      }
      printf("code[%d][%d] = %c\n", len, i, code[len][i]);
    }
  }
}
int main() {
  while (ReadCode()) {
    //PrintCode();
    for (;;) {
      int len = ReadInt(3);
      if (len == 0) {
        break;
      }
      //printf("len = %d\n", len);
      for (;;) {
        int i = ReadInt(len);
        //printf("v = %d\n", i);
        int k = (1 << len) - 1;
        if (i == k) {
          break;
        }
        char decoded = code[len][i];
        putchar(decoded);
      }
    }
    putchar('\n');
  }
}