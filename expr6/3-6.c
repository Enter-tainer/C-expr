#include <stdio.h>
#include <string.h>

typedef struct mint {
  short d[500];
  int len;
} mint;

mint add(const mint* a, const mint* b) {
  const mint* c = a;
  if (a->len > b->len)
    a = b, b = c;
  mint t = *a;
  for (int i = 0; i < t.len; ++i) {
    t.d[i] += b->d[i];
    if (t.d[i] >= 10) {
      t.d[i] %= 10, t.d[i + 1]++;
      if (i == t.len - 1)
        ++t.len;
    }
  }
  for (int i = t.len; i < b->len; ++i) {
    t.len++;
    t.d[i] = b->d[i];
  }
  return t;
}

mint mul(const mint* a, const mint* b) {
  const mint* c = a;
  if (a->len > b->len)
    a = b, b = c;
  mint t;
  memset(&t, 0, sizeof(t));
  t.len = 1;
  for (int i = 0; i < a->len; i++) {
    for (int j = 0; j < b->len; ++j) {
      t.d[i + j] += a->d[i] * b->d[j];
    }
    for (int j = 0; j < t.len; ++j) {
      if (t.d[j] >= 10) {
        int c = t.d[j] / 10;
        t.d[j] %= 10;
        t.d[j + 1] += c;
        if (j == t.len - 1)
          ++t.len;
      }
    }
  }
  for (int i = 499; i >= 1; --i)
    if (t.d[i]) {
      t.len = 1 + i;
      break;
    }
  for (int j = 0; j < t.len; ++j) {
    if (t.d[j] >= 10) {
      int c = t.d[j] / 10;
      t.d[j] %= 10;
      t.d[j + 1] += c;
      if (j == t.len - 1)
        ++t.len;
    }
  }
  return t;
}

mint from_str(const char* str) {
  mint t;
  memset(&t, 0, sizeof(t));
  t.len = strlen(str);
  for (int i = t.len - 1; i >= 0; --i) {
    t.d[i] = str[t.len - i - 1] - '0';
  }
  return t;
}

void print(const mint* t) {
  for (int i = t->len - 1; i >= 0; --i) {
    putchar(t->d[i] + '0');
  }
}

int main() {
  char stra[300], strb[300];
  scanf("%s %s", stra, strb);
  mint a = from_str(stra), b = from_str(strb);
  mint c = mul(&a, &b);
  print(&c);
}
