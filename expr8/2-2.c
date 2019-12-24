#include <stdio.h>
#include <stdlib.h>
int main(int argc, char** argv) {
  char buff[1000];
  FILE* fp;
  if (argc != 2) {
    printf("Arguments error!\n");
    exit(-1);
  }
  if ((fp = fopen(argv[1], "r")) == NULL) {
    printf("Can't open %s\n", argv[1]);
    exit(-1);
  }
  for (int i = 1; fgets(buff, sizeof(buff), fp) != NULL; ++i) {
    printf("%d %s", i, buff);
  }
  fclose(fp);
  return 0;
}
