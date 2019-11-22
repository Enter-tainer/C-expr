#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct intvector {
  int data[100];
  int size;
} intvector;

typedef struct vecvector {
  intvector data[300];
  int size;
} vecvector;

void push_back_vec(vecvector* v, const intvector* data) {
  v->data[v->size++] = *data;
}

void push_back_int(intvector* v, int x) { v->data[v->size++] = x; }

vecvector ans[11];

vecvector* divide_number(int n) {
  // return a char[1000][100]
  if (ans[n].size != 0) {
    return &ans[n];
  }
  for (int i = 1; i < n; ++i) {
    vecvector* d = divide_number(n - i);
    vecvector* m = divide_number(i);
    for (int j = 0; j < d->size; ++j) {
      for (int k = 0; k < m->size; ++k) {
        intvector x = d->data[j];
        for (int kk = 0; kk < m->data[k].size; ++kk)
          push_back_int(&x, m->data[k].data[kk]);
        push_back_vec(&ans[n], &x);
      }
    }
  }
  intvector x;
  x.size = 0;
  memset(x.data, 0, sizeof(x.data));
  push_back_int(&x, n);
  push_back_vec(&ans[n], &x);
  return &ans[n];
}

int cmp(const void* a, const void* b) { return *(int*)(a) < *(int*)(b); }
int hash(const intvector* s) {
  int res = 0;
  for (int i = 0; i < s->size; ++i) {
    res += s->data[i] * pow(10, i);
  }
  return res;
}

char occured[10000000];

int main() {
  intvector tmp;
  memset(tmp.data, 0, sizeof(tmp));
  tmp.size = 0;
  push_back_int(&tmp, 1);
  push_back_vec(&ans[1], &tmp);
  int n;
  scanf("%d", &n);
  divide_number(n);
  for (int i = 0; i < ans[n].size; ++i) {
    qsort(ans[n].data[i].data, ans[n].data[i].size, sizeof(int), cmp);
  }
  for (int i = 0; i < ans[n].size; ++i) {
    int hs = hash(&ans[n].data[i]);
    if (occured[hs])
      continue;
    occured[hs] = 1;
    for (int j = 0; j < ans[n].data[i].size; ++j) {
      printf("%d ", ans[n].data[i].data[j]);
      if (j != ans[n].data[i].size - 1)
        printf("+ ");
    }
    puts("");
  }
  return 0;
}
