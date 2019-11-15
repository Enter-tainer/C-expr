#include <stdio.h>
#include <ctype.h>
#define CHANGE
void flip(char* c) {
  if (isalpha(*c))
    if ('a' <= *c && *c <= 'z')
      *c += 'A' - 'a';
    else
      *c -= 'A' - 'a';
}

int main() {
  char buf[1000];
  gets(buf);
#ifdef CHANGE
  for (char* ptr = buf; *ptr; ++ptr)
    flip(ptr);
#endif
  printf("%s\n", buf);
}
