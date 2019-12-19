#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bits {
  unsigned char d0 : 1;
  unsigned char d1 : 1;
  unsigned char d2 : 1;
  unsigned char d3 : 1;
  unsigned char d4 : 1;
  unsigned char d5 : 1;
  unsigned char d6 : 1;
  unsigned char d7 : 1;
} bits;

typedef union byte
{
  bits d;
  unsigned char c;
} byte;


#define gen_func(i)                                                            \
  void f##i(int b) { printf("the function %d is called\n", b); }

#define gen_if(bits_name, i)                                                   \
  if (bits_name.d##i)                                                          \
    p[i](i);

gen_func(0);
gen_func(1);
gen_func(2);
gen_func(3);
gen_func(4);
gen_func(5);
gen_func(6);
gen_func(7);

void (*p[8])(int) = {f0, f1, f2, f3, f4, f5, f6, f7};

int main () {
  unsigned char s;
  s = 0b10100010;
  byte x;
  x.c = s;
  gen_if(x.d, 0);
  gen_if(x.d, 1);
  gen_if(x.d, 2);
  gen_if(x.d, 3);
  gen_if(x.d, 4);
  gen_if(x.d, 5);
  gen_if(x.d, 6);
  gen_if(x.d, 7);
}
