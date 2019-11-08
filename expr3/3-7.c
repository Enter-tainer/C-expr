#include <stdio.h>
#include <string.h>
char is_prime[1000001];

int main () {
  int m;
  scanf("%d", &m);
  memset(is_prime, 1, sizeof(is_prime));
  for (int i = 2; i * i <= m; ++i) {
    for (int j = i * 2; j <= m; j += i) {
      is_prime[j] = 0;
    }
  }
  for (int i = 2; i <= m - 2; ++i) {
    if (is_prime[i] && is_prime[i + 2]) {
      printf("(%d, %d)\n", i, i + 2);
      ++i;
    }
  }
}
