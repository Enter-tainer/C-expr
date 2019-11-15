#include <stdio.h>

long long sum_fac(int);
// 声明函数

int main(void) {
  int k;
  for (k = 1; k <= 20; k++)
    printf("k=%d\tthe sum is %lld\n", k, sum_fac(k));
  return 0;
}

long long fac(int n) {
  if (n == 1)
    return 1;
  else
    return n * fac(n - 1);
}

long long sum_fac(int n) {
  if (n == 1)
    return 1;
  return sum_fac(n - 1) + fac(n);
}
