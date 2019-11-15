#include <stdio.h>

long long sum_fac(int);
// 声明函数

int main(void) {
  int k;
  for (k = 1; k <= 20; k++)
    printf("k=%d\tthe sum is %lld\n", k, sum_fac(k));
  return 0;
}

long long sum_fac(int n) {
  static long long s = 0, fac = 1;
  fac *= n;
  s += fac;
  return s;
}
