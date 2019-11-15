#define R
#include <stdio.h>
#include <assert.h>

int integer_fraction(float x);

int main(void) {
  float r, s;
  int s_integer = 0;
  printf("input a number");
  scanf("%f", &r);
#ifdef R
  s = 3.14159 * r * r;
  printf("area of round if: %f\n", s);
  s_integer = integer_fraction(s);
  assert((s - s_integer) < 0.5);
  printf("the integer fraction of area is %d\n", s_integer);
#endif
  return 0;
}

int integer_fraction(float x) {
  int i = x + 0.5;
  return i;
}
