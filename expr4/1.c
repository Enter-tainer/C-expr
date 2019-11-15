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
  long long s   = 0;
  long long fac = 1;
  // 初始化，修改为 long long，防止溢出
  int i;
  for (int j = 1; j <= n; ++j) {
    for (i = 1; i <= j; i++)
      fac *= i;
    s += fac;
    fac = 1;
  }
  return s;
}
