#include "../algo/path_finding.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

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
