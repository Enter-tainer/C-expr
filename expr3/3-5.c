#include <stdio.h>
#include <math.h>

int is_square(int n) { return (int)sqrt(n) * (int)sqrt(n) == n; }

int main () {
  for (int i = 1; i <= 9; ++i) {
    for (int j = 1; j <= 9; ++j) {
      if (i == j)
        continue;
      int code = i * 1000 + i * 100 + j * 10 + j;
      if (is_square(code))
        printf("%d\n", code);
    }
  }
}
