#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char** argv) {
  char buff[1000];
  FILE* fp;
  if (argc != 2 && argc != 3) {
    printf("Arguments error!\n");
    exit(-1);
  }
  if ((fp = fopen(argv[1], "r")) == NULL) {
    printf("Can't open %s\n", argv[1]);
    exit(-1);
  }
  bool page = argc == 3 && !strcmp("/p", argv[2]);
  for (int i = 1; fgets(buff, sizeof(buff), fp) != NULL; ++i) {
    if (page) {
      if (i != 1 && i % 25 == 1) {
        getchar();
      }
    }
    printf("%2d %s", i, buff);
  }
  fclose(fp);
  return 0;
}
