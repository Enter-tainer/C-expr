#include <stdio.h>
#include <string.h>
void RemoveDuplicate(char* s);
int main() {
  char str[200];
  printf("Input strings, end of Ctrl+z\n");
  while (fgets(str, 200, stdin) != NULL) {
    RemoveDuplicate(str);
    printf("%s", str);
  }
  return 0;
}

void RemoveDuplicate(char* s) {
  char arr[500];
  memset(arr, 0, sizeof(arr));
  int r, w, i, len;
  len = strlen(s);
  for (r = w = 0; r < len; ++r) {
    if (!arr[s[r]]) {
      arr[s[r]] = 1;
      s[w++] = s[r];
    }
  }
  s[w] = 0;
}
