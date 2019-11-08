#include <stdio.h>

int C[11][11];

int num_of_space(int k) {
  int line_length = 4 * (k + 1);
  return 2 * (10 - k);
}

int main() {
  for (int i = 0; i <= 9; ++i) {
    C[i][0] = C[i][i] = 1;
  }
  for (int i = 2; i <= 9; ++i) {
    for (int j = 0; j <= i; ++j) {
      C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
  }
  for (int i = 0; i <= 9; ++i) {
    int spc = num_of_space(i);
    for (int j = 1; j < spc; ++j)
      putchar(' ');
    for (int j = 0; j <= i; ++j) {
      printf("%4d", C[i][j]);
    }
    putchar('\n');
  }
}
