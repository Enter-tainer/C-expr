// 本程序输出最大的波动
#include <stdio.h>
#include <string.h>
#include <math.h>
int main () {
  int n;
  scanf("%d", &n);
  double price[n + 1], diff[n + 1];
  memset(price, 0, sizeof(double) * (n + 1));
  memset(diff, 0, sizeof(double) * (n + 1));
  // set price & price_diff to zeros
  for (int i = 1; i <= n; ++i) {
    scanf("%lf", price + i);
  }
  for (int i = 1; i <= n; ++i) {
    diff[i] = fabs(price[i] - price[i - 1]);
    // diff stores the difference of price[i] and price[i - 1]
  }
  diff[1] = 0;
  double res = 0;
  for (int i = 1; i <= n; ++i) {
    if (res < diff[i])
      res = diff[i];
    // let res be the biggest element in diff
  }
  printf("%lf\n", res);
}
