// this program is rewritten with while loop
#include <stdio.h>
int main() {
  int i, x, k, flag = 0;
  printf("This program will output whether the input is a prime number or not");
  while (scanf("%d", &x) != EOF) {
    i = 2, k = x >> 1;
    do {
      if (i <= k) {
        if (x % i == 0) {
          flag = 1;
          break;
        }
        i++;
      } else {
        break;
      }
    } while (i <= k);
    if (flag == 1)
      printf("%d is not prime\n", x);
    else
      printf("%d is prime\n", x);
    flag = 0;
  }
}
