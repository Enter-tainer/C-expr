#include <stdio.h>
#include <string.h>

int mmax(int a, int b) { return a > b ? a : b; }

void mswap(int* a, int* b) {
  int t = *a;
  *a    = *b;
  *b    = t;
}

void rotate(int d, int (*p)[d], int n, int m) {
  int tmp[d][d];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; ++j) {
      tmp[m - j - 1][i] = p[i][j];
    }
  }
  memcpy(p, tmp, sizeof(tmp));
}

int main() {
  freopen("matrix.in", "r", stdin);
  freopen("matrix.out", "w", stdout);
  int n, m;
  scanf("%d%d", &n, &m);
  int d = mmax(m, n);
  int map[d][d];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      scanf("%d", &map[i][j]);
  rotate(d, map, n, m);
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j)
      printf("%d ", map[i][j]);
    puts("");
  }
}
