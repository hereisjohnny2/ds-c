#ifndef SORT_TEST_H
#define SORT_TEST_H

#include "../algo/array_utils.h"
#include "../algo/sort.h"
#include "test_utils.h"
#include <stdlib.h>
#include <string.h>

void test_sort() {
  printf("Sort Algorithms in C\n");

  // Bubble Sort with Arrays
  int arr[] = {1, 3, 7, 4, 2};
  int arr_expected[] = {1, 2, 3, 4, 7};
  bubble_sort(ARR_LEN(arr), arr);
  ASSERT_ARR_EQ(ARR_LEN(arr), arr_expected, arr)

  // Quick Sort with Arrays
  int arr2[] = {9, 3, 7, 4, 69, 420, 42};
  int arr_expected2[] = {3, 4, 7, 9, 42, 69, 420};
  quick_sort(ARR_LEN(arr2), arr2);
  ASSERT_ARR_EQ(ARR_LEN(arr2), arr_expected2, arr2)

  printf("All tests passed!\n");
}

#endif // SORT_TEST_H
