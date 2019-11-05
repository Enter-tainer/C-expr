#include <stdio.h>

int main()
{
  int m, n, k, p, i, d;
  printf("Input m, n\n");
  scanf("%d%d", &m, &n);
  if (m < n)
  {
    m ^= n, n ^= m, m ^= n;
    // ^^^^^^^^^^^^^^^^^^^^
    // 第一个语句执行完之后，m 变成　m ^ n，第二个执行后，n 变成　n ^ m ^ n = m，第三个执行后，　m 变成　m ^ n ^ m = n，实现交换变量
  }
  k = 0;
  while (!(m & 1) && !(n & 1))
  {
    //   ^^^^^^^^    ^^^^^^^^
    // 与 1 等价于模２
    m >>= 1;
    n >>= 1;
    //^^^^^ 
    // 在二进制下右移一位等价于除以２
    k++;
  }
  p = 1;
  p <<= k;
  // ^^^^
  // 在二进制下左移一位等价于乘以２
  while ((d = m - n) != n)
  {
    if (d > n)
      m = d;
    else
      m = n, n = d;
      //   ^^
      // 使用逗号运算符可以合并多个语句
  }
  d *= p;
  printf("greatest common divisor: %d", d);
  return 0;
}