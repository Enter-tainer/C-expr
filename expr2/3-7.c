// this program outputs the No.k day is the d-th Day of month m of a given year
#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int isleap(int year) {
  // if year is a leap year, this function returns true
  if (year % 4 == 0) {
    if (year % 100 == 0)
      return year % 400 == 0;
    else
      return 1;
  } else {
    return 0;
  }
}

int main() {
  int y, d;
  scanf("%d%d", &y, &d);
  for (int i = 1; i < 13; ++i)
    daytab[0][i] += daytab[0][i - 1], daytab[1][i] += daytab[1][i - 1];
  int leap = isleap(y);
  int mo   = 0;
  for (; daytab[leap][mo + 1] < d; ++mo)
    ;
  printf("%d 月 %d 日", mo + 1, d - daytab[leap][mo]);
  return 0;
}
