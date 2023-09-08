#include "linked_list_test.h"
#include "path_finding_test.h"
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
  char *maze[] = {
      "XXXXXXXXXX X", "X        X X", "X        X X",
      "X XXXXXXXX X", "X          X", "X XXXXXXXXXX",
  };
  test_path_finding(6, 12, maze);

  return 0;
}
