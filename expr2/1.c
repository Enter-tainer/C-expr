#include <stdio.h>
#define PI 3.14159
//                ^
// 删除多余的分号

int main () {
  int f;
  short p, k;
  double c, r, s;
  // Task 1
  printf("Input Fahrenheit:");
  scanf("%d", &f); 
  //          ^
  // scanf 的第二个参数应该是地址，因此使用取地址符，否则会访问到非法内存
  c = 1.0 * 5 / 9 * (f - 32);
  //  ^^^^^^
  // 该表达式中全是整数，进行除法运算时会发生截断，丢失精度，故乘一个浮点数，让表达式的类型变成双精度浮点型保持精度
  printf("\n%d (F) = %.2f (C)\n\n", f, c);
  // Task 2
  printf("Input the radius r:");
  scanf("%lf", &r);
  //     ^^^
  // 使用 scanf 输入双精度浮点数时，应该使用 %lf
  s = PI * r * r;
  printf("\n The acreage is %.2f\n\n", s);
  //                                  ^^^
  // 输出时，应当传值，而不是传指针，故删去取地址符号
  // Task 3
  k = 0xa1b2, p = 0x8423;
  unsigned short newint = p & 0xff00 | (unsigned short)(k) >> 8; 
  //             ^^^^^^                ^^^^^^^^^^^^^^^^^^^
  // newint 没有声明
  // 有符号负数右移时会在高位补 1，因此应当转换成无符号来得到正确结果
  printf("new int = %#x\n\n", (unsigned int)newint);
  //                          ^^^^^^^^^^^^^^
  // %x 用于输出 unsigned int，因此应当进行转换，以避免错误　
  return 0;
}