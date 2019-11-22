#include <stdio.h>
#include <string.h>

void strnins(char[], char[], int);

int main () {
  char s1[100] = "123321", s2[100] = "ASDAD";
  strnins(s1, s2, 3);
  puts(s2);
}

void strnins(char s[], char t[], int n) {
  int i = 0, j = n;
  while ((t[j++] = s[i++]))
    ;
  t[j] = 0;
}
