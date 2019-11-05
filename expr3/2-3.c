#include <stdio.h>

int is_composite(int n) {
  int i, k, flag = 0;
  i = 2, k = n >> 1;
  do {
    if (i <= k) {
      if (n % i == 0) {
        flag = 1;
        break;
      }
      i++;
    } else {
      break;
    }
  } while (i <= k);
  return flag;
}

int is_pure_composite(int n) {
  if (n < 10)
    return is_composite(n);
  return is_composite(n) && is_pure_composite(n / 10);
}

int main () {
  for (int i = 100; i <= 999; ++i) {
    if (is_pure_composite(i))
      printf("%d\n", i);
  }
}
