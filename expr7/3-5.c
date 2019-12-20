#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node node;
typedef struct single_list single_list;

struct node {
  void* data;
  node* next;
};

struct single_list {
  node* head;
  int size;
};

single_list init_list() {
  single_list x;
  x.size       = 0;
  x.head       = malloc(sizeof(node));
  x.head->next = x.head->data = NULL;
  return x;
}

single_list push_back_list(single_list x, void* data) {
  node* t = x.head;
  while (t->next)
    t = t->next;
  t->next       = malloc(sizeof(node));
  t->next->next = NULL;
  t->next->data = data;
  x.size++;
  return x;
}

single_list push_front_list(single_list x, void* data) {
  node* t = x.head;
  node* n = malloc(sizeof(node));
  n->data = data;
  n->next = t->next;
  t->next = n;
  x.size++;
  return x;
}

single_list insert_list(single_list x, void* data, int pos) {
  // after insert, data stays in the pos postion
  node* t = x.head;
  for (int i = 0; i < pos && t->next; ++i, t = t->next)
    ;
  node* n = malloc(sizeof(node));
  n->data = data;
  n->next = t->next;
  t->next = n;
  x.size++;
  return x;
}

void* in_access_list(single_list x, int pos) {
  node* t = x.head;
  for (int i = 0; i <= pos && t->next; ++i, t = t->next)
    ;
  return t->data;
}

#define access_list(type) (type*)in_access_list

int search_list(single_list x, void* data,
                int (*eq)(const void* a, const void* b)) {
  node* t = x.head->next;
  for (int i = 0; t->next; ++i, t = t->next)
    if (eq(t->data, data))
      return i;
  return -1;
}

#define from_heap(type)                                                        \
  type* from_heap_##type(type x) {                                             \
    type* t = malloc(sizeof(type));                                            \
    *t      = x;                                                               \
    return t;                                                                  \
  }

single_list delete_node(single_list x, int pos) {
  node* t = x.head;
  for (int i = 0; i < pos && t->next; ++i, t = t->next)
    ;
  node* d = t->next;
  t->next = d->next;
  free(d->data);
  d->next = d->data = NULL;
  free(d);
  x.size--;
  return x;
}

single_list pop_front_list(single_list x) { return delete_node(x, 0); }

single_list pop_back_list(single_list x) { return delete_node(x, x.size - 1); }

void drop_nodes(node* x) {
  if (x->next) {
    drop_nodes(x->next);
  }
  free(x->data);
  x->data = x->next = NULL;
  free(x);
}

void drop_list(single_list x) { drop_nodes(x.head); }

int iseq(const int* a, const int* b) { return *a == *b; }

from_heap(int);

int main() {
  single_list s = init_list();
  char c;
  int num_in_read = 0;
  while ((c = getchar()) != '\n') {
    if (isdigit(c)) {
      num_in_read *= 10;
      num_in_read += c - '0';
    } else if (isblank(c)) {
      s           = push_front_list(s, from_heap_int(num_in_read));
      num_in_read = 0;
    } else {
      int m   = *access_list(int)(s, 0);
      s       = pop_front_list(s);
      int t   = *access_list(int)(s, 0);
      s = pop_front_list(s);
      int res = 0;
      if (c == '+') {
        res = t + m;
      } else if (c == '-') {
        res = t - m;
      } else if (c == '*') {
        res = t * m;
      } else if (c == '/') {
        res = t / m;
      }
      num_in_read = 0;
      s           = push_front_list(s, from_heap_int(res));
      getchar();
    }
  }
  printf("%d\n", *access_list(int)(s, 0));
  drop_list(s);
}
