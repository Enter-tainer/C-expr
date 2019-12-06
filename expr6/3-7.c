#include <stdio.h>
#include <string.h>

#define f(x)                                                                   \
  void task##x() { puts("task" #x " is called"); }
f(0) f(1) f(2) f(3) f(4) f(5) f(6) f(7)

#define push_back(x, i)                                                        \
  if (str[i] - '0' == x) {                                                     \
    *t++ = task##x;                                                            \
    continue;                                                                  \
  }

typedef void (*func_t)(void);
void execute(func_t a[], int n) {
  for (int i = 0; i < n; i++) {
    a[i]();
  }
}

void scheduler(const char* str) {
  int len = strlen(str);
  func_t a[8];
  func_t* t = a;
  for (int i = 0; i < len; i++) {
    push_back(0, i);
    push_back(1, i);
    push_back(2, i);
    push_back(3, i);
    push_back(4, i);
    push_back(5, i);
    push_back(6, i);
    push_back(7, i);
  }
  execute(a, len);
}

int main() {
  char str[100];
  while (1) {
    scanf("%s", str);
    scheduler(str);
  }
}
