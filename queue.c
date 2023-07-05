#include <stdlib.h>
#include "queue.h"

typedef struct myNode {
  int value;
  struct myNode *prev;
  struct myNode *next;
} Node;

typedef struct myQueue {
  Node *head;
  Node *tail;
  size_t len;
} Queue;

int queue_len(Queue *q) {
  if (q == NULL)
    return 0;
  return q->len;
}

Queue *queue_new() {
  Queue *s = malloc(sizeof(Queue));
  s->len = 0;
  return s;
}

bool enqueue(Queue *q, int value) {
  Node *node = malloc(sizeof(Node));
  if (node == NULL)
    return false;

  q->len++;

  if (q->head == NULL && q->tail == NULL) {
    q->head = node;
    q->tail = node;

    return true;
  }

  Node *tmp = q->tail;
  node->value = value;
  node->next = tmp;

  tmp->prev = node;
  q->tail = node;

  return true;
}

int dequeue(Queue *q) {
  if (q->head == NULL)
    return QUEUE_EMPTY;

  Node *tmp = q->head;
  int value = tmp->value;
  q->head = tmp->prev;

  free(tmp);

  return value;
}

int queue_head(Queue *q) {
  if (q->head == NULL)
    return QUEUE_EMPTY;
  return q->head->value;
}

int queue_tail(Queue *q) {
  if (q->tail == NULL)
    return QUEUE_EMPTY;
  return q->tail->value;
}

void queue_free(Queue *q) { free(q); }

