#include <math.h>
#include <stdio.h>
int main () {
  long x, y;
  for (int i = 1; i < 100000; i++) { 
    // ^^^
    // i 没有声明
    x = sqrt(i + 100);
    y = sqrt(i + 268);
    if (x * x == i + 100 && y * y == i + 268) // 混淆了 == 与 =，括号加少了
          printf("\n%d", i);
  }
  return 0;
}
