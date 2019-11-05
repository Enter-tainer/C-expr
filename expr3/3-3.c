#include <stdio.h>

char peek() {
  char c = getchar();
  ungetc(c, stdin);
  return c;
}

int main () {
  char ch;
  while((ch = getchar()) != EOF) {
    if (ch == ' ') {
      while (peek() == ' ')
        getchar();
    }
    putchar(ch);
  }
}
