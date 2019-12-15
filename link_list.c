#include <stdio.h>

typedef struct node node;
typedef struct single_list single_list;

struct node
{
  void *data;
  node *prev, *next;
};

struct single_list
{
  node *head;
  int size;
};

single_list init_list()
{
  single_list x;
  x.size = 0;
  x.head = malloc(sizeof(node));
  x.head->prev = x.head->next = x.head->data = NULL;
  return x;
}

single_list push_back_list(single_list x, void *data)
{
  node *t = x.head;
  while (t->next)
    t = t->next;
  t->next = malloc(sizeof(node));
  t->next->next = NULL;
  t->next->data = data;
  x.size++;
  return x;
}

single_list push_front_list(single_list x, void *data)
{
  node *t = x.head;
  node *n = malloc(sizeof(node));
  n->data = data;
  n->next = t->next;
  t->next = n;
  x.size++;
  return x;
}

single_list insert_list(single_list x, void *data, int pos)
{
  // after insert, data stays in the pos postion
  node *t = x.head;
  for (int i = 0; i < pos && t->next; ++i, t = t->next)
    ;
  node *n = malloc(sizeof(node));
  n->data = data;
  n->next = t->next;
  t->next = n;
  x.size++;
  return x;
}

void *in_access_list(single_list x, int pos)
{
  node *t = x.head;
  for (int i = 0; i <= pos && t->next; ++i, t = t->next)
    ;
  return t->data;
}

#define access_list(type) (type *)in_access_list

int search_list(single_list x,
                void *data,
                int (*eq)(const void *a, const void *b))
{
  node *t = x.head->next;
  for (int i = 0; t->next; ++i, t = t->next)
    if (eq(t->data, data))
      return i;
  return -1;
}

#define from_heap(type)             \
  type *from_heap_##type(type x)    \
  {                                 \
    type *t = malloc(sizeof(type)); \
    *t = x;                         \
    return t;                       \
  }

single_list delete_node(single_list x, int pos)
{
  node *t = x.head;
  for (int i = 0; i < pos && t->next; ++i, t = t->next)
    ;
  node *d = t->next;
  t->next = d->next;
  free(d->data);
  d->next = d->data = NULL;
  free(d);
  x.size--;
  return x;
}

single_list pop_front_list(single_list x)
{
  return delete_node(x, 0);
}

single_list pop_back_list(single_list x)
{
  return delete_node(x, x.size - 1);
}

void drop_nodes(node *x)
{
  if (x->next)
  {
    drop_nodes(x->next);
  }
  free(x->data);
  x->data = x->next = NULL;
  free(x);
}

void drop_list(single_list x)
{
  drop_nodes(x.head);
}

int iseq(const int *a, const int *b)
{
  return *a == *b;
}

from_heap(int);
