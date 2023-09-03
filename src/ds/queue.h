#ifndef QUEUE_H
#define QUEUE_H

#include <limits.h>
#include <stdbool.h>

#ifndef QUEUE_EMPTY
#define QUEUE_EMPTY INT_MIN
#endif

typedef struct myNode Node;
typedef struct myQueue Queue;

int queue_len(Queue *q);
Queue *queue_new();
bool enqueue(Queue *q, int value);
int dequeue(Queue *q);
int queue_head(Queue *q);
int queue_tail(Queue *q);
void queue_free(Queue *q);

#endif // QUEUE_H
