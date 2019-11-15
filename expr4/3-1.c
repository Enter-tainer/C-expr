#include <stdio.h>

int main(void) {
  int i, k;
  long long sum = 0, fabonacci(int n);
  printf("input n: ");
  scanf("%d", &k);
  for (i = 1; i <= k; ++i) {
    sum += fabonacci(i);
    printf("i=%d\tthe sum is %lld\n", i, sum);
  }
  return 0;
}

long long fabonacci(int n) {
  static long long fib[100];
  if (n == 1 || n == 2)
    return 1;
  else if (fib[n])
    return fib[n];
  else
    return fib[n] = fabonacci(n - 1) + fabonacci(n - 2);
}
