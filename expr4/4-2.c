#include <stdio.h>
#include <string.h>

int mpow(int n, int p) {
  int res = n;
  for (int i = 1; i < p; ++i)
    res *= n;
  return res;
}

int getkth(int n, int k) {
  // 998244353
  // 987654321
  if (n == 0)
    return 0;
  int res;
  for (; k; k--, n /= 10)
    res = n % 10;
  return res;
}

int intlen(int n) {
  if (n == 0)
    return 1;
  int l = 0;
  for (; n; l++, n /= 10)
    ;
  return l;
}

int is_zimi(int n) {
  int l   = intlen(n);
  int sum = 0;
  for (int i = 1; i <= l; ++i) {
    sum += mpow(getkth(n, i), l);
  }
  return sum == n;
}

int main() {
  char* msg[] = {"",
                 "",
                 "",
                 "三位的水仙花数",
                 "四位的四叶玫瑰数",
                 "五位的五角星数",
                 "六位的六合数",
                 "七位的北斗七星数",
                 "八位的八仙数"};
  while (1) {
    int k;
    scanf("%d", &k);
    if (k == 0) {
      break;
    }
    int l = mpow(10, k) / 10, r = mpow(10, k + 1) / 10;
    int ans[100], *ptr          = ans;
    for (int i = 0; i < 100; ans[i] = 0, ++i)
      ;
    int cnt = 0;
    for (int i = l; i < r; ++i) {
      if (is_zimi(i))
        *(ptr++) = i, cnt++;
    }
    printf("%s共有%d个: ", msg[k], cnt);
    for (ptr = ans; *ptr; ++ptr)
      printf("%d ", *ptr);
    puts("");
  }
}
