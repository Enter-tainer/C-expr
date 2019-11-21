#include <stdio.h>
#include <string.h>
#define M 10
#define N 3

int main() {
  int a[M + 1], out[M + 1];
  memset(out, 0, sizeof(out));
  int *p = a, j = 0;
  for (int i = 0, m = M; i < M; ++i, --m) {
    int k = j + 1;
    for (int q = 1; q <= N; ++k, k > M ? k -= M : 0)
      if (!out[k])
        ++q;
    j = k - 2;
    j += M, j %= M;
    *(p++)     = j + 1;
    out[j + 1] = 1;
    ++j, j %= M;
  }
  for (int i = 0; i < M; ++i)
    printf("%6d", a[i]);
  for (int i = 1; i <= M; ++i)
    if (!out[i])
      printf("%6d\n", i);
}
