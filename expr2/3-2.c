// sum a number from every digit and calculate how many digits in it

#include <stdio.h>

int main () {
  int num, len = 0, sum = 0;
  scanf("%d", &num);
  for (int tmp = num; tmp; tmp /= 10, len++) {
    sum += tmp % 10;
  }
  printf("%d is a %d digit number, sum of all digits is %d\n", num, len, sum);
  return 0;
}