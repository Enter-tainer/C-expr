#include <stdio.h>
#include <math.h>
int p;

void fight(double a, double b, int cnt) {
  if (cnt == 4) {
    p += (fabs(a - b) < 1000);
  } else {
    fight(a * 0.75, b + a * 0.25, cnt + 1);
    fight(a + b * 0.25, b * 0.75, cnt + 1);
  }
}

int main () {
  fight(1000, 2000, 0);
  printf("%lf", 1.0 * p / (2 * 2 * 2 * 2));
}
