#include <stdio.h>
#include <assert.h>

int main () {
  unsigned short x, m, n;
  scanf("%hx%hu%hu", &x, &m, &n);
  assert(0 <= m && m <= 15);
  assert(1 <= n && n <= 16 - m);
  unsigned short mask = ((~0) ^ ((1 << (m)) - 1)) & ~(((~0) >> (m + n)) << (m + n));
  unsigned short ans = (mask & x) << (16 - m - n);
  printf("%x", ans);
}
