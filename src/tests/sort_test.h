#ifndef SORT_TEST_H
#define SORT_TEST_H

#include "../algo/array_utils.h"
#include "../algo/sort.h"
#include "test_utils.h"
#include <stdlib.h>
#include <string.h>


void test_sort() {
  printf("Sort Algorithms in C\n");

  int arr[] = {1, 3, 7, 4, 2};
  int arr_expected[] = {1, 2, 3, 4, 7};

  // Bubble Sort with Arrays
  bubble_sort(ARR_LEN(arr), arr);
  ASSERT_ARR_EQ(ARR_LEN(arr), arr_expected, arr)


  printf("All tests passed!\n");
}

#endif // SORT_TEST_H
