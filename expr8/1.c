#include <stdio.h>
int main (void) {
  short a = 0x253f, b = 0x7b7d;
  // 0x25 %
  // 0x3f ?
  // 0x7b {
  // 0x7d }
  char ch;
  FILE *fp1, *fp2;
  fp1 = fopen("./test1.bin", "wb+");
  fp2 = fopen("./test2.txt", "w+");
  fwrite(&a, sizeof(short), 1, fp1);
  fwrite(&b, sizeof(short), 1, fp1);
  fprintf(fp2, "%d %d", a, b);

  rewind(fp1);
  rewind(fp2);
  while ((ch = fgetc(fp1)) != EOF)
    putchar(ch);
  putchar('\n');
  while ((ch = fgetc(fp2)) != EOF)
    putchar(ch);
  fclose(fp1);
  fclose(fp2);
  return 0;
}
