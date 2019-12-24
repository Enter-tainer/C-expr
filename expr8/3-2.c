#include <stdio.h>

int main () {
  float data[10];
  for (int i = 0; i < 10; i++) {
    scanf("%f", data + i);
  }
  FILE *fp = fopen("float.dat", "wb");
  fwrite(data, sizeof(float), 10, fp);
  fclose(fp);
  fp = fopen("float.dat", "rb");
  fread(data, sizeof(float), 10, fp);
  for (int i = 0; i < 10; i++) {
    printf("%f\n", data[i]);
  }
}
