#ifndef QUEUE_TEST_H
#define QUEUE_TEST_H

#include "../ds/queue.h"
#include "test_utils.h"
#include <stdio.h>
#include <stdlib.h>

void test_queue() {
  printf("Queue in C\n");

  Queue *q = queue_new();

  ASSERT_EQ(queue_head(q), QUEUE_EMPTY);
  ASSERT_EQ(queue_tail(q), QUEUE_EMPTY);

  ASSERT_TRUE(enqueue(q, 0));
  ASSERT_EQ(queue_len(q), 1);
  ASSERT_EQ(queue_head(q), 0);
  ASSERT_EQ(queue_tail(q), 0);

  ASSERT_TRUE(enqueue(q, 1));
  ASSERT_EQ(queue_len(q), 2);
  ASSERT_EQ(queue_head(q), 0);
  ASSERT_EQ(queue_tail(q), 1);

  ASSERT_TRUE(enqueue(q, 2));
  ASSERT_EQ(queue_len(q), 3);
  ASSERT_EQ(queue_head(q), 0);
  ASSERT_EQ(queue_tail(q), 2);

  ASSERT_EQ(dequeue(q), 0);
  ASSERT_EQ(dequeue(q), 1);
  ASSERT_EQ(dequeue(q), 2);
  ASSERT_EQ(dequeue(q), QUEUE_EMPTY);

  queue_free(q);

  printf("All tests passed!\n");
}

#endif // QUEUE_TEST_H
