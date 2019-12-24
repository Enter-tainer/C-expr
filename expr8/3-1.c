#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
  if (argc != 4) {
    puts("Arguments error!");
    exit(-1);
  }
  char* name             = argv[1];
  char* str1             = argv[2];
  char* str2             = argv[3];
  FILE* fp               = fopen(name, "r");
  char buff[1024 * 1024] = {0};
  fread(buff, 1, 1024, fp);
  fclose(fp);
  fp = fopen(name, "w");
  char* i, *t = buff;
  for (i = strstr(buff, str1); i; ) {
    fwrite(t, 1, i - t, fp);
    fwrite(str2, 1, strlen(str2), fp);
    t = i + strlen(str1);
    i = strstr(t, str1);
  }
  fwrite(t, 1, strlen(t), fp);
}
