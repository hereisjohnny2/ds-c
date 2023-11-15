#include "tests.h"
#include <stdio.h>

int main() {
  printf("Data Structures ========================================\n");
  test_linked_list();
  test_queue();
  test_stack();
  test_tree();

  printf("\nAlgorithms ============================================\n");
  test_binary_search();
  test_linear_search();
  test_quick_sort();
  test_bubble_sort();
  test_path_finding();

  return 0;
}
