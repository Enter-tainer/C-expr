#include <stdio.h>
#include <math.h>

#define S(a, b, c) (((a) + (b) + (c)) / 2)
#define AERA(a, b, c) (sqrt(S(a, b, c) * (S(a, b, c) - a) * (S(a, b, c) - b) * (S(a, b, c) - c)))

int main () {
  double a, b, c;
  scanf("%lf %lf %lf", &a, &b, &c);
  printf("%lf\n", AERA(a, b, c));
}
