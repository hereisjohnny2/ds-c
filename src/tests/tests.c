#include "tests.h"

#include "../algo/path_finding.h"
#include "../algo/search.h"
#include "../algo/sort.h"
#include "../ds/linked_list.h"
#include "../ds/queue.h"
#include "../ds/stack.h"
#include "../ds/tree.h"

#include "../algo/array_utils.h"
#include "test_utils.h"

#include <stdio.h>
#include <stdlib.h>

void test_linked_list() {
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

void test_queue() {
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

void test_path_finding(size_t maze_rows, size_t maze_columns, char **maze) {
  printf("Maze Solver in C\n");
  Point start = {
      .x = 10,
      .y = 0,
  };

  Point end = {
      .x = 1,
      .y = 5,
  };

  printf("Before: \n");
  print_maze(maze_rows, maze_columns, maze, NULL);
  bool **path = maze_solver(maze_rows, maze_columns, maze, 'X', start, end);
  printf("After: \n");
  print_maze(maze_rows, maze_columns, maze, path);

  for (int i = 0; i < maze_rows; i++) {
    free(path[i]);
  }
  free(path);
}

void test_linear_search() {
  printf("Linear Search in C");

  int values[] = {1, 3, 5, 7, 9, 10, 22, 45};

  // Linear Search with Arrays
  ASSERT_TRUE(linear_search(ARR_LEN(values), values, 3))
  ASSERT_FALSE(linear_search(ARR_LEN(values), values, 2))

  printf(" (OK)\n");
}

void test_binary_search() {
  printf("Binary Search in C");

  int values[] = {1, 3, 5, 7, 9, 10, 22, 45};

  // Linear Search with Arrays
  ASSERT_TRUE(binary_search(ARR_LEN(values), values, 5))
  ASSERT_FALSE(binary_search(ARR_LEN(values), values, 11))

  printf(" (OK)\n");
}

void test_bubble_sort() {
  printf("Bubble Sort Algorithms in C");

  // Bubble Sort with Arrays
  int arr[] = {1, 3, 7, 4, 2};
  int arr_expected[] = {1, 2, 3, 4, 7};
  bubble_sort(ARR_LEN(arr), arr);
  ASSERT_ARR_EQ(ARR_LEN(arr), arr_expected, arr)

  printf(" (OK)\n");
}

void test_quick_sort() {
  printf("Quick Sort Algorithms in C");

  int arr[] = {9, 3, 7, 4, 69, 420, 42};
  int arr_expected[] = {3, 4, 7, 9, 42, 69, 420};
  quick_sort(ARR_LEN(arr), arr);
  ASSERT_ARR_EQ(ARR_LEN(arr), arr_expected, arr)

  printf(" (OK)\n");
}

void test_stack() {
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

bool test_tree_order_case(TreeNode *node, TREE_ORDER order, int *arr) {
  List *path = list_new();
  List *expected = list_from_array(7, arr);
  tree_order(node, path, order);
  return list_equal(expected, path);
}

void test_tree_order(TreeNode *head) {
  int arr_pre[] = {7, 10, 20, 55, 3, 9, 12};
  ASSERT_TRUE(test_tree_order_case(head, TREE_PRE, arr_pre));
  int arr_in[] = {20, 10, 55, 7, 9, 3, 12};
  ASSERT_TRUE(test_tree_order_case(head, TREE_IN, arr_in));
  int arr_pos[] = {20, 55, 10, 9, 12, 3, 7};
  ASSERT_TRUE(test_tree_order_case(head, TREE_POS, arr_pos));
}

void test_tree_compare() {
  TreeNode *headA = tree_node_new(7);
  TreeNode *nA1 = tree_node_new(10);
  TreeNode *nA2 = tree_node_new(3);
  TreeNode *nA3 = tree_node_new(20);
  TreeNode *nA5 = tree_node_new(9);

  tree_set_node(headA, nA1, 0);
  tree_set_node(headA, nA2, 1);
  tree_set_node(nA1, nA3, 0);
  tree_set_node(nA2, nA5, 1);

  TreeNode *headB = tree_node_new(7);
  TreeNode *nB1 = tree_node_new(10);
  TreeNode *nB2 = tree_node_new(3);
  TreeNode *nB3 = tree_node_new(16);
  TreeNode *nB5 = tree_node_new(7);

  tree_set_node(headB, nB1, 0);
  tree_set_node(headB, nB2, 1);
  tree_set_node(nB1, nB3, 0);
  tree_set_node(nB2, nB5, 1);

  ASSERT_TRUE(tree_compare(headA, headA));
  ASSERT_FALSE(tree_compare(headA, headB));
}

void test_tree() {
  printf("Trees in C");

  TreeNode *head = tree_node_new(7);
  TreeNode *n1 = tree_node_new(10);
  TreeNode *n2 = tree_node_new(3);
  TreeNode *n3 = tree_node_new(20);
  TreeNode *n4 = tree_node_new(55);
  TreeNode *n5 = tree_node_new(9);
  TreeNode *n6 = tree_node_new(12);

  ASSERT_TRUE(tree_set_node(head, n1, 0));
  ASSERT_TRUE(tree_set_node(head, n2, 1));

  ASSERT_TRUE(tree_set_node(n1, n3, 0));
  ASSERT_TRUE(tree_set_node(n1, n4, 1));

  ASSERT_TRUE(tree_set_node(n2, n5, 0));
  ASSERT_TRUE(tree_set_node(n2, n6, 1));

  test_tree_order(head);

  ASSERT_TRUE(breadth_first_search(head, 12));
  ASSERT_FALSE(breadth_first_search(head, 100));
  ASSERT_FALSE(breadth_first_search(NULL, 100));

  printf(" (OK)\n");
}
