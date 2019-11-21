#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *getbin(int c) {
  char *str = malloc(33);
  memset(str, 0, 33);
  for (int i = 0; i < 32; ++i) {
    if ((1 << i) & c)
      str[i] = '1';
    else
      str[i] = '0';
  }
  int len = strlen(str);
  for (int i = 0, j = len - 1; i < j; ++i, --j)
    str[i] ^= str[j] ^= str[i] ^= str[j];
  return str;
}

int main () {
  int c;
  scanf("%d", &c);
  printf("%s", getbin(c));
}
