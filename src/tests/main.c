#include "linked_list_test.h"
#include "queue_test.h"
#include "search_test.h"
#include "sort_test.h"
#include "stack_test.h"
#include <stdio.h>

int main() {
  printf("Data Structures ========================================\n");
  test_linked_list();
  test_queue();
  test_stack();
  printf("\nAlgorithms ==============================================\n");
  test_search();
  test_sort();

  return 0;
}
