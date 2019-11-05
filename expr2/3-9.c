#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_valid_char(char c) { return '0' <= c && c <= '9' || c == '.'; }
int is_num(char c) { return '0' <= c && c <= '9'; }
int is_dot(char c) { return c == '.'; }
int in_range(int c) { return 0 <= c && c <= 255; }
void no() {
  printf("NO");
  exit(0);
}

char ch;
char* next_ptr;
char next() {
  ch = *next_ptr;
  next_ptr++;
  return ch;
}

char peek() { return *next_ptr; }
int state = -1;

void node0() {
  if (is_num(peek()))
    state++, next();
  else
    no();
}

void node1(int next_state) {
  if (is_num(peek()))
    state++, next();
  else if (is_dot(peek()))
    next(), state = next_state;
  else
    no();
}

void node2(int next_state) {
  if (is_num(peek()))
    state++, next();
  else if (peek() == 0)
    next(), state = next_state;
  else
    no();
}

int main() {
  char str[100];
  memset(str, -1, 100);
  scanf("%s", str);
  next_ptr = str;

  while (*next_ptr != -1) {
    switch (state) {
    case -1:
    case 3:
    case 7:
    case 11:
    {
      node0();
      break;
    }
    case 0:
    case 1:
    case 2: {
      node1(3);
      break;
    }
    case 4:
    case 5:
    case 6: {
      node1(7);
      break;
    }
    case 8:
    case 9:
    case 10: {
      node1(11);
      break;
    }
    case 12:
    case 13:{
      node2(14);
      break;
    }
    case 14: {
      next();
      break;
    }
    }
  }
  union Uip
  {
    unsigned int v;
    unsigned char bytes[4];
  } ip;
  int num[4];
  sscanf(str, "%d.%d.%d.%d", num + 3, num + 2, num + 1, num);
  for (int i = 0; i < 4; ++i) {
    ip.bytes[i] = num[i];
    if (!in_range(num[i]))
      no();
  }
  printf("YES %u", ip.v);
}
