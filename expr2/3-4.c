// calculate the number of turn point

#include <stdio.h>

int getint() {
  int tmp;
  scanf("%d", &tmp);
  return tmp;
}

int is_turn_point(int a, int b, int c) {
  return (b > a && b > c) || (b < a && b < c);
}

int main () {
  int n = getint();
  int a, b, c, ans = 0;
  if (n == 1 || n == 2) {
    printf("%d\n", 0);
  } else {
    a = getint(), b = getint(), c = getint();
    ans += is_turn_point(a, b, c);
    for (int i = n - 3; i > 0; --i) {
      a = b, b = c, c = getint();
      ans += is_turn_point(a, b, c);
    }
  }
  printf("%d\n", ans);

}