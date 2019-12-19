#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

single_list read_num(single_list x) {
  char buff[1000];
  fgets(buff, sizeof(buff), stdin);
  int len = strlen(buff);
  for (int i = 0; i < len - 1; i++)
    x = push_front_list(x, from_heap_int(buff[i] - '0'));
  return x;
}

void print_node(node* n) {
  if (n) {
    print_node(n->next);
    putchar('0' + *((int*)n->data));
  }
}

void print_num(single_list x) { print_node(x.head->next); }

single_list plus(single_list a, single_list b) {
  single_list z = init_list();
  int inc = 0;
  if (a.size < b.size) {
    single_list x = a;
    a             = b;
    b             = x;
  }
  while (b.size) {
    int numa = *(access_list(int)(a, 0)), numb = *access_list(int)(b, 0);
    a = pop_front_list(a);
    b = pop_front_list(b);
    int nextv = numa + numb + inc;
    inc       = nextv / 10;
    nextv %= 10;
    z = push_front_list(z, from_heap_int(nextv));
  }
  while (a.size) {
    int num = *access_list(int)(a, 0);
    a = pop_front_list(a);
    int nextv = num + inc;
    inc = nextv / 10;
    nextv %= 10;
    z = push_front_list(z, from_heap_int(nextv));
  }
  if (inc) {
    z = push_front_list(z, from_heap_int(inc));
  }
  return z;
}

int main() {
  single_list x = init_list(), y = init_list(), z;
  x = read_num(x);
  y = read_num(y);
  z = plus(x, y);
  for (node* i = z.head->next; i; i = i->next)
    putchar('0' + *((int*)(i->data)));
  drop_list(z);
  drop_list(x);
  drop_list(y);
}
