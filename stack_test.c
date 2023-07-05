#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

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
  printf("Stack in C\n");

  Stack *s = stack_new();

  assert_int(stack_peek(s), STACK_EMPTY, __LINE__);
  assert_true(stack_push(s, 0), __LINE__);
  assert_int(stack_len(s), 1, __LINE__);
  assert_int(stack_peek(s), 0, __LINE__);
  assert_true(stack_push(s, 1), __LINE__);
  assert_int(stack_len(s), 2, __LINE__);
  assert_int(stack_peek(s), 1, __LINE__);
  assert_int(stack_pop(s), 1, __LINE__);
  assert_int(stack_pop(s), 0, __LINE__);
  assert_int(stack_pop(s), STACK_EMPTY, __LINE__);

  printf("All tests passed!\n");

  return 0;
}
