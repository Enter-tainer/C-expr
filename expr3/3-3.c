#include <stdio.h>

char peek() {
  // this function first get a char from stdin, then put it back
  // so as to peek the next char in stdin
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
      // skip all spaces
    }
    putchar(ch);
  }
}
