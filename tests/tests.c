#include "tests.h"

#include "algo/path_finding.h"
#include "algo/search.h"
#include "algo/sort.h"
#include "ds/linked_list.h"
#include "ds/queue.h"
#include "ds/stack.h"
#include "ds/tree.h"

#include "algo/array_utils.h"
#include "test_utils.h"

#include <stdio.h>
#include <stdlib.h>

void test_linked_list()
{
  printf("Double Linked List in C");

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
  ASSERT_EQ(list_get(l, 1), 10);

  ASSERT_FALSE(insert_at(l, 1000, 10));

  ASSERT_EQ(list_pop(l), 200);
  ASSERT_EQ(list_len(l), 3);
  ASSERT_EQ(list_shift(l), 2);
  ASSERT_EQ(list_pop(l), 5);
  ASSERT_EQ(list_len(l), 1);
  ASSERT_EQ(list_pop(l), 10);
  ASSERT_EQ(list_len(l), 0);

  ASSERT_EQ(list_pop(l), LIST_EMPTY);
  ASSERT_EQ(list_shift(l), LIST_EMPTY);

  list_free(l);

  printf(" (Ok)\n");
}

void test_queue()
{
  printf("Queue in C");

  Queue *q = queue_new();

  ASSERT_EQ(queue_head(q), QUEUE_EMPTY);
  ASSERT_EQ(queue_tail(q), QUEUE_EMPTY);

  ASSERT_TRUE(enqueue(q, 0));
  ASSERT_EQ(queue_len(q), 1);
  ASSERT_EQ(queue_head(q), 0);
  ASSERT_EQ(queue_tail(q), 0);

  ASSERT_TRUE(enqueue(q, 1));
  ASSERT_EQ(queue_len(q), 2);
  ASSERT_EQ(queue_head(q), 0);
  ASSERT_EQ(queue_tail(q), 1);

  ASSERT_TRUE(enqueue(q, 2));
  ASSERT_EQ(queue_len(q), 3);
  ASSERT_EQ(queue_head(q), 0);
  ASSERT_EQ(queue_tail(q), 2);

  ASSERT_EQ(dequeue(q), 0);
  ASSERT_EQ(dequeue(q), 1);
  ASSERT_EQ(dequeue(q), 2);
  ASSERT_EQ(dequeue(q), QUEUE_EMPTY);

  queue_free(q);

  printf(" (OK)\n");
}

void test_path_finding()
{
  printf("Maze Solver in C");

  int maze_rows = 6, maze_columns = 12;

  char *maze[] = {
      "XXXXXXXXXX X",
      "X        X X",
      "X        X X",
      "X XXXXXXXX X",
      "X          X",
      "X XXXXXXXXXX",
  };

  char *expected_maze[] = {
      "XXXXXXXXXX1X",
      "X        X1X",
      "X        X1X",
      "X XXXXXXXX1X",
      "X1111111111X",
      "X1XXXXXXXXXX",
  };

  Point start = {
      .x = 10,
      .y = 0,
  };

  Point end = {
      .x = 1,
      .y = 5,
  };

  bool **path = maze_solver(maze_rows, maze_columns, maze, 'X', start, end);
  ASSERT_MAT_EQ(maze_rows, maze_columns, maze, maze);

  for (int i = 0; i < maze_rows; i++)
  {
    free(path[i]);
  }
  free(path);

  printf(" (OK)\n");
}

void test_linear_search()
{
  printf("Linear Search in C");

  int values[] = {1, 3, 5, 7, 9, 10, 22, 45};

  // Linear Search with Arrays
  ASSERT_TRUE(linear_search(ARR_LEN(values), values, 3))
  ASSERT_FALSE(linear_search(ARR_LEN(values), values, 2))

  printf(" (OK)\n");
}

void test_binary_search()
{
  printf("Binary Search in C");

  int values[] = {1, 3, 5, 7, 9, 10, 22, 45};

  // Linear Search with Arrays
  ASSERT_TRUE(binary_search(ARR_LEN(values), values, 5))
  ASSERT_FALSE(binary_search(ARR_LEN(values), values, 11))

  printf(" (OK)\n");
}

void test_bubble_sort()
{
  printf("Bubble Sort Algorithms in C");

  // Bubble Sort with Arrays
  int arr[] = {1, 3, 7, 4, 2};
  int arr_expected[] = {1, 2, 3, 4, 7};
  bubble_sort(ARR_LEN(arr), arr);
  ASSERT_ARR_EQ(ARR_LEN(arr), arr_expected, arr)

  printf(" (OK)\n");
}

void test_quick_sort()
{
  printf("Quick Sort Algorithms in C");

  int arr[] = {9, 3, 7, 4, 69, 420, 42};
  int arr_expected[] = {3, 4, 7, 9, 42, 69, 420};
  quick_sort(ARR_LEN(arr), arr);
  ASSERT_ARR_EQ(ARR_LEN(arr), arr_expected, arr)

  printf(" (OK)\n");
}

void test_stack()
{
  printf("Stack in C");

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

  printf(" (OK)\n");
}

bool test_tree_order_case(Tree *tree, TREE_ORDER order, int *arr)
{
  List *path = list_new();
  List *expected = list_from_array(7, arr);
  depth_first_transversal(tree, path, order);
  return list_equal(expected, path);
}

void test_tree_order(Tree *tree)
{
  int arr_pre[] = {7, 3, 10, 9, 20, 12, 55};
  ASSERT_TRUE(test_tree_order_case(tree, TREE_PRE, arr_pre));
  int arr_in[] = {3, 7, 9, 10, 12, 20, 55};
  ASSERT_TRUE(test_tree_order_case(tree, TREE_IN, arr_in));
  int arr_pos[] = {3, 9, 12, 55, 20, 10, 7};
  ASSERT_TRUE(test_tree_order_case(tree, TREE_POS, arr_pos));
}

void test_tree_compare()
{
  Tree *treeA = tree_new();
  bst_insert(treeA, 7);
  bst_insert(treeA, 10);
  bst_insert(treeA, 3);
  bst_insert(treeA, 20);
  bst_insert(treeA, 9);

  Tree *treeB = tree_new();
  bst_insert(treeB, 7);
  bst_insert(treeB, 10);
  bst_insert(treeB, 3);
  bst_insert(treeB, 16);
  bst_insert(treeB, 7);

  ASSERT_TRUE(tree_compare(treeA, treeA));
  ASSERT_FALSE(tree_compare(treeA, treeB));
}

void test_tree()
{
  printf("Trees in C");

  Tree *tree = tree_new();
  bst_insert(tree, 7);
  bst_insert(tree, 10);
  bst_insert(tree, 3);
  bst_insert(tree, 20);
  bst_insert(tree, 55);
  bst_insert(tree, 9);
  bst_insert(tree, 12);

  test_tree_order(tree);

  ASSERT_TRUE(depth_first_search(tree, 12));
  ASSERT_FALSE(depth_first_search(tree, 100));
  ASSERT_FALSE(depth_first_search(NULL, 100));

  ASSERT_TRUE(breadth_first_search(tree, 12));
  ASSERT_FALSE(breadth_first_search(tree, 100));
  ASSERT_FALSE(breadth_first_search(NULL, 100));

  ASSERT_TRUE(bst_find(tree, 12));
  ASSERT_FALSE(bst_find(tree, 100));
  ASSERT_FALSE(bst_find(NULL, 100));

  test_tree_compare();

  printf(" (OK)\n");
}
