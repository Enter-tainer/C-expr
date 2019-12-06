#include <stdio.h>
#include <string.h>

char ** longest(int n, char (*strs)[20], int *len) {
  char (*p)[20] = 0;
  size_t max_len = 0;
  for (int i = 0; i < n; i++) {
    if (strlen(strs[i]) > max_len)
      p = &strs[i], max_len = strlen(strs[i]);
  }
  *len = max_len;
  return p;
}

int main () {
  char p[][20] = {"123321", "dfsfs", "dttttttttt", "1234567890000", "09303030"};
  int len, n = 5;
  char (*t)[20] = longest(n, p, &len);
  printf("%d: %s\n", len, *t);
}
