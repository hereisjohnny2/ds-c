#ifndef STACK_TEST_H
#define STACK_TEST_H

#include "../ds/stack.h"
#include "test_utils.h"
#include <stdio.h>
#include <stdlib.h>

void test_stack() {
  printf("Stack in C\n");

  Stack *s = stack_new();

  ASSERT_EQ(stack_peek(s), STACK_EMPTY);
  ASSERT_TRUE(stack_push(s, 0));
  ASSERT_EQ(stack_len(s), 1);
  ASSERT_EQ(stack_peek(s), 0);
  ASSERT_TRUE(stack_push(s, 1));
  ASSERT_EQ(stack_len(s), 2);
  ASSERT_EQ(stack_peek(s), 1);
  ASSERT_EQ(stack_pop(s), 1);
  ASSERT_EQ(stack_pop(s), 0);
  ASSERT_EQ(stack_pop(s), STACK_EMPTY);

  stack_free(s);

  printf("All tests passed!\n");
}

#endif // STACK_TEST_H
