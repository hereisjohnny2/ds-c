#include <stdlib.h>
#include "queue.h"

typedef struct myNode {
  int value;
  struct myNode *next;
} Node;

typedef struct myQueue {
  Node *head;
  Node *tail;
  size_t len;
} Queue;

int queue_len(Queue *q) {
  if (!q)
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

  node->value = value;

  if (q->len == 0) {
    q->len++;
    q->head = node;
    q->tail = node;

    return true;
  }

  q->len++;

  Node *tmp = q->tail;
  tmp->next = node;
  q->tail = node;

  return true;
}

int dequeue(Queue *q) {
  if (q->len == 0)
    return QUEUE_EMPTY;

  q->len--;

  Node *tmp = q->head;
  int value = tmp->value;
  q->head = tmp->next;

  free(tmp);

  return value;
}

int queue_head(Queue *q) {
  if (q->len == 0) {
    return QUEUE_EMPTY;
  }

  return q->head->value;
}

int queue_tail(Queue *q) {
  if (q->len == 0)
    return QUEUE_EMPTY;
  return q->tail->value;
}

void queue_free(Queue *q) { free(q); }

