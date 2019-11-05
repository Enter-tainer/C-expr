#include <stdio.h>

void strReverse(char s[]);
int strLength(char s[]);

int main () {
  char s[1000] = {0}; 
  //          ^^^^^^
  // 初始化，如果用户输入空串，不初始化的话行为未定义
  printf("输入一个字符串\n");
  scanf("%s", s);
  printf("串%s的长度为: %d\n", s, strLength(s));
  strReverse(s);
  printf("反转后: %s", s);
}

int strLength(char s[]) {
  int i = 0;
  while(s[i++]);
  return i - 1; 
  //     ^^^^^
  // 访问到空字符时，i已经表示字符串长度，自增之后应当再减去1才是实际长度
}

void strReverse(char s[]) {
  int i, j;
  for (i = 0, j = strLength(s) - 1; i < j; i++, j--) { 
    //        ^^^^^^^^^^^^^^^^^^^^
    // 数组下标从 0 开始，j 应当是 s 的长度减去 1
    char t;
    t = s[i];
    s[i] = s[j];
    s[j] = t;
  }
}