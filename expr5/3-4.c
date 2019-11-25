#include <stdio.h>
#include <string.h>
int p[100][100], res[100][100];
int n, m;
void eliminate() {
  memcpy(res, p, sizeof(res));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j + 2 <= m; ++j) {
      if (p[i][j] == p[i][j + 1] && p[i][j + 1] == p[i][j + 2])
        res[i][j] = res[i][j + 1] = res[i][j + 2] = 0;
    }
  }
  for (int j = 1; j <= m; ++j) {
    for (int i = 1; i + 2 <= n; ++i) {
      if (p[i][j] == p[i + 1][j] && p[i + 1][j] == p[i + 2][j])
        res[i][j] = res[i + 1][j] = res[i + 2][j] = 0;
    }
  }
}

int main() {
  puts("pls input n, m and the table");
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      scanf("%d", &p[i][j]);
  puts("");
  eliminate();
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      printf("%d ", res[i][j]);
    }
    puts("");
  }
}
