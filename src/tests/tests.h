#ifndef TESTS_H
#define TESTS_H

#include <stddef.h>

void test_linked_list();
void test_queue();
void test_stack();

void test_path_finding(size_t maze_rows, size_t maze_columns, char **maze);

void test_linear_search();
void test_binary_search();

void test_bubble_sort();
void test_quick_sort();

#endif // TESTS_H
