#include <stdio.h>
int main () {
  char c, numchar, numline;
  numchar = 0;
  numline = 0;
  printf("输入若干行文本，Ctrl+z结束\n");
  while((c = getchar()) != EOF) { 
    //  ^-------------^
    // 赋值优先级低，应当加上括号
    numchar++;
    if (c == '\n')
      numline++;
  }
  printf("字符数：%d，", numchar); // 后缀 ++ 返回值还是自己，删去
  printf("行数：%d\n", numline);
  return 0;
}
