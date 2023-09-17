#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <limits.h>
#include <stdbool.h>
#include <stddef.h>

#ifndef LIST_EMPTY 
#define LIST_EMPTY INT_MIN
#endif

typedef struct myNode Node;
typedef struct myList List;

int list_len(List *q);
List *list_from_array(size_t size, int *arr);
List *list_new();
bool list_push(List *l, int value);
int list_shift(List *l);
int list_pop(List *l);
bool insert_at(List *l, int pos, int value);
int list_get(List *l, int pos);
int list_first(List *l);
int list_last(List *l);
void list_print(List *l);
bool list_equal(List *l1, List *l2);
void list_free(List *l);

#endif // LINKED_LIST_H
