#ifndef SEARCH_TEST_H
#define SEARCH_TEST_H

#include "../algo/search.h"
#include "test_utils.h"

void test_search() {
  printf("Search Algorithms in C\n");

  int values[] = {1, 3, 5, 7, 9, 10, 22, 45};

  // Linear Search with Arrays
  ASSERT_TRUE(linear_search(len(values), values, 3))
  ASSERT_FALSE(linear_search(len(values), values, 2))

  // Linear Search with Arrays
  ASSERT_TRUE(binary_search(len(values), values, 5))
  ASSERT_FALSE(binary_search(len(values), values, 11))

  printf("All tests passed!\n");
}

#endif // SEARCH_TEST_H
