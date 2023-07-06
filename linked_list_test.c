#include "linked_list.h"
#include "test_utils.h"
#include <stdio.h>

int main(void) {
  List *l = list_new();

  ASSERT_EQ(list_first(l), LIST_EMPTY);
  ASSERT_EQ(list_last(l), LIST_EMPTY);

  ASSERT_TRUE(list_push(l, 2));
  ASSERT_EQ(list_len(l), 1);
  ASSERT_EQ(list_first(l), list_last(l));

  ASSERT_TRUE(list_push(l, 5));
  ASSERT_EQ(list_len(l), 2);

  ASSERT_TRUE(list_push(l, 200));
  ASSERT_EQ(list_len(l), 3);

  ASSERT_EQ(list_get(l, 0), 2);
  ASSERT_EQ(list_get(l, 1), 5);
  ASSERT_EQ(list_get(l, 2), 200);

  ASSERT_TRUE(insert_at(l, 1, 10));
  ASSERT_EQ(list_len(l), 4);
  ASSERT_EQ(list_get(l, 1), 5);

  ASSERT_FALSE(insert_at(l, 1000, 10));

  // 2, 10, 5, 200
  ASSERT_EQ(list_pop(l), 200);
  ASSERT_EQ(list_len(l), 3);
  // 2, 10, 5
  // ASSERT_EQ(list_shift(l), 2);
  // ASSERT_EQ(list_len(l), 2);
  // 10, 5
  ASSERT_EQ(list_pop(l), 5);
  // ASSERT_EQ(list_len(l), 0);
  // ASSERT_EQ(list_pop(l), 10);

  printf("All tests passed!\n");

  return 0;
}
