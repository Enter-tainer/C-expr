#include <stdio.h>

int main () {
  unsigned long x;
  while(scanf("%lu", &x) != EOF) {
    char *ptr = &x; // read x from byte to byte
    // since most machine use little edian, the visit is from low to high
    printf("%u.%u.%u.%u", 0xff & ptr[3],
                          0xff & ptr[2],
                          ptr[1],
                          ptr[0]);
  }
}
