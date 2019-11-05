#include <stdio.h>
int char_count, word_count, line_count = 1;
char ch;
int state;
enum { kchn, keng, kendl, kspc };

char fill_ch() {
  ++char_count;
  ch = getchar();
  return ch;
}

int is_chn(char s) { return s & 0x80; }

int is_spc(char s) { return s == ' ' || s == '\n' || s == '\t'; }

int is_newline(char s) { return s == '\n'; }

int is_eng(char s) {
  return ('0' <= s && s <= '9' || 'a' <= s && s <= 'z' || 'A' <= s && s <= 'Z');
}

int is_eof(char s) { return s == EOF; }

char peek_next() {
  ch = getchar();
  ungetc(ch, stdin);
  return ch;
}

void set_state() {
  char cc = peek_next();
  if (is_eng(cc))
    state = keng;
  else if (is_newline(cc))
    state = kendl;
  else if (is_spc(cc))
    state = kspc;
  else if (is_chn(cc))
    state = kchn;
}

int main() {
  set_state();
  while (ch != EOF) {
    switch (state) {
    case kchn: {
      fill_ch();
      fill_ch();
      ++word_count;
      --char_count;
      set_state();
      break;
    }
    case keng: {
      while(is_eng(ch)) {
        fill_ch();
      }
      ungetc(ch, stdin);
      --char_count;
      ++word_count;
      set_state();
      break;
    }
    case kendl: {
      ++line_count;
      --char_count;
      fill_ch();
      set_state();
      break;
    }
    case kspc: {
      fill_ch();
      --char_count;
      set_state();
      break;
    }
    }
  }
  printf("%d lines, %d chars, %d words", line_count, char_count, word_count);
}
