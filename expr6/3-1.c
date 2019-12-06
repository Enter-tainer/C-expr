#include <stdio.h>

int main () {
  long x;
  unsigned char* p = (void *)&x;
  scanf("%d", &x);
  for (int i = 0; i < 4; ++i) {
    printf("%02X ", *p);
    ++p;
  }
}
