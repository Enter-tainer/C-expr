#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_valid_char(char c) {
  return '0' <= c && c <= '9' || c == '.';
} // return true if c is a valid char
int is_num(char c) { return '0' <= c && c <= '9'; }
int is_dot(char c) { return c == '.'; }
int in_range(int c) { return 0 <= c && c <= 255; }
// return true if 0 <= c <= 255
void no() {
  // if match fails, just output a error message and exit
  printf("NO");
  exit(0);
}

char ch;
char* next_ptr; // it points to the next char in stdin
char next() {
  ch = *next_ptr;
  next_ptr++;
  return ch;
}

char peek() { return *next_ptr; } // peek the next char in stdin
int state = -1;                   // -1 is the initial state

void node0() {
  // node0 is a kind of node in FSM with same transistion
  if (is_num(peek()))
    state++, next();
  else
    no();
}

void node1(int next_state) {
  // node1 is a kind of node in FSM with same transistion
  if (is_num(peek()))
    state++, next();
  else if (is_dot(peek()))
    next(), state = next_state;
  else
    no();
}

void node2(int next_state) {
  // node2 is a kind of node in FSM with same transistion
  if (is_num(peek()))
    state++, next();
  else if (peek() == 0)
    next(), state = next_state;
  else
    no();
}

int main() {
  char str[100];
  memset(str, -1, 100); // set str[] to -1 to find the end
  scanf("%s", str);
  next_ptr = str;

  while (*next_ptr != -1) {
    // run the finite state machine (FSM)
    // this DFA matches regex: (\d{1-3}\.){3}\d{1-3}
    switch (state) {
    case -1:
    case 3:
    case 7:
    case 11: {
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
    case 13: {
      node2(14);
      break;
    }
    case 14: {
      next();
      break;
    }
    }
  }
  union Uip {
    unsigned int v;
    unsigned char bytes[4];
  } ip;
  // this union provides a way to access the every byte of a int, which makes it easiser
  int num[4];
  sscanf(str, "%d.%d.%d.%d", num + 3, num + 2, num + 1, num);
  for (int i = 0; i < 4; ++i) {
    ip.bytes[i] = num[i];
    if (!in_range(num[i]))
      no();
    // check if all part is greater than 0 and less than 255
  }
  printf("YES %u", ip.v);
}
