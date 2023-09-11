#include "tests.h"
#include <stdio.h>

int main() {
  printf("Data Structures ========================================\n");
  test_linked_list();
  test_queue();
  test_stack();

  printf("\nAlgorithms ============================================\n");
  test_binary_search();
  test_linear_search();
  test_quick_sort();
  test_bubble_sort();

  char *maze[] = {
      "XXXXXXXXXX X", "X        X X", "X        X X",
      "X XXXXXXXX X", "X          X", "X XXXXXXXXXX",
  };
  test_path_finding(6, 12, maze);

  return 0;
}
