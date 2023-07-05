#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void assert_int(int got, int expected, int line) {
  if (got != expected) {
    fprintf(stderr, "Assert fail at Line %d. Expected: %d, got: %d.\n", line,
            expected, got);
    exit(EXIT_FAILURE);
  }
}

void assert_true(bool got, int line) {
  if (!got) {
    fprintf(stderr,
            "Assert fail at Line %d. Expected to be true but got false.\n",
            line);
    exit(EXIT_FAILURE);
  }
}

int main(void) {
  printf("Queue in C\n");

  Queue *q = queue_new();

  assert_int(queue_head(q), QUEUE_EMPTY, __LINE__);
  assert_int(queue_tail(q), QUEUE_EMPTY, __LINE__);

  assert_true(enqueue(q, 0), __LINE__);
  assert_int(queue_len(q), 1, __LINE__);
  assert_int(queue_head(q), 0, __LINE__);
  assert_int(queue_tail(q), 0, __LINE__);

  assert_true(enqueue(q, 1), __LINE__);
  assert_int(queue_len(q), 2, __LINE__);
  assert_int(queue_head(q), 0, __LINE__);
  assert_int(queue_tail(q), 1, __LINE__);

  assert_true(enqueue(q, 2), __LINE__);
  assert_int(queue_len(q), 3, __LINE__);
  assert_int(queue_head(q), 0, __LINE__);
  assert_int(queue_tail(q), 2, __LINE__);

  assert_int(dequeue(q), 0, __LINE__);
  assert_int(dequeue(q), 1, __LINE__);
  assert_int(dequeue(q), 2, __LINE__);
  assert_int(dequeue(q), QUEUE_EMPTY, __LINE__);

  queue_free(q);

  printf("All tests passed!\n");

  return 0;
}
