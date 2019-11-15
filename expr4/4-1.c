#include <stdio.h>
#include <string.h>
char is_prime[10000];
void caixiang(int n) {
  for (int i = 2; i < sizeof(is_prime); ++i) {
    if (is_prime[i] && is_prime[n - i]) {
      printf("%d=%d+%d\n", n, i, n - i);
      return;
    }
  }
}

int main() {
  memset(is_prime, 1, sizeof(is_prime));
  for (int i = 2; i * i < sizeof(is_prime); ++i) {
    for (int j = i * 2; j < sizeof(is_prime); j += i) {
      is_prime[j] = 0;
    }
  }
  while (1) {
    int n;
    printf("input n: ");
    scanf("%d", &n);
    if (n % 2 == 0 && n > 4)
      caixiang(n);
  }
}
