// switch case:
// if input is uppercase, ouput is lowercase

#include <stdio.h>

int main () {
  char c = getchar();
  if (c >= 'A' && c <= 'Z')
    putchar(c - 'A' + 'a');
  else
    putchar(c);
  return 0;
}