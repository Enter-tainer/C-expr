#include <stdio.h>

int main () {
  unsigned long x;
  while (scanf("%lu", &x) != EOF) {
    char *ptr = &x; // read x from highest byte to lowest byte
    // since most machines use little edian, the order of bytes are from low to high
    printf("%u.%u.%u.%u", 0xff & ptr[3],
                          0xff & ptr[2],
                          0xff & ptr[1],
                          0xff & ptr[0]);
  }
}
