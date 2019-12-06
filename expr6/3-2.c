#include <stdio.h>
#include <stdlib.h>

int remove_same(int a[], int n) {
  int *first = a, *last = a + n;
  if (first == last)
    return n;

  int * result = first;
  while (++first != last) {
    if (!(*result == *first) && ++result != first) {
      *result = *first;
    }
  }
  return 1 + result - a;
}

int main () {
  int num[100], n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", num + i);
  int newl = remove_same(num, n);
  for (int i = 0; i < newl; ++i)
    printf("%d ", *(num + i));
  puts("");
}
