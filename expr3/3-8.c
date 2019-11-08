#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* check(int arr[], int num) {
  int* res = malloc(sizeof(int) * 10);
  memset(res, 0, 10 * sizeof(int));
  for (int i = 0; i < 10; ++i) {
    if (res[arr[i]]) {
      free(arr);
      return NULL;
    } else {
      res[arr[i]] = i;
    }
  }
  int a = res[0] * 10000 + res[1] * 1000 + res[2] * 100 + res[3] * 10 + res[4];
  int b = res[5] * 10000 + res[6] * 1000 + res[7] * 100 + res[8] * 10 + res[9];
  if (a % b == 0 && a / b == num)
    return res;
  else {
    free(res);
    return NULL;
  }
}

void dfs(int k, int num) {
  static int order[11];
  if (k == 10) {
    int* res = check(order, num);
    if (res) {
      printf("%d%d%d%d%d/%d%d%d%d%d = %d\n", res[0], res[1], res[2], res[3],
             res[4], res[5], res[6], res[7], res[8], res[9], num);
      free(res);
    } else {
      return;
    }
  } else {
    for (int i = 0; i < 10; ++i) {
      if (!order[i]) {
        order[i] = k;
        dfs(k + 1, num);
        order[i] = 0;
      }
    }
  }
}

int main() {
  int n;
  scanf("%d", &n);
  dfs(1, n);
}
