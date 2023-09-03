#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <limits.h>
#include <stdbool.h>

#ifndef LIST_EMPTY 
#define LIST_EMPTY INT_MIN
#endif

typedef struct myNode Node;
typedef struct myList List;

int list_len(List *q);
List *list_new();
bool list_push(List *l, int value);
int list_shift(List *l);
int list_pop(List *l);
bool insert_at(List *l, int pos, int value);
int list_get(List *l, int pos);
int list_first(List *l);
int list_last(List *l);
void list_free(List *l);

#endif // LINKED_LIST_H
