#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(int a[], int n) {
  if (n == 1 || n == 0)
    return;
  int l[n], g[n];
  int piv_idx = rand() % n, piv = a[piv_idx];
  int i, j, k;
  for (i = 0, j = 0, k = 0; i < n; ++i)
    if (i != piv_idx)
      if (a[i] <= piv)
        l[j++] = a[i];
      else if (a[i] > piv)
        g[k++] = a[i];
  sort(l, j);
  sort(g, k);
  for (i = 0; i < n; ++i)
    if (i < j)
      a[i] = l[i];
    else if (i == j)
      a[i] = piv;
    else
      a[i] = g[i - j - 1];
}

void reverse(int a[], int n) {
  if (n == 0 || n == 1)
    return;
  a[0] ^= a[n - 1] ^= a[0] ^= a[n - 1];
  reverse(a + 1, n - 2);
}

int main(int argc, char** argv) {
  if (argc < 2) {
    puts("too few arguments");
    exit(1);
  }
  int n = atoi(argv[1]), rev = 0;
  if (argc == 3 && strcmp(argv[2], "-d") >= 0) {
    rev = 1;
  }
  int nums[n];
  for (int i = 0; i < n; ++i)
    scanf("%d", i + nums);
  sort(nums, n);
  if (rev) {
    reverse(nums, n);
  }
  for (int i = 0; i < n; ++i)
    printf("%d ", nums[i]);
  puts("");
  return 0;
}
