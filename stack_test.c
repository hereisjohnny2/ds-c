#include "stack.h"
#include "test_utils.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
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

  return 0;
}
