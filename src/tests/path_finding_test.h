#include "../algo/path_finding.h"
#include <stdio.h>
#include <stdlib.h>

void test_path_finding(char **maze) {
  printf("Maze Solver in C\n");
  Point start = {
      .x = 10,
      .y = 0,
  };

  Point end = {
      .x = 1,
      .y = 5,
  };

  bool **seen = (bool **)malloc(6 * sizeof(bool *));
  for (int i = 0; i < 6; i++) {
    seen[i] = (bool *)malloc(12 * sizeof(bool));
  }

  int **path = (int **)malloc(6 * sizeof(int *));
  for (int i = 0; i < 6; i++) {
    path[i] = (int *)malloc(12 * sizeof(int));
  }

  printf("Before: \n");
  print_maze(6, 12, maze, path);
  maze_solver(6, 12, maze, 'X', seen, start, end, path);
  printf("After: \n");
  print_maze(6, 12, maze, path);
}
