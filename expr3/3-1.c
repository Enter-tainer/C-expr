#include <stdio.h>

double calc_tax(double x) {
  // calc tax with if
  if (x < 1000) {
    return 0;
  } else if (x < 2000) {
    return x * 0.05;
  } else if (x < 3000) {
    return x * 0.1;
  } else if (x < 4000) {
    return x * 0.15;
  } else if (x < 5000) {
    return x * 0.2;
  } else {
    return x * 0.25;
  }
}

double calc_tax_switch(double x) {
  // calc tax with switch
  int t = x / 1000;
  switch (t) {
    case 0:
      return 0;
    case 1:
      return x * 0.05;
    case 2:
      return x * 0.1;
    case 3:
      return x * 0.15;
    case 4:
      return x * 0.2;
    default:
      return x * 0.25;
  }
}

int main () {
  double x;
  printf("输入你的工资：");
  scanf("%lf", &x);
  printf("你需要缴税：%lf（if） %lf（switch）\n", calc_tax(x), calc_tax_switch(x));
}
