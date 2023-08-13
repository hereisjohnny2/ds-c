#include <stdlib.h>
#include "linked_list.h"

typedef struct myNode {
  int value;
  struct myNode *prev;
  struct myNode *next;
} Node;

typedef struct myList {
  Node *first;
  Node *last;
  size_t len;
} List;

int list_len(List *q) {
  if (q == NULL)
    return 0;
  return q->len;
}

List *list_new() {
  List *l = malloc(sizeof(List));
  l->len = 0;
  return l;
}

bool list_push(List *l, int value) {
  Node *node = malloc(sizeof(Node));
  if (node == NULL)
    return false;

  l->len++;
  node->value = value;

  if (l->first == NULL && l->last == NULL) {
    l->first = node;
    l->last = node;

    return true;
  }

  Node *tmp = l->last;
  node->prev = tmp;

  tmp->next = node;
  l->last = node;

  return true;
}

int list_shift(List *l) {
  if (l->first == NULL)
    return LIST_EMPTY;

  if (l->len == 0) {
    l->first = NULL;
    l->last = NULL;
    return LIST_EMPTY;
  }

  if (l->len == 1) {
    l->len--;
    int value = l->first->value;
    free(l->first);

    return value;
  }

  l->len--;

  Node *tmp = l->first;
  int value = tmp->value;
  l->first = tmp->next;

  free(tmp);

  return value;
}

int list_pop(List *l) {
  if (l->last == NULL)
    return LIST_EMPTY;

  if (l->len == 0) {
    l->first = NULL;
    l->last = NULL;
    return LIST_EMPTY;
  }

  if (l->len == 1) {
    l->len--;
    int value = l->last->value;
    return value;
  }

  l->len--;

  Node *tmp = l->last;
  int value = tmp->value;
  l->last = tmp->prev;

  free(tmp);

  return value;
}

bool insert_at(List *l, int pos, int value) {
  if (pos >= l->len) {
    return false;
  }

  Node *node = malloc(sizeof(Node));
  if (node == NULL) {
    return false;
  }

  l->len++;
  node->value = value;

  if (l->first == NULL && l->last == NULL) {
    l->first = node;
    l->last = node;

    return true;
  }

  Node *tmp = l->first;
  if (pos == 0) {
    node->next = tmp;
    l->first = node;

    return true;
  }

  if (pos == l->len - 1) {
    tmp = l->last;
    node->prev = tmp;
    l->last = node;

    return true;
  }

  for (int i = 1; i <= pos; i++) {
    tmp = tmp->next;
  }

  node->prev = tmp->prev;
  tmp->prev->next = node;

  node->next = tmp;
  tmp->prev = node;

  return true;
}

int list_get(List *l, int pos) {
  if (pos >= l->len) {
    return LIST_EMPTY;
  }

  Node *tmp = l->first;
  for (int i = 0; i < pos; i++) {
    tmp = tmp->next;
  }

  return tmp->value;
}

int list_first(List *l) {
  if (l->first == NULL)
    return LIST_EMPTY;
  return l->first->value;
}

int list_last(List *l) {
  if (l->last == NULL)
    return LIST_EMPTY;
  return l->last->value;
}

void list_free(List *l) { free(l); }
