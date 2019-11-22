#include <stdio.h>
#include <stdlib.h>

typedef struct student {
  char name[20];
  int score;
} student;

typedef struct stu_array {
  student d[1000];
  int size;
} stu_array;

void swap_stu(student* a, student* b) {
  student c;
  c = *a, *a = *b, *b = c;
}

void print_score(const stu_array* arr) {
  for (int i = 0; i < arr->size; ++i) {
    printf("%s: %d\n", arr->d[i].name, arr->d[i].score);
  }
}

int cmp_stu(const void* a, const void* b) {
  return ((const student*)a)->score < ((const student*)b)->score;
}

void sort_score(stu_array* arr) {
  qsort(arr->d, arr->size, sizeof(arr->d[0]), cmp_stu);
}

int search(const stu_array* arr, int sc) {
  int l = 0, r = arr->size, m = (r - l) / 2 + l; // [l, r)
  while (l < r) {
    m = (r - l) / 2 + l;
    if (arr->d[m].score > sc)
      l = m + 1;
    else if (arr->d[m].score == sc)
      return m;
    else
      r = m;
  }
  if (arr->d[l].score == sc)
    return l;
  else if (arr->d[r].score == sc)
    return r;
  else
    return -1;
}

int main() {
  puts("Pls input the number of the students");
  int n;
  scanf("%d", &n);
  puts("Pls input n students and their score");
  stu_array arr;
  arr.size = n;
  for (int i = 0; i < n; ++i) {
    scanf("%s %d", &arr.d[i].name, &arr.d[i].score);
  }
  while (1) {
    puts("1. sort, 2. output, 3.search");
    int op;
    scanf("%d", &op);
    switch (op) {
    case 1: {
      sort_score(&arr);
      break;
    }
    case 2: {
      print_score(&arr);
      break;
    }
    case 3: {
      int sc;
      puts("Pls input the score");
      scanf("%d", &sc);
      int res = search(&arr, sc);
      if (res != -1) {
        printf("%s: %d\n", arr.d[res].name, arr.d[res].score);
      } else {
        puts("No such score");
      }
      break;
    }
    default:
      puts("Unknown operation");
      break;
    }
  }
}
